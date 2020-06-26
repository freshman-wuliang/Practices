/*
编写函数九n，它的功能是：计算并输出下列级数和：
s = 1/(1*2) + 1/(2*3)+ ... + 1/(n*(n+1))
例如，当n=10时，函数值为0.909091。
*/

#include<stdio.h>

double function(int n);

int main(void)
{
	printf("result:%lf\n",function(10));
	
	return 0;
}

double function(int n)
{
	double sum = 0.0;
	
	for(int i = 1;i<=n;i++)
	{
		sum += 1.0 / (i * (i + 1.0));
	}
	
	return sum;
}