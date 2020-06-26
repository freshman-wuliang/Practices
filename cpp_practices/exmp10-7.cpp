#include<iostream>
#include<iomanip>

using namespace std;

class Complex
{
	public:
		Complex()   //默认构造函数
		{real = 0.0;imag = 0.0;}
		
		Complex(double r);   //转换构造函数(将double转换为Complex)
		
		Complex(double r,double i)   //构造函数
		:real(r),imag(i)
		{}
		
		Complex(const Complex &c);   //复制构造函数
		
		~Complex();
		
		operator double();   //转换构造函数(将Complex转换为double)
		
		friend Complex operator + (Complex &c1,Complex &c2);
		
		friend Complex operator - (Complex &c1,Complex &c2);
		
		friend ostream &operator << (ostream &o,Complex &c);
		
		friend istream &operator >> (istream &input,Complex &c);
		
		
		
	private:
		double real;
		double imag;
};

int main(void)
{
	Complex c(1.0,2.0);
	Complex c1(0.0,1.0);
	Complex tmp;
	double a = 1.0;
	double r;
	
	cout << "c:" << c << endl;
	cout << "c1:" << c1 << endl;
	//r = double(c);
	tmp = c + Complex(1.0);
	cout << tmp << endl;
	
	return 0;
}

Complex::Complex(double r)
{
	real = r;
	imag = 0.0;
}

Complex::Complex(const Complex &c)
{
	real = c.real;
	imag = c.imag;
}

Complex::~Complex()
{
	//cout << "class::Complex destructor call" << endl;
}

ostream &operator << (ostream &o,Complex &c)
{
	o << setiosflags(ios::fixed) << setprecision(2) << c.real
	  << setiosflags(ios::showpos) << c.imag << "i";
	  
	 o.unsetf(ios::showpos);
	 
	 return o;
}

istream &operator >> (istream &input,Complex &c)
{
	input >> c.real >> c.imag;
	
	return input;
}

Complex operator + (Complex &c1,Complex &c2)
{
	return Complex(c1.real+c2.real,c1.imag+c2.imag);
}
		
Complex operator - (Complex &c1,Complex &c2)
{
	return Complex(c1.real-c2.real,c1.imag-c2.imag);
}

Complex::operator double()
{
	return real;
}