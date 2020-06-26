#include<iostream>
#include<iomanip>

using namespace std;

class Complex
{
	public:
		Complex(double r=0.0,double i=0.0)
		:real(r),imag(i)
		{}
		
		Complex(const Complex &c);
		
		~Complex();
		
		void display(void);
		
		Complex add(const Complex &c);
		
		Complex operator + (const Complex &c);
		
	private:
		double real;
		double imag;
};

int main(void)
{
	Complex c1(3,4);
	Complex c2(5,-10);
	
	cout << "c1:";
	c1.display();
	cout << "c2:";
	c2.display();
	cout << "c1+c2:";
	(c1+c2).display();
	
	return 0;
}

Complex::Complex(const Complex &c)
{
	real = c.real;
	imag = c.imag;
}

Complex::~Complex()
{
	cout << "class::Complex destructor call" << endl;
}

void Complex::display(void)
{
	cout << setiosflags(ios::fixed) << setprecision(2) << real;
	cout << setiosflags(ios::showpos) << imag << "i" << endl;
	cout.unsetf(ios::showpos);
}

Complex Complex::add(const Complex &c)
{
	Complex tmp;
	
	tmp.real = real + c.real;
	tmp.imag = imag + c.imag;
	
	return tmp;
}

Complex Complex::operator + (const Complex &c)
{
	Complex tmp;
	
	tmp.real = real + c.real;
	tmp.imag = imag + c.imag;
	
	return tmp;
}