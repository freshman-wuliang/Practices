#include<iostream>
#include<cmath>

using namespace std;

double triangle(double a,double b,double c);

int main(void)
{
	double a,b,c;
	
	cin >> a >> b >> c;
	try
	{
		while(a > 0 && b > 0 && c > 0)
		{
			cout << triangle(a,b,c) << endl;
			cin >> a >> b >> c;
		}
	}
	
	catch(double)
	{
		cout << "a = " << a << ",b = " << b << ",c = " << c;
		cout << "that is not a triangle!" << endl;
	}
	cout << "end" << endl;
	
	return 0;
}

double triangle(double a,double b,double c)
{
	double p = (a + b + c) / 2.0;
	
	if(a + b <= c || a + c <= b || b + c <= a)
		throw a;
	
	return sqrt(p * (p - a) * (p - b) * (p - c));
}