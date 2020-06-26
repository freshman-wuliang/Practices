/*
编写函数fun，它的功能是：
求n以内（不包括n）同时能被3与7整除的所有自然数之和的平方根s
并作为函数值返回。
例如，若n为1000时，函数值应为s=153.909064
*/

#include<stdio.h>
#include<math.h>

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
	int sum = 0;
	
	for(int i = 1;i<n;i++)
	{
		if(i % 3 == 0 && i % 7 == 0)
		{
			sum += i;
		}
	}
	
	return sqrt(sum);
}