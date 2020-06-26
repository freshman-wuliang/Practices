#include<iostream>
#include<math.h>

using namespace std;

int main(void)
{
	double delta;
	double a,b,c;
	double x1,x2;
	
	cout << "enter three num:";
	cin >> a >> b >> c;
	delta = b*b - 4*a*c;
	
	if(delta > 0)
	{
		x1 = (-b+sqrt(delta))/(2*a);
		x2 = (-b-sqrt(delta))/(2*a);
		cout << "x1=" << x1 << ',' << "x2=" << x2 << endl;
	}
	else if(delta < 0)
	{
		cout << "no result" << endl;
	}
	else
	{
		x1 = (-b)/(2*a);
		cout << "x1=x2=" << x1 << endl;
	}
	
	return 0;
}