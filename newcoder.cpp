//思路： 找到除了数组第一个和最后一个以外的最大数
//总的步数减去这个最大数
//
#include<iostream>
#include<assert.h>
#include<vector>
using namespace std;
int GoHome(int arr[],int len)
{
	assert(arr&&len > 0);
	int max = 0;
	int index = 0;
	for (int i = 1; i < len-1; ++i)
	{
		int n = abs(arr[i] - arr[len - 1]);
		if (n>max)
		{
			max = n;
			index = i;
		}
	}
	int sum = 0;
	int prev = arr[0];
	int begin = 0;
	for (int i = 0; i < len; i++)
	{
		if (i == index)
			continue;
		begin = arr[i];
		sum += abs(prev - begin);
		prev = begin;		
	}
	return sum;
}
void reOrderArray(vector<int> &array) {

	if (array.size() <= 0)
		return;
	int start = 0;
	int end = array.size() - 1;
	while (start<end)
	{
		if (array[start] % 2 != 0)
			start++;
		if (array[end] % 2 != 1)
			end--;
		std::swap(array[start], array[end]);
		start++; end--;
	}
}
int main()
{
	vector<int> v = { 1, 2, 3, 4, 5, 6, 7 };
	//int arr[] = {100,-100,99,-99};
	//int N = 4;
	//cin >> N;
	//int *arr = new int[N];
	//for (int i=0; i < N; i++)
	//	cin >> arr[i];
	reOrderArray(v);
	//cout<<GoHome(arr, N)<<endl;
	//delete[]arr;
	return 0;
}