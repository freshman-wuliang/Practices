//类的继承

#include<iostream>
#include<string>

using namespace std;

class Student
{
	public :
		Student();
		
		Student(string n,string na,char s);
		
		Student(const Student &s);
		
		~Student();
		
		void display(void);
		
		void getValue(void);
		
	private :
		string num;
		string name;
		char sex;
};

class Student1 : public Student
{
	public:
		void get_value1(void);
		
		void display1(void);
		
	private:
		int age;
		string addr;
};

int main(void)
{
	Student1 s1;
	
	s1.get_value1();
	s1.display1();
	
	return 0;
}

Student::Student()
{
	num = "000";
	name = "xxx";
	sex = 'x';
}

Student::Student(string n,string na,char s)
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
	cout << "class::Student drstructor call" << endl;
}

void Student::getValue(void)
{
	cin >> num >> name >> sex;
}

void Student::display(void)
{
	cout << "num:" << num << '\t';
	cout << "name:" << name << '\t';
	cout << "sex:" << sex;
}

void Student1::get_value1(void)
{
	getValue();
	cin >> age >> addr;
}

void Student1::display1(void)
{
	display();
	cout << "\tage:" << age << '\t';
	cout << "addr:" << addr << '\t' << endl;
}