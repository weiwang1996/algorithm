#include<string>
#include<iostream>
using namespace std;

void Permutation1(char* str, char* begin)
{
	if (*begin == '\0')
		cout << str << " ";
	else
	{
		for (char *ch = begin; *ch != '\0'; ++ch)
		{
			swap(*begin, *ch);
			Permutation1(str, begin + 1);
		}
	}
}
void Permutation(char* str)
{
	if (str== NULL)
		return;
	Permutation1(str, str);
}
int main()
{
	char str[] = "abc";
	Permutation(str);
	return 0;
}
