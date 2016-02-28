 ///
 /// @file    my_string.cc
 /// @author  苏志贤(529203156@qq.com)
 /// @date    2016-02-28 16:42:45
 ///
#include<iostream>
#include<string.h>
using std::cout;
using std::endl;
class String
{
	public:
		String();
		String(const char *pstr);
		String(const String & rhs);
		String & operator=(const String & rhs);
		~String();
		void print();
	
	private:
		char *pStr_;
};
//默认构造函数
String::String()
{
	cout << "constructor" << endl;
	pStr_ = new char[1];
	strcpy(pStr_, "\0");
}
//带参构造函数
String::String(const char *pstr)
{
	cout << "constuctor with argrument" << endl;
	int len = strlen(pstr);
	pStr_ = new char[len + 1];
	strcpy(pStr_, pstr);
}
//拷贝构造函数
String::String(const String & rhs)
{
	cout << "copy constructor" << endl;
	int len = sizeof(rhs);
	pStr_ = new char[len + 1];
	strcpy(pStr_, rhs.pStr_);
}
//赋值运算符函数
String & String::operator=(const String & rhs)
{
	cout << "operator" << endl;
	if(this == &rhs) //考虑自己赋给自己的情况
		return *this;
	int len = sizeof(rhs);
	delete [] pStr_ ;			//先释放掉对象本身成员pStr_的堆空间
	pStr_ = new char[len + 1];	//接着为其申请一块 新的 大小合适的 空间
	strcpy(pStr_,rhs.pStr_);
	return *this ;
}
//析构函数
String::~String()
{
	cout << "disconstructor" << endl;
	delete [] pStr_;
}

//打印字符串
void String::print()
{
	cout << pStr_ << endl;
}

int main(void)
{
	cout << "--------------------" << endl;
	String str1;
	str1.print();
	cout << "--------------------" << endl;
	String str2 = "Hello,world";
	str2.print();
	cout << "--------------------" << endl;
	String str3 = "wangdao";
	str3.print();
	cout << "--------------------" << endl;
	str2 = str3;
	str2.print();
	cout << "--------------------" << endl;
	String str4 = str3;
	str4.print();
	cout << "--------------------" << endl;
	
	str1.print();
	str2.print();
	str3.print();
	str4.print();
}
