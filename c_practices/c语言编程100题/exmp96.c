/*
请编写函数fun，其功能是：
计算并输出给定数组（长度为9）中每相邻两个元素之平均值的平方根之和。
例如，若给定数组中的9个元素依次为:
12.0、34.0、4.0、23.0、34.0、45.0、18.0、3.0、11.0
则输出应为s=35.951014。
*/

#include<stdio.h>
#include<math.h>

#define N 9

float function(float array[],int n);

int main(void)
{
	float array[N] = {12.0,34.0,4.0,23.0,34.0,45.0,18.0,3.0,11.0};
	
	for(int i=1;i<=N;i++)
	{
		printf("%.2f ",array[i-1]);
	}
	putchar('\n');
	
	printf("result:%f\n",function(array,N));
	
	return 0;
}

float function(float array[],int n)
{
	float sum = 0.0;
	
	for(int i=1;i<=n-1;i++)
	{
		sum += sqrt((array[i] +  array[i-1]) / 2.0);
	}
	
	return sum;
}