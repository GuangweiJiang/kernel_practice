//==========================================
// Filename:
//      tasks.h
//
// Description:
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


#ifndef __KENEL_PRACTICE_TASKS_H
#define __KENEL_PRACTICE_TASKS_H

//--------------------------------------------------------------------------------------
// Include Files
//--------------------------------------------------------------------------------------



//-----------------------------------------------------------------
// MACROS
//-----------------------------------------------------------------




//-----------------------------------------------------------------
// DEFINES
//-----------------------------------------------------------------
/*CPU mode define*/
#define SVCMODE         		0x13

// 定义“任务堆栈指针”的存放位置
#define STK_PTR_SIZE			0x4		// 4 bytes (store the pointer of tasks' stack)
#define	TASK_MAIN_STK_PTR		((unsigned long *)0x0010FFC)
#define	TASK01_STK_PTR			((unsigned long *)0x00100FF8)
#define	TASK02_STK_PTR			((unsigned long *)0x00100FF4)

// 定义任务堆栈的基址，注意此程序的堆栈是向下增长
#define TASK_STACK_SIZE			0x80000	// the stack size
#define TASK_MAIN_STK_BASE		((unsigned long *)0x00200000)	// The base address of stack
#define TASK01_STK_BASE			((unsigned long *)0x00280000)
#define TASK02_STK_BASE			((unsigned long *)0x00300000)


//-----------------------------------------------------------------
// CONSTANTS AND VARIABLES
//-----------------------------------------------------------------



//-----------------------------------------------------------------
// INTERNAL FUNCTIONS
//-----------------------------------------------------------------
void task_create(void(*Task)(void), unsigned long *p_Stack, unsigned long *Task_STK_PTR);



//-----------------------------------------------------------------
// EXTERNAL FUNCTIONS
//-----------------------------------------------------------------
void task_sched_main_to_01();
void task_sched_01_to_02();
void task_sched_02_to_01();

#endif
