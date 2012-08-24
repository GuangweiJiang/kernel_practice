//==========================================
// Filename:
//      tasks.c
//
// Description:
//      任务控制相关的操作，如任务创建(task_create).
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


//--------------------------------------------------------------------------------------
// Include Files
//--------------------------------------------------------------------------------------
#include "tasks.h"



//-----------------------------------------------------------------
// MACROS
//-----------------------------------------------------------------



//-----------------------------------------------------------------
// DEFINES
//-----------------------------------------------------------------
	



//-----------------------------------------------------------------
// CONSTANTS AND VARIABLES
//-----------------------------------------------------------------



//-----------------------------------------------------------------
// INTERNAL FUNCTIONS
//-----------------------------------------------------------------



//-----------------------------------------------------------------
// EXTERNAL FUNCTIONS
//-----------------------------------------------------------------



//-----------------------------------------------------------------
// IMPLEMENTATION
//-----------------------------------------------------------------




//----------------------------------------------------------------------------
// Function:
//      void task_create(void(*Task)(void), unsigned long *p_Stack, unsigned long *Task_STK_PTR)
//
// Description:
//		建立Task的运行上下文环境(context)
//
// Parameters:
//      void(*Task)(void):			Task地址
//		unsigned long *p_Stack:		Task堆栈指针
//		unsigned long *Task_STK_PTR:保存Task栈顶的地址 
//
// Return Value:
//      n/a
//
void task_create(void(*Task)(void), unsigned long *p_Stack, unsigned long *Task_STK_PTR)
{	
	*(p_Stack)   = (unsigned long)Task;			/* 将任务的地址压入堆栈 */	
	*(--p_Stack) = (unsigned long)13;			/* lr  */
	*(--p_Stack) = (unsigned long)12;			/* r12 */
	*(--p_Stack) = (unsigned long)11;			/* r11 */
	*(--p_Stack) = (unsigned long)10;			/* r10 */
	*(--p_Stack) = (unsigned long)9;			/* r9  */
   	*(--p_Stack) = (unsigned long)8;			/* r8  */
   	*(--p_Stack) = (unsigned long)7;			/* r7  */
   	*(--p_Stack) = (unsigned long)6;			/* r6  */
   	*(--p_Stack) = (unsigned long)5;			/* r5  */
   	*(--p_Stack) = (unsigned long)4; 			/* r4  */
   	*(--p_Stack) = (unsigned long)3;			/* r3  */
   	*(--p_Stack) = (unsigned long)2;			/* r2  */
   	*(--p_Stack) = (unsigned long)1;			/* r1  */
	*(--p_Stack) = (unsigned long)0;			/* r0  */
	*(--p_Stack) = (unsigned long)(SVCMODE);	/* CPSR */
	*Task_STK_PTR = (unsigned long)p_Stack;		/* 保存Task栈顶地址*/
}
