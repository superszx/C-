 ///
 /// @file    sigleton.cc
 /// @author  苏志贤(529203156@qq.com)
 /// @date    2016-02-28 19:52:28
 ///
 
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;
class Single{
	public:
		static Single & Init();
		static void Show();
		static Single *_psin;
		static string _name;
	private:
		Single(){};
		Single(Single &cp){};
		Single & operator = (Single &cp){};
};
string Single::_name = "bigin";
Single *Single::_psin = NULL;
Single & Single::Init()
{
	if(_psin ==  NULL)
	{	
		_name = "SINGLETON";
		static Single thesingle ;
		_psin = &thesingle;
	}
	return *_psin;
}

void Single::Show()
{
	cout << _name << endl;
}

int main()
{
	Single::Show();	
	Single::Init();
	Single::Show();
	return 0;
}


