#include"Student.h"

Student::Student()
{
	num = "000";
	name_s = "xxx";
	sex = "boy/girl";
}

Student::Student(string n,string na,string s)
{
	num = n;
	name_s = na;
	sex = s;
}

Student::Student(const Student &s)
{
	num = s.num;
	name_s = s.name_s;
	sex = s.sex;
}

Student::~Student()
{
	cout << "class::Student destructor call" << endl;
}

void Student::getValue_s(void)
{
	cin >> num >> name_s >> sex;
}

void Student::display_s(void)
{
	cout << "num:" << num << ' '
	     << "name:" << name_s << ' '
		 << "sex:" << sex << ' ';
}