/*
编写函数fun，它的功能是：
根据以下公式求P的值，结果由函数值带回。m与n为两个正整数且要求m>n。
p = (m!)/(n!*(m-n)!);
例如：m=12，n=8时，运行结果为495.000000。
*/

#include<stdio.h>

double function(int m,int n);

long factorial(int n);

int main(void)
{
	int m,n;
	
	printf("enter m and n:");
	scanf("%d%d",&m,&n);
	printf("result:%.6lf\n",function(m,n));
	
	return 0;
}

double function(int m,int n)
{
	double result;
	
	result = (double)factorial(m) / (double)(factorial(n)*factorial(m-n));
	
	return result;
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