#include<iostream>
#include<assert.h>
using namespace std;
int MoreThanHalf(int arr[], size_t num)
{
	assert(arr  && num > 0);
	int cur = arr[0];
	int count = 0;
	for (int i = 1; i < num; ++i)
	{
		if (count == 0)
		{
			cur = arr[i];
		}
		else
		{
			if (cur == arr[i])
				count++;
			else
				count--;
		}
	}
	return cur;
}
void Test2()
{
	int arr[] = { 1, 3, 2, 55, 4, 3, 2, 3, 2, 3, 5, 6, 3 };
	int arr1[] = { 1, 2, 3, 2, 1, 3, 2, 3, 3 };
	cout << MoreThanHalf(arr1, sizeof(arr1) / sizeof(arr1[2]));
}
int main()
{

	Test2();
}