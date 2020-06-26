/*
请编写函数fun，其功能是：
计算并输出给定10个数的方差：
例如，给定的10个数为95.0、89.0、76.0、65.0、88.0、72.0、85.0、81.0、90.0、56.0
则输出为S=11.730729。
*/

#include<stdio.h>
#include<math.h>

#define N 10

void printNum(float num[],int n);

float aveNum(float num[],int n);

float variance(float num[],int n);

int main(void)
{
	float num[N] = {
		95.0,89.0,75.0,65.0,88.0,
		72.0,85.0,81.0,90.0,56.0
	};
	
	printNum(num,N);
	printf("variance:%.2f\n",variance(num,N));
	
	return 0;
}

void printNum(float num[],int n)
{
	printf("score:");
	for(int i=1;i<=n;i++)
	{
		printf("%.2f ",num[i-1]);
	}
	putchar('\n');
}

float aveNum(float num[],int n)
{
	float sum = 0.0;
	
	for(int i=1;i<=n;i++)
	{
		sum += num[i-1];
	}
	
	return sum / n;
}

float variance(float num[],int n)
{
	float ave;
	float sum = 0.0;
	
	ave = aveNum(num,n);
	for(int i=1;i<=n;i++)
	{
		sum += (num[i-1] - ave) * (num[i-1] - ave);
	}
	
	sum /= n;
	
	return (float)sqrt(sum);
}