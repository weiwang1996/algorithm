#include<iostream>
#include<stdio.h>
#include<vector>
using namespace std;
void Reverse(vector<int>& v)
{
	if (v.empty())
		return;
	int j = v.size()-1;
	for (int i = 0; i < v.size(); ++i)
	{
		if (i < j)
			swap(v[i], v[j]);
		else
			break;
		j--;
	}
}
vector<int> solution(vector<int>&v)
{
    vector<int> temp;
	if (v.size()<2 || v.size()>200000)
		return temp;
	for (int i = 0; i < v.size(); i++)
	{
		temp.push_back(v[i]);
		Reverse(temp);
	}
	return temp;
}
void Print(vector<int>&v)
{
	for (int i = 0; i < v.size(); ++i)
        {
		cout << v[i];
        if(i!=v.size()-1)
            cout<<" ";
    }
	cout << endl;
}
int main()
{
	int input = 0;
	cin >> input;
	vector<int> b;
	while (input--)
	{
		int in=0;
		scanf("%d",&in);
        if(in<1||in>10000000000)
            return 0;
		b.push_back(in);
	}
	vector<int> temp=solution(b);
	Print(temp);
	return 0;
}
