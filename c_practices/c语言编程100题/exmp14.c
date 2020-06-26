/*
请编写函数fun，函数的功能是求出二维数组周边元素之和，作为函数值返回。二维数组中的值在主函数中赋予。
例如：若二维数组中的值为:
|1 3 5 7 9|
|2 9 9 9 4|
|6 9 9 9 8|
|1 3 5 7 0|
则函数值为61。
*/

#include<stdio.h>

#define M 4
#define N 5

void printMatrix(int a[M][N]);

int function(int array[M][N]);

int main(void)
{
	int array[M][N] = {{1,3,5,7,9},{2,9,9,9,4},{6,9,9,9,8},{1,3,5,7,0}};
	int result;
	
	printf("Matrx:\n");
	printMatrix(array);
	printf("result:");
	result = function(array);
	printf("%d\n",result);
	
	return 0;
}

void printMatrix(int a[M][N])
{
	for(int i=0;i<M;i++)
	{
		printf("| ");
		for(int j=0;j<N;j++)
		{
			printf("%d ",a[i][j]);
		}
		printf("|\n");
	}
}

int function(int array[M][N])
{
	int sum = 0;
	
	for(int i=1;i<=M;i++)
	{
		for(int j=1;j<=N;j++)
		{
			if(i == 1 || i == M)
			{
				sum += array[i-1][j-1];
			}
			else
			{
				if(j == 1 || j == N)
				{
					sum += array[i-1][j-1];
				}
			}
		}
	}
	
	return sum;
}