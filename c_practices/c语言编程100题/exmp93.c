/*
请编写函数fun，它的功能是:
计算下列级数和，和值由函数值返回
s = 1 + x + ... + (x^n / n!)
例如，当n=10，x=0.3时，函数值为1.349859。
*/

#include<stdio.h>

double function(double x,int n);

//assist function
long factorial(int n);

double exp_f(double x,int n);

int main(void)
{
	int n;
	double x;
	
	printf("enter the x,n:");
	scanf("%lf,%d",&x,&n);
	printf("result:%lf\n",function(x,n));
	
	return 0;
}

//assist function
long factorial(int n)
{
	long sum = 1;
	
	for(int i=1;i<=n;i++)
	{
		sum *= i;
	}
	
	return sum;
}

double exp_f(double x,int n)
{
	double sum = 1.0;
	
	for(int i=1;i<=n;i++)
	{
		sum *= x;
	}
	
	return sum;
}

double function(double x,int n)
{
	double sum = 0.0;
	
	for(int i=0;i<=n;i++)
	{
		sum += (exp_f(x,i)) / (factorial(i));
	}
	
	return sum;
}