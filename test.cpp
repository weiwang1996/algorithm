#include<iostream>
using namespace std;
class Person
{
public:
	void print()
	{
		cout << _name << "--" << _age << "--" << _gender << endl;
	}
private:
	int _age;//年龄
	char _gender[5];//性别
	char _name[20];//姓名
};
class Student : public  Person //学生类继承自人类
{
private:
	int stu_num[20];//学号
	double garde;//成绩
};
class B
{
	B();
public:
	void funtest();
private:
	int _b;
};
class D :public B
{
public:
	D()
	:B()
	, _d(0)
	{
	}
private:
	int _d;
};
B::B()
{
	cout << "B::B()" << endl;
}