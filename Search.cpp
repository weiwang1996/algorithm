#include<iostream>
#include<vector>
using namespace std;
bool SearchNum(vector<vector<int>> arr, int key)
{
	if (arr.empty())
		return false;
	int row = arr.size();//行
	int col = arr[0].size();//列
	int x = 0;
	int y = col - 1;
	while (x < row&&y >= 0)
	{
		int temp = arr[x][y];
		if (temp == key)
			return true;
		else if (temp>key)
			y--;
		else
			x++;
	}
	return false;
}
void Test1()
{
	vector<int> v1 = { 1, 3, 5, 8 };
	vector<int> v2= { 2, 4, 7, 9 };
	vector<int> v3 = { 4, 6, 8, 11 };
	vector<int> v4 = { 5, 7, 10, 12 };
	vector<vector<int>> arr = { v1, v2, v3, v4 };
	cout << SearchNum(arr,12);
}
int main()
{
	Test1();
	
	return 0;
}
