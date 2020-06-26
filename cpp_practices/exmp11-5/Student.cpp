#include"Student.h"

Student::Student()
{
	num = "000";
	name = "xxx";
	sex = "boy/girl";
}

Student::Student(string n,string na,string s)
{
	num = n;
	name = na;
	sex = s;
}

Student::Student(const Student &s)
{
	num = s.num;
	name = s.name;
	sex = s.sex;
}

Student::~Student()
{
	cout << "class::Student destructor call" << endl;
}

void Student::getValue(void)
{
	cin >> num >> name >> sex;
}

void Student::display(void)
{
	cout << "num:" << num << ' '
	     << "name:" << name << ' '
		 << "sex:" << sex << ' ';
}