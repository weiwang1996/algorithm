void merge(int *a, int *temp, int left, int mid, int right)
{
	int  begin1 = left;
	int end1 = mid;
	int begin2 = mid + 1;
	int end2 = right;
	int index = begin1;
	while (begin1 <= end1&&begin2 <= end2)
	{
		if (a[begin1] <= a[begin2])
			temp[index++] = a[begin1++];
		else
			temp[index++] = a[begin2++];
	}
	if (begin1 > end1)//begin1走完
	{
		while (begin2 <= end2)
			temp[index++] = a[begin2++];
	}
	else if (begin2 > end2)
	{
		while (begin1 <= end1)
			temp[index++] = a[begin1++];
	}
}

void _mergeSort(int *a ,int * temp, int left, int right)
{
	if (left >= right)
		return;
	int mid = left - (left - right) / 2;
	_mergeSort(a, temp, left, mid);
	_mergeSort(a, temp, mid + 1, right);
	merge(a, temp, left, mid, right);
	memmove(a + left, temp + left, (right - left + 1)*sizeof(int));
}
void MergeSort(int * a, size_t n)
{
	if (a==NULL||n <= 0)
		return;
	int left = 0;
	int right = n - 1;
	int *temp = new int[n];
	_mergeSort(a,temp, left, right);
	delete[] temp;
}
