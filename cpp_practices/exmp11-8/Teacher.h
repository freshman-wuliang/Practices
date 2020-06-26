#ifndef TEACHER_H
#define TEACHER_H

#include<string>
#include<iostream>

using namespace std;

class Teacher
{
	public:
		Teacher();  //默认构造函数
		
		Teacher(string n,int a,string t);   //构造函数
		
		Teacher(const Teacher &t);
		
		~Teacher();
		
		void getValue_t(void);
		
		void display_t(void);
		
	protected:
		string name_t;
		int age;
		string title;
};

#endif