#include<iostream>

using namespace std;

int main(void)
{
	bool leap;
	int year;
	
	cout << "enter a year:";
	cin >> year;
	
	if(year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
	{
		leap = true;
	}
	else
	{
		leap = false;
	}
	
	if(leap)
	{
		cout << year << "is a leap year" << endl;
	}
	else
	{
		cout << year << "is not a leap year" << endl;
	}
	
	return 0;
}