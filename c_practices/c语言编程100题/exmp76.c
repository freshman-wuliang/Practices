/*
请编写函数fun，其功能是：
计算并输出当x<0.97时下列多项式的值，直到|Sn-Sn-1|<0.000001为止
sn = 1 + 0.5x + (0.5(0.5-1))/(2!)x^2 + ... + (0.5(0.5-1)...(0.5-n+1))/(n!)x^n
例如，若主函数从键盘给x输入0.21后，则输出为s：1.100000
*/

#include<stdio.h>
#include<math.h>

#define PRECISION 0.000001

double function(double x,int n);

//assist function
long factorial(int n);

double exp_x(double x,int n);

int main(void)
{
	double x = 0.21;
	double result;
	int i;
	
	for(i=1;fabs(function(x,i) - function(x,i-1)) >= PRECISION;i++)
	{
		printf("s_%d:%.10lf\n",i,function(x,i));
	}
	
	result = function(x,i);
	
	printf("result:%.10lf\n",result);
	
	return 0;
}

double function(double x,int n)
{
	double sum = 0.0;
	double numerator = 1.0;
	
	if(n == 0)
	{
		return 1.0;
	}
	
	for(int i=1;i<=n;i++)
	{
		//计算分子
		for(int j=0;j <= i-1;j++)
		{
			numerator *= (0.5 - j);
		}
		
		sum += (numerator / factorial(i)) * exp_x(x,i);
	}
	
	sum += 1;
	
	return sum;
}

//assist function
long factorial(int n)
{
	int sum = 1;
	
	for(int i=1;i<=n;i++)
	{
		sum *= i;
	}
	
	return sum;
}

double exp_x(double x,int n)
{
	double sum = 1.0;
	
	for(int i = 1;i<=n;i++)
	{
		sum *= x;
	}
	
	return sum;
}