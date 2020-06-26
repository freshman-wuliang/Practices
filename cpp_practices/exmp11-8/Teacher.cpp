#include"Teacher.h"

Teacher::Teacher()  //默认构造函数
{
	name_t = "xxx";
	age = 0;
	title = "xxx";
}

Teacher::Teacher(string n,int a,string t)   //构造函数
{
	name_t = n;
	age = a;
	title = t;
}

Teacher::Teacher(const Teacher &t)
{
	name_t = t.name_t;
	age = t.age;
	title = t.title;
}

Teacher::~Teacher()
{
	cout << "class::Teacher destructor call" << endl;
}

void Teacher::getValue_t(void)
{
	cin >> name_t >> age >> title;
}
		
void Teacher::display_t(void)
{
	cout << "name:" << name_t << '\t'
	     << "age:" << age << '\t'
		 << "title:" << title << '\t';
}