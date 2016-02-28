 ///
 /// @file    disconstruction.cc
 /// @author  苏志贤(529203156@qq.com)
 /// @date    2016-02-26 20:56:29
 ///

//拷贝构造函数的调用，发生在类的实例化（声明）过程中（构造一个新的对象（实例化））
//赋值运算符函数的调用，发生在 两个 已存在 的对象间 赋值的过程中 （对象赋值）（两个对象已经创建好）
#include <iostream>
#include <string.h>
using std::cout;
using std::endl;

class Company {
	public :
	Company();	//声明 默认构造函数
	Company(char *);	//声明 带参构造函数
	Company(const Company &cp);	//声明 拷贝构造函数
	Company & operator = (const Company &cp);	//赋值运算符函数
		~Company();	//声明 析构函数
	void ShowName();
	private:
	char *_name;
};

//default constructor
Company::Company()
{
	cout << "default constructer" << endl;
	_name = new char[10];
	strcpy(_name, "\0");
}

//constructor
Company::Company(char *name)
{
	cout << "constructer" << endl;
	int len = strlen(name);
	_name = new char[len + 1];
	strcpy(_name, name);
}

//拷贝构造函数
Company::Company(const Company &cp)
//:_name(cp._name) //浅拷贝
{
	int len = strlen(cp._name); 
	_name = new char[len + 1]; //申请一块堆空间，存放新对象的_name字符串
	strcpy(_name,cp._name);
	cout << "copy constructor " << endl;
}

//赋值运算符函数
Company & Company::operator = (const Company &cp)
{
	cout << "operator " << endl;
	int len = strlen(cp._name);
	_name = new char[len + 1];
	strcpy(_name, cp._name);
	return *this;
};


//析构函数
Company::~Company()
{
	cout << "disconstructer (" << _name << ")." << endl;
	delete [] _name;
}

void Company::ShowName()
{
	cout << "company name: " << _name << endl;
}

int main()
{
	cout << "-----------------" << endl;
	Company ap ;
	ap.ShowName();
	cout << "-----------------" << endl;
	Company ap1 = Company("apple");
	ap1.ShowName();
	cout << "-----------------" << endl;
	Company ap2 = ap1;
	ap2.ShowName();
	cout << "-----------------" << endl;
	ap = ap1;
	ap.ShowName();
	cout << "-----------------" << endl;
	return 0;
}
