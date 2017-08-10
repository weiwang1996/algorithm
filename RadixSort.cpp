#include<vector>
#include<iostream>
using namespace std;

//int GetNumOfPos(int num, int pos)
//{
//	int temp = 1;
//	for (int i = 0; i < pos - 1; i++)
//	{
//		temp *= 10;
//	}
//	return (num / temp) % 10;
//}
//void RadixSort(int * arr, int n)
//{
//	int ret = 0;
//	int* temp = new int[n];
//	for (int i = 0; i < n; i++)
//		temp[i] = arr[i];
//	int **con= new int*[10];
//	for (int i = 0; i < 10; i++)
//	{
//		con[i] = new int[10];
//		con[i][0] = 0;
//	}
//	for (int pos = 1; pos < 10; pos++)
//	{
//		for (int i = 0; i < n; i++)
//		{
//			ret=GetNumOfPos(arr[i], pos);
//			int index = ++con[ret][0];
//			con[ret][index] = arr[i];
//		}
//		for (int i = 0, j = 0; i < 10; i++)
//		{
//			for (int k = 1; k <= con[i][0]; k++)
//				arr[j++] = con[i][k];
//			con[i][0] = 0;
//		}
//	}
//}

void adjust(int *a, int n, int pos)
{
	int parent = pos;
	int child = pos * 2 + 1;
	while (child < n)
	{
		if (child + 1 < n&&a[child + 1] > a[child])
			child++;
		if (a[child] > a[parent])
			swap(a[child], a[parent]);
		else
			break;
		parent = child;
		child = parent * 2 + 1;
	}
}
void make_heap(int *a, int n)
{
	if (!a || n <= 0)
		return;
	for (int i = (n - 2) / 2; i >= 0; i--)
	{
		adjust(a, n, i);
	}
}
int* GetNumOfMidIndex(int *a, int n)
{
	if (!a || n <= 0)
		return NULL;
	int ret[2] = {0};
	int ret_index = 0;
    make_heap(a, 10);
		int temp = n / 2;
		int end = n ;
		while(end)
		{
			swap(a[0], a[--end]);
			adjust(a, end, 0);
			if (end == temp)
			{
				if (ret_index > 1)
					break;
				ret[ret_index]=a[temp];
				ret_index++;
				if (temp % 2 != 0)
					break;
				else
					continue;
			}
		}
		return ret;
}

int main()
{
	int arr[] = { 521, 310, 72, 373, 15, 546, 385, 856, 187, 147 ,0};
	//RadixSort(arr, sizeof(arr) / sizeof(arr[1]));
	int *ret = GetNumOfMidIndex(arr, 11);
	for (int i = 0; i < 10; ++i)
		cout << arr[i] << " ";
	cout << endl;
	for (int i = 0; i < 2; ++i)
		cout << ret[i] << " ";
	
	return 0;
}