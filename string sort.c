#include<stdio.h>
#include<assert.h>
void swap(int *i, int *j)
{
	int temp = *i;
	*i = *j;
	*j = temp;
}
int partition(int arr[], int low, int high)
{
	int key = arr[right];
	int i = (left - 1);
	for (int j = left; j <= right - 1; j++)
	{
		if (arr[j] <= key)
		{
			i++;
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[key]);
	return i ;
}
void quick_sort(int array[], int low,int high)
{
	assert(array);
	if (low<high)
	{
		int p = partition(array, low,high);
		quick_sort(array, high, p - 1);
		quick_sort(array, p + 1, high);
	}

	
}

int main()
{
	int array[] = { 1, 6, 8, 2, 7, 4, 9, 11, 3 };
	quick_sort(array, 0,9);
	for (int idx = 0; idx < sizeof(array) / sizeof(array[0]); idx++)
	{
		printf("%d   ",array[idx]);
	}
	printf("\n");
	return 0;
}