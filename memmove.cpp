#include<iostream>
#include<assert.h>
using namespace std;
void * Memmove(void * dest, const void* scr, size_t count)
{
	void *ret = dest;
	assert(dest);
	assert(scr);
	char* pdest = (char*)dest;
	char* pscr = (char*)scr;
	if (dest <= scr || (char*)dest >= (char*)scr + count)
	{
		while (count--)
		{
			*pdest++ = *pscr++;	
		}
	}
	else
	{
		pdest = pdest + count - 1;
		pscr = pscr + count - 1;
	//	*((pdest) + count) = *((pscr) + count);
		while (count--)
		{
			*pdest = *pscr;
			pdest --;
			pscr--;
		}
	}

	return ret;
}
