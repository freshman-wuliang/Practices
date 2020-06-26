#ifndef CIRCLE_H
#define CIRCLE_H

#include"Point.h"
#include<iostream>

using namespace std;

const float pi = 3.1415926;

class Circle : public Point
{
	public:
		Circle();
		
		Circle(float a,float b,float r);
		
		Circle(const Circle &c);
		
		~Circle();
		
		void setRadius(float r);
		
		float getRadius(void) const;
		
		float area(void) const;
		
		friend istream &operator >> (istream &input,Circle &c);
		
		friend ostream &operator << (ostream &output,const Circle &c);
		
	protected:
		float radius;
};

#endif