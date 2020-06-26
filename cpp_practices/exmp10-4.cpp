//重载双目运算符

#include<iostream>
#include<cstring>

using namespace std;

class mString
{
	public:
		mString(char *s=NULL)
		:pstr(s)
		{}
		
		mString(const mString &s);
		
		~mString();
		
		void display(void);
		
		friend bool operator > (const mString &s1,const mString &s2);
		
	private:
		char *pstr;
};

int main(void)
{
	mString s1("hello");
	mString s2("world");
	
	s1.display();
	cout << " ";
	s2.display();
	cout << endl;
	cout << "s1>s2?:" << (s1 > s2) << endl;
	
	return 0;
}

mString::mString(const mString &s)
{
	pstr = s.pstr;
}

mString::~mString()
{
	cout << "class::mString destructoer call" << endl;
}

void mString::display(void)
{
	cout << pstr;
}

bool operator > (const mString &s1,const mString &s2)
{
	if(strcmp(s1.pstr,s2.pstr) > 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}