/*
下列程序定义了NxN的二维数组，并在主函数中自动赋值
请编写函数fun(int a[][N]，int n)，该函数的功能是：
数组右上半三角元素中的值乘以m。
例如：若m的值为2，a数组中的值为：
|1 9 7|
|2 3 8|
|4 5 6|
则返回主程序后a数组中的值应为：
|2 18 14|
|2 6 16|
|4 5 12|
*/

#include<stdio.h>

#define N 3

void printMatrix(int cMatrix[N][N],int n);

void function(int cMatrix[N][N],int m);

int main(void)
{
	int cMatrix[N][N] = {{1,9,7},{2,3,8},{4,5,6}};
	
	printf("before:\n");
	printMatrix(cMatrix,N);
	function(cMatrix,2);
	printf("after:\n");
	printMatrix(cMatrix,N);
	
	return 0;
}

void printMatrix(int cMatrix[N][N],int n)
{
	for(int i=1;i<=n;i++)
	{
		printf("| ");
		for(int j=1;j<=n;j++)
		{
			printf("%d ",cMatrix[i-1][j-1]);
		}
		printf("|\n");
	}
}

void function(int cMatrix[N][N],int m)
{
	for(int i = 1;i<=N;i++)
	{
		for(int j=1;j<=N;j++)
		{
			if(j >= i)
			{
				cMatrix[i-1][j-1] *= m;
			}
		}
	}
}