/*
请编写函数fun，它的功能是:
求Fibonacci数列中大于t的最小的一个数，结果由函数返回
其中Fibonacci数列F(n)的定义为：
F(0)=0，F(1)=1
F(n)=F(n-1)+F(n-2)
例如:当t=1000时，函数值为1597
*/

#include<stdio.h>

long fibonacci(int n);

long function(int t);

int main(void)
{
	printf("result:%ld\n",function(1000));
	
	return 0;
}

long fibonacci(int n)
{
	int a = 0,b = 1;
	long result;
	
	if(n == 0)
		return a;
	
	if(n == 1)
		return b;
	
	for(int i=2;i<=n;i++)
	{
		result = a + b;
		a = b;
		b = result;
	}
	
	return result;
}

long function(int t)
{
	int i = 0;
	
	while(fibonacci(i) <= t)
		i++;
	
	return fibonacci(i);
}