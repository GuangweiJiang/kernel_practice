@==========================================
@ Filename:
@ 		tasks_asm.h
@
@ Description:
@		汇编语言头文件，定义task有关的变量/函数等，如stack起始地址/大小等。。。
@		定义内容和tasks.h基本相同。
@
@ Author/Created Date:
@		Guangwei Jiang, 2012-08-24
@
@ Modification History:
@ 
@
@
@ Note:
@    
@==========================================
@
@ 

#ifndef __KENEL_PRACTICE_TASKS_ASM_H
#define __KENEL_PRACTICE_TASKS_ASM_H

@-----------------------------------------------------------------
@ DEFINES
@-----------------------------------------------------------------
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

@ 定义任务堆栈的基址，注意此程序的堆栈是向下增长
.equ TASK_STACK_SIZE,		0x00080000	
.equ TASK_MAIN_STK_BASE,	0x00200000
.equ TASK01_STK_BASE,		TASK_MAIN_STK_BASE + TASK_STACK_SIZE
.equ TASK02_STK_BASE,		TASK01_STK_BASE + TASK_STACK_SIZE
.equ TASK03_STK_BASE,		TASK02_STK_BASE + TASK_STACK_SIZE
.equ TASK04_STK_BASE,		TASK03_STK_BASE + TASK_STACK_SIZE
.equ TASK05_STK_BASE,		TASK04_STK_BASE + TASK_STACK_SIZE
.equ TASK06_STK_BASE,		TASK05_STK_BASE + TASK_STACK_SIZE
.equ TASK07_STK_BASE,		TASK06_STK_BASE + TASK_STACK_SIZE
.equ TASK08_STK_BASE,		TASK07_STK_BASE + TASK_STACK_SIZE
.equ TASK09_STK_BASE,		TASK08_STK_BASE + TASK_STACK_SIZE
.equ TASK10_STK_BASE,		TASK09_STK_BASE + TASK_STACK_SIZE
.equ TASK11_STK_BASE,		TASK10_STK_BASE + TASK_STACK_SIZE
.equ TASK12_STK_BASE,		TASK11_STK_BASE + TASK_STACK_SIZE

#endif
