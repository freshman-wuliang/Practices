/*
请编写一个函数fun，它的功能是：根据以下公式求π的值
要求满足精度0.0005，即某项小于0.0005时停止迭代：
迭代公式为：
PI / 2 = 1 + 1/3 + (1*2)/(3*5) + (1* ... *n)/(3*...*(2*n + 1))
*/

#include<stdio.h>

#define PRESICION 0.000001

float function(void);

int main(void)
{
	printf("pi:%f\n",function());
	
	return 0;
}

float function(void)
{
	float pi = 1.0;
	float numerator = 1.0;
	float denominator = 3.0;
	
	for(int i=1;;i++)
	{
		pi += numerator / denominator;
		numerator *= i+1;
		denominator *= (2*(i+1) + 1);
		printf("i:%d\n",i);
		printf("pi:%f\n",pi*2.0);
		
		if(numerator/denominator < PRESICION)
			break;
	}
	
	return pi*2;
}
