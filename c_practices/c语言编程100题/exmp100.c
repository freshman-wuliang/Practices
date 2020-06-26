/*
请编写函数fun，其功能是：计算并输出
S = 1 + (1 + 2^0.5) + ... + (1 + 2^0.5 + n^0.5)
例如，若主函数从键盘给n输入20后，则输出为s=534.188884。
注意：n的值要求大于1但不大于100。
*/

#include<stdio.h>
#include<math.h>

double function(int n);

//assist function
double cacSeries(int n);

int main(void)
{
	int n;
	
	printf("enter the n:");
	scanf("%d",&n);
	printf("result:%lf\n",function(n));
	
	return 0;
}

double cacSeries(int n)
{
	double sum = 0.0;
	
	for(int i=1;i<=n;i++)
	{
		sum += sqrt(i);
	}
	
	return sum;
}

double function(int n)
{
	double sum = 0.0;
	
	for(int i=1;i<=n;i++)
	{
		sum += cacSeries(i);
	}
	
	return sum;
}