/*
请编一个函数void fun(int tt[M][N]，int pp[N])
tt指向一个M行N列的二维数组，求出二维数组每列中最小元素，并依次放入pp所指一维数组中。
例：
|5 2 6 7|
|1 2 6 3|
|2 8 15 6|
结果：1 2 6 3
二维数组中的数已在主函数中赋予。
*/

#include<stdio.h>

#define M 3
#define N 4

void function(int tt[M][N],int pp[N]);

void printMatrix(int a[M][N]);

int main(void)
{
	int tt[M][N] = {{5,2,6,7},{1,2,6,3},{2,8,15,6}};
	int pp[N];
	
	printf("matrix:\n");
	printMatrix(tt);
	function(tt,pp);
	printf("result:");
	for(int i=1;i<=N;i++)
	{
		printf("%d ",pp[i-1]);
	}
	printf("\n");
	
	return 0;
}

void function(int tt[M][N],int pp[N])
{
	int min;
	
	for(int i=0;i<N;i++)
	{
		min = tt[0][i];
		for(int j=0;j<M;j++)
		{
			if(tt[j][i] < min)
			{
				min = tt[j][i];
			}
		}
		pp[i] = min;
	}
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
