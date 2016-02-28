 ///
 /// @file    this.cc
 /// @author  苏志贤(529203156@qq.com)
 /// @date    2016-02-27 21:39:19
 ///
 
//this 指针是指向 对象本身的指针，作用域在对应的成员函数内。
//使用stactic成员函数时，没有隐含this指针传入。
//使用非stactic成员函数时，隐含this指针传入。
//private成员只能在 类内调用。

#include <iostream>

using std::cout;
using std::endl;

class Point
{
	public:
		Point();
		Point(int x, int y);
		void print();
		static void printsomething();
		static void func1(Point *);
	private:
		static int _len;
		int _x;
		int _y;
};

//静态成员要在 类外初始化
int Point::_len = 10;
//默认构造函数
Point::Point()
:_x(0)
,_y(0)
{
	cout << "Point()" << endl;
}
//带参构造函数
Point::Point(int x , int y )
:_x(x)
,_y(y)
{
	cout << "Point(int x, int y)" << endl;
}
//成员函数（接口）（public）
void Point::print()
{
	_len ++; 
	cout << "p("<<this->_x <<","<<_y<<")" << "len = "<< _len << endl;
}
//静态成员函数（static）（无隐含this指针传入）
void Point::printsomething()
{
	//静态成员函数可以调用static私有成员，原因是static成员存在于全局静态区，不需要this指针访问。
	cout << "len = "<< _len <<" ------------------" << endl; 
	//静态成员函数 不可调用 非静态成员 ，原因是没有隐含的this指针传入。
	//invalid use of member ‘Point::_y’ in static member function
	//cout << "p("<<_x <<","<<_y<<")" << endl;
}
//静态成员函数（static）（可访问Point类 对象的private成员）
void Point::func1(Point *p)
{
	//可以访问p的私有成员，原因是静态成员函数在类中定义 也属于类内访问。
	cout << "point("<<p->_x<<","<<p->_y<<")" << endl;
}

int main()
{
	Point pt =	Point(3,3);
	Point pt1;
	Point pt2(2,2);
	
	//也可以用作用域限定符::来调用类的 静态成员函数
	Point::printsomething();

	//但是 不能 用::来调用类的 非静态成员函数
	//Point::print();
	//error| cannot call member function ‘void Point::print()’ without object
	
	//非静态成员函数，隐含this指针作为参数传入
	pt1.print();
	pt2.print();

	pt.printsomething();
	
	//静态成员函数，无隐含this指针传入，
	//若要访问private成员，必须传递对应对象指针
	pt.func1(&pt);

	//this指针的作用域是成员函数内，不能作为实参传递。
	// error| invalid use of ‘this’ in non-member function
	//pt.func1(this);
	
	//error| within this context
	//静态私有成员不能在类外访问。
	//cout << "len = " <error| within this context< Point::len << endl;
}




