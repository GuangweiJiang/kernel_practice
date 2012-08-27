//==========================================
// Filename:
//      task01.c
//
// Description:
//      仅作测试，向console打印一些信息.
//
// Author/Created Date:
//      Guangwei Jiang, 2012-08-21
//
// Modification History:
// 		Guangwei Jiang, 2012-08-27
//		呼叫“task_sched()”进行不同任务间的切换； 
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
#include "task01.h"
#include "misc.h"



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
//      void task01()
//
// Description:
//		向console打印信息，之后将任务控制权交给task02。
//
// Parameters:
//      n/a
//
// Return Value:
//      n/a
//
void task01()
{ 

	putstr("Enter task01\n");	
		
	while (1)
	{
		putstr("This is task01!\n");	
		task_sched();
	}

}
