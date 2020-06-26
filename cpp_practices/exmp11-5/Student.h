#ifndef STUDENT_H
#define STUDENT_H

#include<string>
#include<iostream>

using namespace std;

class Student
{
	public:
		Student();   //默认构造函数
		
		Student(string n,string na,string sex);   //构造函数
		
		Student(const Student &s);  //复制构造函数
		
		~Student();   //析构函数
		
		void getValue(void);
		
		void display(void);
		
	protected:
		string num;
		string name;
		string sex;
};

#endif