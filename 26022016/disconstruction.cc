 ///
 /// @file    disconstruction.cc
 /// @author  苏志贤(529203156@qq.com)
 /// @date    2016-02-26 20:56:29
 ///

//类对象在声明周期结束时，自动调用析构函数 （new出来的对象除外）
//new出来的对象 ，在类对象生命周期结束时，并没有自动调用析构函数，需要显式使用delete释放空间。

#include <iostream>
#include <string.h>
using std::cout;
using std::endl;

class Company {
	public :
	Company();
	Company(char *);
	~Company();//声明一个析构函数
	void ShowName();
	private:
	char *_name;
};
Company::Company()
{
	cout << "default constructer" << endl;
	_name = new char[10];
	strcpy(_name, "\0");
}

Company::Company(char *name)
{
	cout << "constructer" << endl;
	_name = new char[10];
	strcpy(_name, name);
}

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
	Company *pap = new Company("IBM");
	pap->ShowName();
	cout << "-----------------" << endl;
	delete pap;
	return 0;
}
