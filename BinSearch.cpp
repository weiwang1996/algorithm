int BinSearch(int * arr, int k,size_t n)
{
	assert(arr);
	int left = 0;
	int right = n - 1;、、？、、、
	while (left < right)
	{
		int mid = left+(right-left) / 2;
		if (k>arr[mid])
		{
			left = mid;
		}
		else if (k < arr[mid])
		{
			right = mid;
		}
		else
			return mid;
	}
	if (left>right)
		return -1;
}
//时间复杂度N^2，空间复杂度N
int BinSearch(int * arr, int k,int left,int right)
{
	assert(arr);
	int mid = 0;
	if (left <= right)
	{
		mid = (right + left) / 2;
		if (k == arr[mid])
			return mid;
		else if (k > arr[mid])
			return BinSearch(arr, k, mid+1, right);
		else if (k < arr[mid])
			return BinSearch(arr, k, left-1, mid);
	}
	else return -1;
}
