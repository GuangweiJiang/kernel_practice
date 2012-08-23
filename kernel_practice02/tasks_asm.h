//==========================================
// Filename:
//      tasks_asm.h
//
// Description:
//		汇编代码的头文档，和tasks.h定义相同。
//      定义task有关的变量/函数等，如stack起始地址/大小等。。。
//
// Author/Created Date:
//      Guangwei Jiang, 2012-08-21
//
// Modification History:
// 
//
//
// Note:
//    
//==========================================
//
// 
//


//#ifndef __KENEL_PRACTICE_TASKS_ASM_H
//#define __KENEL_PRACTICE_TASKS_ASM_H

//--------------------------------------------------------------------------------------
// Include Files
//--------------------------------------------------------------------------------------



//-----------------------------------------------------------------
// MACROS
//-----------------------------------------------------------------




//-----------------------------------------------------------------
// DEFINES
//-----------------------------------------------------------------
// 定义“任务堆栈指针”的存放位置
#define STK_PTR_SIZE			0x4		// 4 bytes (store the pointer of tasks' stack)
#define	TASK_MAIN_STK_PTR		((unsigned long *)0x00100000)
#define TASK01_STK_PTR			((unsigned long *)(TASK_MAIN_STK_PTR+STK_PTR_SIZE))
#define TASK02_STK_PTR			((unsigned long *)(TASK01_STK_PTR+STK_PTR_SIZE))
#define TASK03_STK_PTR			((unsigned long *)(TASK02_STK_PTR+STK_PTR_SIZE))
#define TASK04_STK_PTR			((unsigned long *)(TASK03_STK_PTR+STK_PTR_SIZE))
#define TASK05_STK_PTR			((unsigned long *)(TASK04_STK_PTR+STK_PTR_SIZE))
#define TASK06_STK_PTR			((unsigned long *)(TASK05_STK_PTR+STK_PTR_SIZE))
#define TASK07_STK_PTR			((unsigned long *)(TASK06_STK_PTR+STK_PTR_SIZE))
#define TASK08_STK_PTR			((unsigned long *)(TASK07_STK_PTR+STK_PTR_SIZE))
#define TASK09_STK_PTR			((unsigned long *)(TASK08_STK_PTR+STK_PTR_SIZE))
#define TASK10_STK_PTR			((unsigned long *)(TASK09_STK_PTR+STK_PTR_SIZE))
#define TASK11_STK_PTR			((unsigned long *)(TASK10_STK_PTR+STK_PTR_SIZE))
#define TASK12_STK_PTR			((unsigned long *)(TASK111_STK_PTR+STK_PTR_SIZE))

// 定义任务堆栈的基址，注意此程序的堆栈是向下增长
#define TASK_STACK_SIZE			0x80000	// the stack size
#define TASK_MAIN_STK_BASE		((unsigned long *)0x00200000)	// The base address of stack
#define TASK01_STK_BASE			((unsigned long *)(TASK_MAIN_STK_BASE+TASK_STACK_SIZE))
#define TASK02_STK_BASE			((unsigned long *)(TASK01_STK_BASE+TASK_STACK_SIZE))
#define TASK03_STK_BASE			((unsigned long *)(TASK02_STK_BASE+TASK_STACK_SIZE))
#define TASK04_STK_BASE			((unsigned long *)(TASK03_STK_BASE+TASK_STACK_SIZE))
#define TASK05_STK_BASE			((unsigned long *)(TASK04_STK_BASE+TASK_STACK_SIZE))
#define TASK06_STK_BASE			((unsigned long *)(TASK05_STK_BASE+TASK_STACK_SIZE))
#define TASK07_STK_BASE			((unsigned long *)(TASK06_STK_BASE+TASK_STACK_SIZE))
#define TASK08_STK_BASE			((unsigned long *)(TASK07_STK_BASE+TASK_STACK_SIZE))
#define TASK09_STK_BASE			((unsigned long *)(TASK08_STK_BASE+TASK_STACK_SIZE))
#define TASK10_STK_BASE			((unsigned long *)(TASK09_STK_BASE+TASK_STACK_SIZE))
#define TASK11_STK_BASE			((unsigned long *)(TASK10_STK_BASE+TASK_STACK_SIZE))
#define TASK12_STK_BASE			((unsigned long *)(TASK11_STK_BASE+TASK_STACK_SIZE))


//-----------------------------------------------------------------
// CONSTANTS AND VARIABLES
//-----------------------------------------------------------------



//-----------------------------------------------------------------
// INTERNAL FUNCTIONS
//-----------------------------------------------------------------



//-----------------------------------------------------------------
// EXTERNAL FUNCTIONS
//-----------------------------------------------------------------


//#endif
