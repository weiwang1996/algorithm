#include<iostream>
using namespace std;
void AdjustArray(int *arr, int length,bool (*fun)(int))//所有奇数在偶数的前面
{
	if (arr == NULL || length <= 1)
		return;
	int *pBegin = arr;
	int* pEnd = arr+length - 1;
	while (pBegin < pEnd)
	{
		while (pBegin < pEnd&&(!fun(*pBegin)))
			pBegin++;
		while (pEnd>pBegin&&(fun(*pEnd)))
			pEnd--;
		int temp=*pBegin;
		*pBegin = *pEnd;
		*pEnd = temp;
	}
}
bool IsEven(int num)
{
	return (num & 1) == 0;
}
int main()
{
	int arr[10] = { 1, 6, 2, 3, 5, 8, 9, 7, 4, 12 };
	AdjustArray(arr, sizeof(arr) / sizeof(int), IsEven);
	return 0;
}
