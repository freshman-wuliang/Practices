#include"Circle.h"

Circle::Circle()
:Point()
{
	radius = 0.0;
}

Circle::Circle(float a,float b,float r)
:Point(a,b)
{
	radius = r;
}

Circle::Circle(const Circle &c)
:Point(c)
{
	radius = c.radius;
}

Circle::~Circle()
{
	cout << "class::Circle destructor call" << endl;
}

void Circle::setRadius(float r)
{
	radius = r;
}

float Circle::getRadius(void) const
{
	return radius;
}

float Circle::area(void) const
{
	return pi * radius * radius;
}

istream &operator >> (istream &input,Circle &c)
{
	input >> c.x >> c.y >> c.radius;
	
	return input;
}

ostream &operator << (ostream &output,const Circle &c)
{
	output << "{(" << c.x << "," << c.y << ")," << c.radius << "}";
	
	return output;
}