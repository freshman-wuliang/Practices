/*
请编写函数fun，它的功能是：
计算并输出n（包括n）以内能被5或9整除的所有自然数的倒数之和。
例如，若主函数从键盘给n输入20后，则输出为s=0.583333。
注意：n的值要求不大于100。
*/

#include<stdio.h>

double function(int n);

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
		if(i % 5 == 0 || i % 9 == 0)
		{
			sum += 1.0 / i;
		}
	}
	
	return sum;
}