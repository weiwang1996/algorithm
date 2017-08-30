#include<iostream>
#include<vector>
#include<assert.h>
using namespace std;

vector<int>&  MaxDoubleOfArray(int  *arr, int size)
{
	assert(arr&&size > 0);
	vector<int> ret;
	ret.resize(2);
	if (arr[0] > arr[1])
	{
		ret[0] = arr[0];
		ret[1] = arr[1];
	}
	else
	{
		ret[1] = arr[0];
		ret[0] = arr[1];
	}
	for (int i = 2; i < size; i++)
	{
		if (arr[i]>ret[0])
			ret[0] = arr[i];
		else if (arr[i] > ret[1])
			ret[1] = arr[i];
		else
			continue;
	}
	cout << ret[0] << "  " << ret[1] << endl;
	return ret;
}
void Test(){
	int array[] = { 2, 0, 4, 67, 8, 5, 9 };
MaxDoubleOfArray(array, sizeof(array) / sizeof(array[0]));
	
}
int main()
{
	Test();
}
