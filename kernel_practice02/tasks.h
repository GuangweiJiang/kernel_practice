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
#define SVCMODE         			0x13

// 定义“任务堆栈指针”的存放位置
#define STK_PTR_SIZE				0x4		// 4 bytes (store the pointer of tasks' stack)
#define	TASK_MAIN_STK_PTR			0x00100000
#define TASK01_STK_PTR				(TASK_MAIN_STK_PTR + STK_PTR_SIZE)
#define TASK02_STK_PTR				(TASK01_STK_PTR + STK_PTR_SIZE)
#define TASK03_STK_PTR				(TASK02_STK_PTR + STK_PTR_SIZE)
#define TASK04_STK_PTR				(TASK03_STK_PTR + STK_PTR_SIZE)
#define TASK05_STK_PTR				(TASK04_STK_PTR + STK_PTR_SIZE)
#define TASK06_STK_PTR				(TASK05_STK_PTR + STK_PTR_SIZE)
#define TASK07_STK_PTR				(TASK06_STK_PTR + STK_PTR_SIZE)
#define TASK08_STK_PTR				(TASK07_STK_PTR + STK_PTR_SIZE)
#define TASK09_STK_PTR				(TASK08_STK_PTR + STK_PTR_SIZE)
#define TASK10_STK_PTR				(TASK09_STK_PTR + STK_PTR_SIZE)
#define TASK11_STK_PTR				(TASK10_STK_PTR + STK_PTR_SIZE)
#define TASK12_STK_PTR				(TASK11_STK_PTR + STK_PTR_SIZE)

// 定义任务堆栈的基址，注意此程序的堆栈是向下增长
#define TASK_STACK_SIZE				0x00080000	// the stack size
#define TASK_MAIN_STK_BASE			0x00200000	// The base address of stack
#define TASK01_STK_BASE				(TASK_MAIN_STK_BASE + TASK_STACK_SIZE)
#define TASK02_STK_BASE				(TASK01_STK_BASE + TASK_STACK_SIZE)
#define TASK03_STK_BASE				(TASK02_STK_BASE + TASK_STACK_SIZE)
#define TASK04_STK_BASE				(TASK03_STK_BASE + TASK_STACK_SIZE)
#define TASK05_STK_BASE				(TASK04_STK_BASE + TASK_STACK_SIZE)
#define TASK06_STK_BASE				(TASK05_STK_BASE + TASK_STACK_SIZE)
#define TASK07_STK_BASE				(TASK06_STK_BASE + TASK_STACK_SIZE)
#define TASK08_STK_BASE				(TASK07_STK_BASE + TASK_STACK_SIZE)
#define TASK09_STK_BASE				(TASK08_STK_BASE + TASK_STACK_SIZE)
#define TASK10_STK_BASE				(TASK09_STK_BASE + TASK_STACK_SIZE)
#define TASK11_STK_BASE				(TASK10_STK_BASE + TASK_STACK_SIZE)
#define TASK12_STK_BASE				(TASK11_STK_BASE + TASK_STACK_SIZE)


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
