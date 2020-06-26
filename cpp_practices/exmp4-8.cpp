#include<iostream>

using namespace std;

int max(int a,int b);
float max(float a,float b);
double max(double a,double b);

int main(void)
{
	int i_a,i_b;
	float f_a,f_b;
	double d_a,d_b;
	
	cout << "enter two int num:";
	cin >> i_a >> i_b;
	cout << "max_int:" << max(i_a,i_b) << endl;
	
	cout << "enter two float num:";
	cin >> f_a >> f_b;
	cout << "max_float:" << max(f_a,f_b) << endl;
	
	cout << "enter two double num:";
	cin >> d_a >> d_b;
	cout << "max_double:" << max(d_a,d_b) << endl;
	
	return 0;
}

int max(int a,int b)
{
	return a > b? a:b;
}

float max(float a,float b)
{
	return a > b? a : b;
}

double max(double a,double b)
{
	return a > b? a : b;
}