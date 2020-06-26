#include<iostream>
#include<iomanip>
#include<cmath>

using namespace std;

int main(void)
{
	double a,b,c;
	double half_perimeter;
	double area;
	
	cout << "enter three side:";
	cin >> a >> b >> c;
	
	if(a + b > c && a +c > b && b + c > a)
	{
		half_perimeter = (a+b+c)/2.0;
		area = sqrt(half_perimeter*(half_perimeter - a)*(half_perimeter - b)*(half_perimeter - c));
		cout << setiosflags(ios::fixed) << setprecision(2);
		cout << "area:" << area << endl;
	}
	else
	{
		cout << "parameter error" << endl;
	}
	
	return 0;
}