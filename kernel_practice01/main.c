//==========================================
// Filename:
//		main.c
//
// Description:
//		main向console打印信息。
//
// Author/Created Date:
//      Guangwei Jiang, 2012-0817
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
#include "misc.h"

//-----------------------------------------------------------------
// DEFINES
//-----------------------------------------------------------------
#define GOLDFISH_TTY_PUT_CHAR (*(volatile unsigned int *)0xff002000)

//-----------------------------------------------------------------
// INTERNAL FUNCTIONS
//-----------------------------------------------------------------
void main();

//-----------------------------------------------------------------
// EXTERNAL FUNCTIONS
//-----------------------------------------------------------------



//-----------------------------------------------------------------
// IMPLEMENTATION
//-----------------------------------------------------------------


//----------------------------------------------------------------------------
// Function:
//      void main()
//
// Description:
//		main向console打印信息。
//
// Parameters:
//      n/a
//
// Return Value:
//      n/a
//
void main()
{ 

	putstr("Enter main\n");	
		
	while (1)
	{
		putstr("Hello World!\n");	
	}

}


