/*
请编一个函数float fun(double h)
函数的功能是对变量h中的值保留2位小数，并对第三位进行四舍五入(规定h中的值为正数)。
例如：若h值为8.32433，则函数返回8.32；若h值为8.32533，则函数返回8.33。
*/

#include<stdio.h>

float function(double h);

int main(void)
{
	double h = 8.32433;
	double m = 8.32533;
	
	printf("num:%.6lf\n",h);
	printf("result:%0.6f\n",function(h));
	printf("num:%.6lf\n",m);
	printf("result:%.6f\n",function(m));
	
	return 0;
}

float function(double h)
{
	int integer;
	double tmp;
	double tail;
	float result;
	
	tmp = h * 100.0;
	integer = (int)tmp;
	tail = tmp - integer;
	//printf("tmp:%.6lf,integer:%d,tail:%.6lf\n",tmp,integer,tail);
	if(tail >= 0.5)
	{
		integer++;
	}
	
	result = (float)integer / 100.0;
}