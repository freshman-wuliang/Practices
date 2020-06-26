#include<iostream>
#include<string>

using namespace std;

class Student
{
	public :
		Student(int n,string nam,char s);   //构造函数
		
		~Student();   //析构函数
		
		void display(void);
		
	private :
		int num;
		string name;
		char sex;
};

int main(void)
{
	Student stu(10010,"wuliang",'b');
	
	stu.display();
	
	return 0;
}

Student::Student(int n,string nam,char s)
{
	num = n;
	name = nam;
	sex = s;
}

Student::~Student()
{
	cout << "destructor call" << endl;
}

void Student::display(void)
{
	cout << "num:" << num << endl;
	cout << "name:" << name << endl;
	cout << "sex:" << sex << endl;
}