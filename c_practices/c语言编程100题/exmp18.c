/*
编写程序，实现矩阵(3行3列)的转置(即行列互换)。
例如，若输入下面的矩阵:
|100 200 300|
|400 500 600|
|700 800 900|
则程序输出:
|100 400 700|
|200 500 800|
|300 600 900|
*/

#include<stdio.h>

#define M 3
#define N 3

void printMatrix(int a[M][N]);

void function(int array[M][N]);

int main(void)
{
	int array[M][N] = {{100,200,300},{400,500,600},{700,800,900}};
	
	printf("before:\n");
	printMatrix(array);
	printf("after:\n");
	function(array);
	printMatrix(array);
	
	return 0;
}

//打印矩阵
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

//实现矩阵转置
void function(int array[M][N])
{
	int tmp;
	
	for(int i=1;i<=M;i++)
	{
		for(int j=1;j<=N;j++)
		{
			if(i > j)
			{
				tmp = array[i-1][j-1];
				array[i-1][j-1] = array[j-1][i-1];
				array[j-1][i-1] = tmp;
			}
		}
	}
}