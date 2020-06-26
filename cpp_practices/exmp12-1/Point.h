#ifndef POINT_H
#define POINT_H

#include<iostream>

using namespace std;

class Point
{
	public:
		Point();
		
		Point(float a,float b);
		
		Point(const Point &p);
		
		~Point();
		
		void setPoint(float a,float b);
		
		float getX(void);
		
		float getY(void);
		
		friend istream &operator >> (istream &input,Point &p);
		
		friend ostream &operator << (ostream &ouput,const Point &p);
		
	protected:
		float x;
		float y;
};

#endif