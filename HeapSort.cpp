void _AdjustDown(int *a, int n, int root)
{
	int parent = root;
	int child = parent * 2 + 1;
	while (child < n)
	{
		if (child + 1 < n&&a[child + 1] > a[child])
			child++;
		if (a[child] > a[parent])
		{
			swap(a[child], a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
			break;
	}
}
void HeapSort(int *a, size_t n)
{
	assert(a);
	for (int i = (n - 2) / 2; i >= 0; --i)
	{
		_AdjustDown(a, n, i);
	}
	int end = n;
	while (end--)
	{
		swap(a[0], a[end]);
		_AdjustDown(a, end, 0);
	}
}
