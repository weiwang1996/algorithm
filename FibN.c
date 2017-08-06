#include<stdio.h>
//long long Fibonacci(unsigned n)
//{
//	if (n <= 0)
//		return 0;
//	if (n == 1)
//		return 1;
//		return Fibonacci(n - 1) + Fibonacci(n - 2);
//}
long long Fibonacci(unsigned n)
{
	int result[2] = { 0, 1 };
	if (n < 2)
		return result[n];
	long long Fibnasecond = 1;
	long long Fibnafirst = 0;
	long long FibN = 0;
	for (unsigned i = 2; i <= n; ++i)
	{
		FibN = Fibnafirst + Fibnasecond;
		Fibnafirst=Fibnasecond ;//把第一个
		 Fibnasecond = FibN;
	}
	return FibN;
}
void TestFun()
{
	long long ret = 0;
	ret=Fibonacci(20);
	printf("ret=%d\n",ret);

}
int main()
{
	TestFun();
	return 0;
}