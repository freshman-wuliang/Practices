#include"Graduate.h"

Graduate::Graduate()
:Student(),Teacher()
{
	wage = 0.0;
}

Graduate::Graduate(string sn,string sna,string ss,string tn,int ta,string tt,float w)
:Student(sn,sna,ss),Teacher(tn,ta,tt)
{
	wage = w;
}

Graduate::~Graduate()
{
	cout << "class::Graduate destructor call" << endl;
}

void Graduate::getValue_g(void)
{
	getValue_s();
	getValue_t();
	
	cin >> wage;
}

void Graduate::display_g(void)
{
	display_s();
	display_t();
	
	cout << "wage:" << wage << '\t';
}