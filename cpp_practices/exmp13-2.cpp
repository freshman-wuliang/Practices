#include<iostream>

using namespace std;

int main(void)
{
	int a = 21;
	
	cout.setf(ios::showbase);
	cout << "dec:" << a << endl;
	cout.unsetf(ios::dec);
	cout.setf(ios::hex);
	cout << "hex:" << a << endl;
	cout.setf(ios::oct);
	cout << "oct:" << a << endl;
}