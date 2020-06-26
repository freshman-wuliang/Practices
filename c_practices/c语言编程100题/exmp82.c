/*
请编写一个函数fun，它的功能是：计算n门课程的平均分，计算结果作为函数值返回。
例如：若有5门课程的成绩是：90.5，72，80，61.5，55，则函数的值为71.80。
注意：部分源程序给出如下。
*/

#include<stdio.h>

#define MAX_NUM 10

float function(float score[],int n);

int main(void)
{
	float score[MAX_NUM];
	int n;
	
	printf("enter the n:");
	scanf("%d",&n);
	printf("enter score:");
	for(int i=1;i<=n;i++)
	{
		scanf("%f",&score[i-1]);
	}
	
	for(int i=1;i<=n;i++)
	{
		printf("%.2f ",score[i-1]);
	}
	putchar('\n');
	
	printf("ave:%.2f\n",function(score,n));
	
	return 0;
}

float function(float score[],int n)
{
	float sum = 0.0;
	
	for(int i=1;i<=n;i++)
	{
		sum += score[i-1];
	}
	
	return sum / n;
}