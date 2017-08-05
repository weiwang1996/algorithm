#include<iostream>
#include<string.h>
#include<assert.h>
using namespace std;
void Reserve(char *pStart, char *pEnd);
void ReserveSentence(char * arr)
{
	assert(arr);
	char *Start = arr;//设置指向字符串开头的指针
	char *End = arr + strlen(arr)-1;//指向字符串尾的指针
	Reserve(Start, End);//不管三七二十一先全部反转
	char * pstart= arr;//设置两个指针都先指向翻转后的字符串首
	char *pend = arr;
	while (pend)//判断该字符串是否是一个句子 ，
	{
		if (*pend == ' ')//也就是说判断含不含 ' '
			break;//如果含有跳出
			pend++;
			if (*pend == '\0') //没有的话说明是一个单纯的词，直接跳出。
		return;
	}
	
	while (*pstart != '\0')//循环直到结束
	{
		while (*pend != ' '&&*pend!='\0')//让pend往后走直到遇到' '，或者结束
		{
			pend++;
		}
			Reserve(pstart, pend-1);//反转该单词 ，注意这里的pend指向' ',所以pend-1向前。
			if (*pend == '\0')//
			pstart = pend;//当让pstart转移到'\0'
			else
			pstart = ++pend;//没结束时 ++pend指向下一个单词的开始，让pstart指向下个单词
	}
}
void LeftRevolve(char *arr,  int i)
{
	assert(arr);	
	int n = strlen(arr);
	if (i == 0&&i>n&&n>0)//非法的字符串 或者i>n
		return;
	char *leftstart = arr;
	char* leftend = arr + i - 1;
	char *rightstart = arr + i;
	char *rightend = arr+n-1;
	//三次旋转法
	Reserve(leftstart, leftend);
	Reserve(rightstart, rightend);
	Reserve(leftstart, rightend);
}
void Reserve(char *pStart,char *pEnd)
{
	if (pStart == NULL || pEnd == NULL)
		return;
	while (pStart< pEnd)
	{
		char temp = *pStart;
		*pStart = *pEnd;
		*pEnd = temp;
		pStart++;
		pEnd--;
	}
}
int main()
{
	char arr[] = "abcdefgh";
	char arr1[] = "who am  i";
	char arr2[] = "whoami";
	ReserveSentence(arr2);
	LeftRevolve(arr, 3);
	cout << arr2<< endl;
	return 0;
}