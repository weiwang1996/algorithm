#include<iostream>
using namespace std;
void swapchar(char & ch1, char& ch2)
{
	char temp = ch1;
	ch1 = ch2;
	ch2 = temp;
}
void _partition(char * str, char* begin)
{
	if (*begin == '\0')
		cout << str << "  ";
	else
	{		
		for (char *ch = begin; *ch != '\0'; ++ch)
		{
		     swapchar(*ch, *begin);
			/*char temp = *ch;
			*ch = *begin;
			*begin = temp;*/
			_partition(str, begin + 1);
			swapchar(*ch, *begin);
		}
	}
}
void Solution( char * str)
{
	if (str == NULL)
		return;
	_partition(str, str);
}
int main()
{
	char str[] = "abcd";
	Solution(str);
	//system("pause");
	return 0;
}
