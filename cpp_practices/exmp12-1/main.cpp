#include<iostream>
#include"Cylinder.h"

using namespace std;

int main(void)
{
	Cylinder c(3.5,6.4,5.2,10);
	
	cout << c << endl;
	cout << "area:" << c.area() << endl;
	cout << "volume:" <<c.volume() << endl;
	
	return 0;
}