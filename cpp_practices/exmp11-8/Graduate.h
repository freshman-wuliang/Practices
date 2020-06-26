#ifndef GRADUATE_H
#define GRADUATE_H

#include"Student.h"
#include"Teacher.h"
#include<iostream>
#include<string>

using namespace std;

class Graduate : public Teacher, public Student
{
	public:
		Graduate();
		
		Graduate(string sn,string sna,string ss,string tn,int ta,string tt,float w);
		
		~Graduate();
		
		void getValue_g(void);
		
		void display_g(void);
		
	private:
		float wage;
};

#endif