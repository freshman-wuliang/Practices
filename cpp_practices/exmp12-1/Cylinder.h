#ifndef CYLINDER_H
#define CYLINDER_H

#include"Circle.h"
#include<iostream>

using namespace std;

class Cylinder : public Circle
{
	public:
		Cylinder();
		
		Cylinder(float a,float b,float r,float h);
		
		Cylinder(const Cylinder &c);
		
		~Cylinder();
		
		void setHeight(float h);
		
		float getHeight(void);
		
		float area(void) const;
		
		float volume(void) const;
		
		friend istream &operator >> (istream &input,Cylinder &c);
		
		friend ostream &operator << (ostream &output,const Cylinder &c);
		
	protected:
		float height;
};

#endif