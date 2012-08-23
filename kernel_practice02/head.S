@**************************************************************
@ File: 	head.S
@ Function: 初始化，包括设置SVC模式下的堆栈，启动第一个任务main.
@ Author: 	Guangwei_Jiang
@ Date:		2012-08-17
@**************************************************************

@ 定义“任务堆栈指针”的存放位置
.equ STK_PTR_SIZE,			0x4		@ 4 bytes (store the pointer of tasks' stack)
.equ TASK_MAIN_STK_PTR,		0x0010FFC
.equ TASK01_STK_PTR,		0x00100FF8
.equ TASK02_STK_PTR,		0x00100FF4

.equ TASK_MAIN_STK_BASE,	0x00200000

.global start
.global	task_sched_main_to_01
.global task_sched_01_to_02
.global task_sched_02_to_01

	
@******************************************************************************
@ CPU reset后运行的第一段代码。
@ 初始化，包括设置SVC模式下的堆栈，启动第一个任务Task1。
@******************************************************************************
	.align
start:
	ldr	sp, =TASK_MAIN_STK_BASE	
	bl 	main				@ 启动第一个任务main
halt_loop:
	b	halt_loop
	
@******************************************************************************
@ 从main tak切换到task1
@******************************************************************************
task_sched_main_to_01:
	stmfd sp!,{lr}              @ PC 入栈
	stmfd sp!,{r0-r12,lr}		@ r0-r12，lr入栈
			
	mrs r4,cpsr
	stmfd sp!,{r4}				@ cpsr入栈

	ldr r5,=TASK_MAIN_STK_PTR	@ 取出存放main task的Stack Pointer的地址
	str sp,[r5]                 @ 保存main task的Stack Pointer

	ldr r6, =TASK01_STK_PTR		@ 取出存放Task1的Stack Pointer的地址
	ldr sp, [r6]				@ 取出Task1的堆顶指针到SP         		
	b   POP_ALL					@ 根据设定的栈结构顺序出栈

@******************************************************************************
@ 从Task1切换到Task2
@******************************************************************************
task_sched_01_to_02:
	stmfd sp!,{lr}              @ PC 入栈
	stmfd sp!,{r0-r12,lr}		@ r0-r12，lr入栈
			
	mrs r4,cpsr
	stmfd sp!,{r4}				@ cpsr入栈

	ldr r5,=TASK01_STK_PTR		@ 取出存放Task1的Stack Pointer的地址
	str sp,[r5]                 @ 保存Task1的Stack Pointer

	ldr r6, =TASK02_STK_PTR		@ 取出存放Task2的Stack Pointer的地址
	ldr sp, [r6]				@ 取出Task2的堆顶指针到SP         		
	b   POP_ALL					@ 根据设定的栈结构顺序出栈


@******************************************************************************
@ 从Task2切换到Task1
@******************************************************************************
task_sched_02_to_01:
	stmfd sp!,{lr}              @ PC 入栈
	stmfd sp!,{r0-r12,lr}		@ r0-r12，lr入栈
			
	mrs r4,cpsr
	stmfd sp!,{r4}				@ cpsr入栈

	ldr r5,=TASK02_STK_PTR		@ 取出存放Task2的Stack Pointer的地址
	str sp,[r5]                 @ 保存Task2的Stack Pointer
	
	ldr r6,=TASK01_STK_PTR		@ 取出存放Task1的Stack Pointer的地址
	ldr sp,[r6]                 @ 取出Task2的堆顶指针到SP   		
	b   POP_ALL					@ 根据设定的栈结构顺序出栈
				
@******************************************************************************			
@ 根据设定的栈结构顺序出栈
@******************************************************************************
POP_ALL:			
	ldmfd sp!,{r4}              @ psr出栈
	msr CPSR_cxsf,r4	
	ldmfd sp!,{r0-r12,lr,pc}    @ r0-r12,lr,pc出栈

