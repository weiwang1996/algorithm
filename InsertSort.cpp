void InsertSort(int *a, size_t n)
{
	for (int i = 0; i<n-1; i++)
	{
		int end = i;
		int temp = a[end + 1];
		while (end >= 0)
		{
			if (a[end] > temp)
			{
				a[end + 1] = a[end];
				end--;
			}
			else
				break;
			a[end+1] = temp;
		}
	}
}
