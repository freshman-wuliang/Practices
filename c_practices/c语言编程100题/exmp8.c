/*
编写函数fun，函数的功能是：
根据以下公式计算s，计算结果作为函数值返回；n通过形参传入。
S=1+1/(1+2)+1/(1+2+3)+……1/(1+2+3+…+n)
例如：若n的值为11时，函数的值为1.833333。
*/

#include<stdio.h>

double function(int n);

int main(void)
{
	int n;
	
	printf("enter the n:");
	scanf("%d",&n);
	printf("result:%.6lf\n",function(n));
	
	return 0;
}

double function(int n)
{
	double result = 0;
	int sum = 0;
	
	for(int i=1;i<=n;i++)
	{
		printf("i:%d,sum:%d,result:%.6lf\n",i,sum,result);
		result += (1.0 / (sum + i));
		sum += i;
	}
	
	return result;
}