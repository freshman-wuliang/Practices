/*
程序定义了N*N的二维数组，并在主函数中赋值。
请编写函数fun，函数的功能是：求出数组周边元素的平均值并作为函数值返回给主函数中的s。
例如：若a数组中的值为：
|0 1 2 9 7|
|1 9 7 4 5|
|2 3 8 3 1|
|4 5 6 8 2|
|5 9 1 4 1|
则返回主程序后s的值应为3.375。
*/

#include<stdio.h>

#define DIMENSION 5

void printMatrix(int a[DIMENSION][DIMENSION]);

float function(int a[DIMENSION][DIMENSION]);

int main(void)
{
	int a[DIMENSION][DIMENSION] = {{0,1,2,9,7},{1,9,7,4,5},{2,3,8,3,1},{4,5,6,8,2},{5,9,1,4,1}};
	float result;
	
	printf("Matrix:\n");
	printMatrix(a);
	result = function(a);
	printf("result:%.3f\n",result);
	
	return 0;
}

void printMatrix(int a[DIMENSION][DIMENSION])
{
	for(int i=0;i<DIMENSION;i++)
	{
		printf("| ");
		for(int j=0;j<DIMENSION;j++)
		{
			printf("%d ",a[i][j]);
		}
		printf("|\n");
	}
}

float function(int a[DIMENSION][DIMENSION])
{
	int sum = 0;
	float average;
	
	for(int i=1;i<=DIMENSION;i++)
	{
		for(int j=1;j<=DIMENSION;j++)
		{
			if(i == 1 || i == DIMENSION)
			{
				sum += a[i-1][j-1];
			}
			else
			{
				if(j == 1 || j == DIMENSION)
				{
					sum += a[i-1][j-1];
				}
			}
		}
	}
	average = (float)sum / (float)(DIMENSION*2 + 2*(DIMENSION-2));
	
	return average;
}