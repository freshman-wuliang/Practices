/*
请编写函数fun，其功能是：
计算并输出下列多项式值：
Sn = 1 + 1/1! + 1/2! + 1/3! + 1/4! + ... + 1/n!
例如，若主函数从键盘给n输入15，则输出为s=2.718282。
注意：n的值要求大于1但不大于100
*/

#include<stdio.h>

long factorial(int n);

double function(int n);

int main(void)
{
	int n;
	
	printf("enter the n:");
	scanf("%d",&n);
	printf("result:%lf\n",function(n));
	
	return 0;
}

long factorial(int n)
{
	long sum = 1;
	
	for(int i=1;i<=n;i++)
	{
		sum *= i;
	}
	
	return sum;
}

double function(int n)
{
	double sum = 0.0;
	
	for(int i=1;i<=n;i++)
	{
		sum += 1.0 / (double)factorial(i-1);
	}
	
	return sum;
}