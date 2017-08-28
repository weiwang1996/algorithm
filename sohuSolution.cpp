#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
int a[100000007];
void work(int N,int *arr,int size)
{
	if (size == 0)
		return; 
	const int max = 10000;
	int temp[max] = {arr[0]};
	int cur = 0;
	int a = arr[0];
		int index = 0;
		int prev = 0;
		for (int i = 0; i < max; i++)
		{
			int a = temp[prev];
		
				for (int k = 0; k < a; k++)
				{
					temp[cur++] = arr[index%size];
				}
				index++;		
			prev++;
			if (cur >= N)
				break;
		}
	for (int i = 0; i < N; i++)
	{
		cout << temp[i] << endl;
	}
}
int main()
{
	int N;
	int size;
	cin >> N;
	cin >> size;
	int *arr=new int[size];
	for (int i = 0; i<size; i++)
		cin >> arr[i];
	work(N,arr,size);
	return 0;
}
