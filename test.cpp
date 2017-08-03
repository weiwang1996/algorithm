#include<iostream>
#include<vector>
#include<assert.h>
using namespace std;

int Repitition(vector<int>& arr)
{
	assert(!arr.empty());
	int index = 0;
	int num = 0;
	for (int i=0; i < arr.size(); ++i)
	{
		index = i;
		num = arr[index];
		while (num != index)
		{
			if (arr[num] != num)
				swap(arr[num], num);
			else
				return num;
		}
	}
}
int main()
{
	vector<int> arr = {1,2,4,9,6,3,5,2,7};
	cout << Repitition(arr);
	return 0;
}