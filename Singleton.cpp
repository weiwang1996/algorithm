#include<iostream>
#include<mutex>
#include<assert.h>
using namespace std;
//version 1.0 非线程安全
class MySingleton1
{
public:
	static MySingleton1* GetInstance(int data)//设置为静态成员函数为了无对象时调用。
	{
		if (_singieton == NULL)//单例模式保证只有一个实例
			_singieton = new MySingleton1(data);
		return _singieton;
	}
	static void DelInstance()
	{
		if (_singieton)
		{
			delete _singieton;
			_singieton = NULL;
		}
	}
	void Print()
	{
		cout<<_data<<endl;
	}
private:
	MySingleton1(int data)//显式给出构造函数，并且封装private，只能内部构造，避免外部构造。
		:_data(data)
	{}
	MySingleton1(const MySingleton1& s);//封装拷贝构造函数
	MySingleton1* operator=(const MySingleton1&s);//封装赋值运算符
	static MySingleton1* _singieton;//静态的指针实例，用来获取对象。
	//单例模式下的数据
	int  _data;

};
MySingleton1* MySingleton1::_singieton = NULL;
void TestSingleton(){
	MySingleton1::GetInstance(5)->Print();
	MySingleton1::DelInstance();
}

//version 2.0 线程安全的懒汉模式
//class MySingleton2
//{
//public:
//	static MySingleton2* GetInstance(int data)//设置为静态成员函数为了无对象时调用。
//	{
//		if (_singieton == NULL)
//		{
//			_mtx.lock();
//			if (_singieton == NULL)
//			{
//				MySingleton2*temp= new MySingleton2(9);
//			_singieton=temp;
//			return _singieton;
//			}
//			_mtx.unlock();
//		}
//	}
//	static void DelInstance()
//	{
//		if (_singieton)
//		{
//			delete _singieton;
//			_singieton = NULL;
//		}
//	}
//	void Print()
//	{
//		cout << _data << endl;
//	}
//private:
//	MySingleton2(int data)//显式给出构造函数，并且封装private，只能内部构造，避免外部构造。
//		:_data(data)
//	{}
//	MySingleton2(const MySingleton2& s);//封装拷贝构造函数
//	MySingleton2* operator=(const MySingleton2&s);//封装赋值运算符
//	static mutex _mtx;
//	static MySingleton2* _singieton;//静态的指针实例，用来获取对象。
//	//单例模式下的数据
//	int  _data;
//
//};
//MySingleton2* MySingleton2::_singieton = NULL;
//void TestSingleton2(){
//	MySingleton2::GetInstance(5)->Print();
//	MySingleton2::DelInstance();
//}
// version 3.0 饿汉模型 简明高效、线程安全。
class MySingleton3
{
public:
	static MySingleton3* GetInstance()
	{
		assert(_Instance);
		return _Instance;
	}
	static void DelInstance()
	{
		if (_Instance)
		{
			delete _Instance;
			_Instance = NULL;
		}
	}
	void Print()
	{
		cout << _data << endl;
	}
private:
	MySingleton3(int data=0)
		:_data(data)
	{}
	MySingleton3(const MySingleton3 &);
	MySingleton3& operator=(const MySingleton3&);
	static MySingleton3* _Instance;
	int _data;
};
MySingleton3* MySingleton3::_Instance = new MySingleton3;
void TestSingleton3()
{
	MySingleton3::GetInstance()->Print();
	MySingleton3::DelInstance();
}
int main()
{
	//TestSingleton2();
	//TestSingleton();
	TestSingleton3();
	return 0;
}