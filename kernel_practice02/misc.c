//==========================================
// Filename:
//		main.c
//
// Description:
//		定义一些函数，如putstr().
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
// IMPLEMENTATION
//-----------------------------------------------------------------

//----------------------------------------------------------------------------
// Function:
//      void putc2(int c)
//
// Description:
//		向console输出一个字符。
//
// Parameters:
//      int c：				要输出的字符
//
// Return Value:
//      n/a
//
void putc2(int c)
{
	GOLDFISH_TTY_PUT_CHAR = c;
}

//----------------------------------------------------------------------------
// Function:
//      static inline void flush(void)
//
// Description:
//		此处没有任何意义，仅保留函数接口而已
//
// Parameters:
//      n/a
//
// Return Value:
//      n/a
//
inline void flush(void)
{
}

//----------------------------------------------------------------------------
// Function:
//      void putstr(const char *ptr)
//
// Description:
//		向console输出一个字符串
//
// Parameters:
//      const char *ptr：			要输出的字符串指针
//
// Return Value:
//      n/a
//
void putstr(const char *ptr)
{
	char c;

	while ((c = *ptr++) != '\0') {
		if (c == '\n')
			putc2('\r');
		putc2(c);
	}

	flush();
}
