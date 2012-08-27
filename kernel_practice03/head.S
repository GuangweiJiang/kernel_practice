@**************************************************************
@ File: 	head.S
@ Function: 初始化，包括设置SVC模式下的堆栈，启动第一个任务main.
@           并且进行不同任务间的切换。
@ Author: 	Guangwei_Jiang
@ Date:		2012-08-27
@**************************************************************

#include "tasks_asm.h"

.global start
.global	task_sched

	
@******************************************************************************
@ CPU reset后运行的第一段代码。
@ 初始化，包括设置SVC模式下的堆栈，启动第一个任务Task1。
@******************************************************************************
	.align
start:

	@ 初始化"下一个任务"的堆栈指针，该指针指向任务main;
    ldr	r0, =TASK_MAIN_STK_PTR
    ldr r1, =TASK_NEXT_STK_PTR
    str	r0, [r1]			@ mem[r1] =r0

	ldr	sp, =TASK_MAIN_STK_BASE	
	bl 	main				@ 启动第一个任务main
halt_loop:
	b	halt_loop
	
@******************************************************************************			
@ 任务切换。这里使用最简单的"轮转法调度"！
@******************************************************************************
task_sched:
	@ 将“当前任务”寄存器值压栈。
	stmfd sp!,{lr}              @ PC 入栈
	stmfd sp!,{r0-r12,lr}		@ r0-r12，lr入栈			
	mrs r4,cpsr
	stmfd sp!,{r4}				@ cpsr入栈

	@ 计算存放“当前任务”堆栈指针的地址。
	@ 因为采用最简单的“轮转法调度”，所以，“当前任务”是上一次调度之前的“下一个任务”！
	ldr r0, =TASK_CUR_STK_PTR	
	ldr r1, =TASK_NEXT_STK_PTR
	ldr r1, [r1]				 
	str	r1, [r0]	
		
	@ 保存“当前任务”的栈顶指针。
	ldr r5,=TASK_CUR_STK_PTR	@ 取出存放“当前任务”的堆栈指针的地址
	ldr r5, [r5]
	str sp,[r5]                 @ 保存“当前任务”的堆栈指针			
	
	@ 计算“下一个任务”堆栈指针。
	@ “下一个任务”的堆栈指针, 保存在“当前任务”堆栈指针的地址的后面；
	@ 如果“下一个任务”超出了界限，则指向第一个任务。
	ldr r0, =TASK_NEXT_STK_PTR
	ldr r1, =TASK_CUR_STK_PTR
	ldr r1, [r1]
	add r1, r1, #4				@"下一个任务"保存地址 = “当前任务”保存地址 + 4			
	str r1, [r0]	
	ldr r2, =TASK_MIN_STK_PTR
	ldr r3, =TASK_MAX_STK_PTR
	cmp r3, r1
	strmi r2, [r0]				@ 如果TASK_NEXT_STK_PTR越界，
								@ 则将TASK_MIN_STK_PTR的值赋给TASK_NEXT_STK_PTR.			

	@ 取出“下一个任务”的栈顶指针，并将寄存器依次出栈。
	ldr r6, =TASK_NEXT_STK_PTR	@ 取出存放"下一个任务"的Stack Pointer的地址
	ldr r6, [r6]
	ldr sp, [r6]				@ 取出"下一个任务"的堆顶指针,赋给SP         		
	b   POP_ALL					@ 根据设定的栈结构顺序出栈
				
@******************************************************************************			
@ 根据设定的栈结构顺序出栈
@******************************************************************************
POP_ALL:			
	ldmfd sp!,{r4}              @ psr出栈
	msr CPSR_cxsf,r4	
	ldmfd sp!,{r0-r12,lr,pc}    @ r0-r12,lr,pc出栈
