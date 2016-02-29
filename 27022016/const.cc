 ///
 /// @file    const.cc
 /// @author  苏志贤(529203156@qq.com)
 /// @date    2016-02-29 09:59:43
 ///

//const 修饰的成员函数 以只读的方式访问成员
//不能修改成员；
//不能调用非const成员函
#include <iostream>
using std::cout;
using std::endl;
class Date{
	public:
		Date();
		Date(int year, int mon, int day);
		void Func1() const;
	private:
		int _year;
		int _mon;
		int _day;
};

Date::Date()
:_year(1900)
,_mon(1)
,_day(1)
{
}

Date::Date(int year, int mon, int day)
:_year(year)
,_mon(mon)
,_day(day)
{
}
void Date::Func1() const
{
	//error| assignment of member ‘Date::_year’ in read-only object
	//_year = 2000;//const成员函数不能修改对象成员的值。
	
	//只可以读
	cout <<_year<<"年 "<<_mon<<"月 "<<_day<<"日" << endl;
}
int main()
{
	Date d;
	d.Func1();
	Date d1(2016,02,29);
	d1.Func1();
	return 0;
}
