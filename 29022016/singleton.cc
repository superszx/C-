 ///
 /// @file    sigleton.cc
 /// @author  苏志贤(529203156@qq.com)
 /// @date    2016-02-28 19:52:28
 ///

//单例设计模式
//可以创建和销毁
//同一时间，只存在唯一对象，存储于堆区

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;
class Single{
	public:
		static Single* GetSingleton(string name);
		static void DistorySingleton();
		static void Show();

	private:
		Single(){};
		Single(string name);
		Single(Single &cp){};
		Single & operator = (Single &cp){};
		static string _name;
		static Single *_psin;
};
string Single::_name = "default";
Single* Single::_psin = NULL;
Single* Single::GetSingleton(string name)
{
	if(_psin ==  NULL)
		_psin = new Single(name);
	return _psin;
}
void Single::DistorySingleton()
{
	delete _psin;
	_psin = NULL;
	_name = "default";
}
void Single::Show()
{
	cout << _name << endl;
}

Single::Single(string name)
{
	_name = name;
}
int main()
{
	Single::Show();	
	Single *psin1 = Single::GetSingleton(static_cast <string>("SINGLETON"));
	Single::Show();	
	Single *psin2 = Single::GetSingleton(string("SECOND"));
	Single::Show();	
	Single::DistorySingleton();
	Single::Show();	
	Single *psin3 = Single::GetSingleton(string("THIRD"));
	Single::Show();
	return 0;
}


