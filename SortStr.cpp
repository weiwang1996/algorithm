#include<iostream>
#include<string.h>
using namespace std;

void Solution(char *str,char* pstart)
{
	if (*pstart=='\0')
		cout<<str<<endl;
	for (char *ch = pstart; *ch != '\0'; ch++)
	{
		swap(*ch, *pstart);
		Solution(str, pstart + 1);
		swap(*ch, *pstart);
	}
}
void Permutation(char * str)
{
	if (str == NULL)
		return;
	char *pstart = str;
	Solution(str, pstart);
}
	int main()
	{
	Permutation("abc");
	return 0;
}