/*函数模板*/

#include<iostream>

using namespace std;

template<typename T>   //T是虚拟类型名
T max(T a,T b,T c)
{
	if(b > a)
		a = b;
	if(c > a)
		a = c;
	
	return a;
}

int main(void)
{
	int i_a = 185,i_b = 567,i_c = -76;
	float f_a = 56.87,f_b = 90.23,f_c = -32.5;
	
	cout << "max_int:"  << max(i_a,i_b,i_c) << endl;
	cout << "max_flaot" << max(f_a,f_b,f_c) << endl;
	
	return 0;
}