#include"Cylinder.h"

Cylinder::Cylinder()
:Circle()
{
	height = 0.0;
}

Cylinder::Cylinder(float a,float b,float r,float h)
:Circle(a,b,r)
{
	height = h;
}

Cylinder::Cylinder(const Cylinder &c)
:Circle(c)
{
	height = c.height;
}

Cylinder::~Cylinder()
{
	cout << "class::Cylinder destructor call" << endl;
}

void Cylinder::setHeight(float h)
{
	height = h;
}

float Cylinder::getHeight(void)
{
	return height;
}

float Cylinder::area(void) const
{
	float base_area;
	float lateral_area;
	
	base_area = pi * radius * radius;
	lateral_area = pi * 2.0 * radius * height;
	
	return 2.0 * base_area + lateral_area;
}

float Cylinder::volume(void) const
{
	return pi * radius * radius * height;
}

istream &operator >> (istream &input,Cylinder &c)
{
	input >> c.x >> c.y >> c.radius >> c.height;
	
	return input;
}

ostream &operator << (ostream &output,const Cylinder &c)
{
	output << "{(" << c.x << "," << c.y << ")," << c.radius << "," << c.height << "}";
	
	return output;
}