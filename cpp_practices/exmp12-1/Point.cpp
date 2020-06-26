#include"Point.h"

Point::Point()
{
	x = 0.0;
	y = 0.0;
}

Point::Point(float a,float b)
{
	x = a;
	y = b;
}

Point::Point(const Point &p)
{
	x = p.x;
	y = p.y;
}

Point::~Point()
{
	cout << "class::Point destructor call" << endl;
}

void Point::setPoint(float a,float b)
{
	x = a;
	y = b;
}

float Point::getX(void)
{
	return x;
}

float Point::getY(void)
{
	return y;
}

istream &operator >> (istream &input,Point &p)
{
	input >> p.x >> p.y;
	
	return input;
}

ostream &operator << (ostream &output,const Point &p)
{
	output << "(" << p.x << "," << p.y << ")";
	
	return output;
}