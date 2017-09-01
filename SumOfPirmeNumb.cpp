#include<iostream>
#include<assert.h>
#include<vector>
using namesapce std;
int SumOfPirmeNumb(int arr,int N)
{
  assert(N>=2);
 
int sum=0;
 
vector temp;
 
for(int i=0;i<N,++i)
 
{
 
for(int j=arr[i]+1;j<arr[i+1];j++)
 
{
 
if(IsPirme(j))
 
temp.push_back(j);
 
}
 
}
 
auto it=temp.begin();
 
for(it=temp.begin();it!=temp.end();it++)
 
sum+=*it;
 
return sum;
}
 
bool IsPrime(int num)
 
{
 
for(int i=2;i<num;++i)
 
{
 
if(i%num!=i)
 
return false;
 
}
 
return true;
 
}
 
int main()
{
  int N=0;
  cin>>N;
 int *arr=new int[N];
 for(int i=0;i<N;++i)
 
{
 
cin>>arr[i];
 
}
int ret=SumOfPirmeNumb(arr,N);
 
cout<<ret<<endl;
  return 0;
}
