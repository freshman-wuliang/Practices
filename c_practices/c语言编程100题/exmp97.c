/*
请编写函数fun，其功能是：计算并输出下列多项式值：
s = 1 + 1/(1+2) + ... + 1/(1+2+...+n)
例如，若主函数从键盘给n输入50后，则输出为S=1.960784。
注意：n的值要求大于1但不大于100。
*/

#include<stdio.h>

double function(int n);

//assist function
int sumN(int n);

int main(void)
{
	int n;
	
	printf("enter the n:");
	scanf("%d",&n);
	printf("result:%lf\n",function(n));
	
	return 0;
}

double function(int n)
{
	double sum = 0.0;
	
	for(int i=1;i<=n;i++)
	{
		sum += 1.0 / sumN(i);
	}
	
	return sum;
}

int sumN(int n)
{
	int sum = 0;
	
	for(int i=1;i<=n;i++)
	{
		sum += i;
	}
	
	return sum;
}