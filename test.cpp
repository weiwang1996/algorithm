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
	int _age;//����
	char _gender[5];//�Ա�
	char _name[20];//����
};
class Student : public  Person //ѧ����̳�������
{
private:
	int stu_num[20];//ѧ��
	double garde;//�ɼ�
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