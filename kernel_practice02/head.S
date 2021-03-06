@**************************************************************
@ File: 	head.S
@ Function: 初始化，包括设置SVC模式下的堆栈，启动第一个任务main.
@           并且进行不同任务间的切换。
@ Author: 	Guangwei_Jiang
@ Date:		2012-08-17
@**************************************************************

@ 定义“任务堆栈指针”的存放位置
.equ STK_PTR_SIZE,			0x4		@ 4 bytes (store the pointer of tasks' stack)
.equ TASK_MAIN_STK_PTR,		0x00100000
.equ TASK01_STK_PTR,		TASK_MAIN_STK_PTR + STK_PTR_SIZE
.equ TASK02_STK_PTR,		TASK01_STK_PTR + STK_PTR_SIZE
.equ TASK03_STK_PTR,		TASK02_STK_PTR + STK_PTR_SIZE
.equ TASK04_STK_PTR,		TASK03_STK_PTR + STK_PTR_SIZE
.equ TASK05_STK_PTR,		TASK04_STK_PTR + STK_PTR_SIZE
.equ TASK06_STK_PTR,		TASK05_STK_PTR + STK_PTR_SIZE
.equ TASK07_STK_PTR,		TASK06_STK_PTR + STK_PTR_SIZE
.equ TASK08_STK_PTR,		TASK07_STK_PTR + STK_PTR_SIZE
.equ TASK09_STK_PTR,		TASK08_STK_PTR + STK_PTR_SIZE
.equ TASK10_STK_PTR,		TASK09_STK_PTR + STK_PTR_SIZE
.equ TASK11_STK_PTR,		TASK10_STK_PTR + STK_PTR_SIZE
.equ TASK12_STK_PTR,		TASK11_STK_PTR + STK_PTR_SIZE

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
@ 从main task切换到task1
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

