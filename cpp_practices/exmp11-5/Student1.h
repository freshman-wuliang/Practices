#ifndef STUDENT1_H
#define STUDENT1_H

#include"Student.h"
#include<string>
#include<iostream>

using namespace std;

class Student1 : public Student
{
	public:
		Student1();
		
		Student1(string n,string na,string s,int a,string ad);
		
		~Student1();
		
		void getValue1(void);
		
		void display1(void);
		
	protected:
		int age;
		string addr;
};

#endif