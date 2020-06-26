#include"Student1.h"

Student1::Student1()
{
	num = "xxx";
	name = "xxx";
	sex = "boy/girl";
	age = 0;
	addr = "xxx";
}

Student1::Student1(string n,string na,string s,int a,string ad)
:Student(n,na,s)
{
	age = a;
	addr = ad;
}

Student1::~Student1()
{
	cout << "class::Student1 destructor call" << endl;
}

void Student1::getValue1(void)
{
	getValue();
	cin >> age >> addr;
}

void Student1::display1(void)
{
	display();
	cout << "age:" << age << ' '
	     << "addr:" << addr << ' ';
}