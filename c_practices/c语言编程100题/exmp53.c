/*
请编写函数fun，该函数的功能是：
实现B=A+A'，即把矩阵A加上A的转置，存放在矩阵B中
计算结果在main函数中输出
例如，输入下面的矩阵:
|1 2 3|
|4 5 6|
|7 8 9|
其转置矩阵为：
|1 4 7|
|2 5 8|
|3 6 9|
则程序输出:
|2 6 10|
|6 10 14|
|10 14 18|
*/

#include<stdio.h>

#define M 3
#define N 3

void function(int A[M][N],int B[M][N]);

void printMatrix(int matrix[M][N]);

int main(void)
{
	int A[M][N] = {{1,2,3},{4,5,6},{7,8,9}};
	int B[M][N];
	
	printf("matrix A:\n");
	printMatrix(A);
	printf("matrix B:\n");
	function(A,B);
	printMatrix(B);
	
	return 0;
}

void function(int A[M][N],int B[M][N])
{
	for(int i=1;i<=M;i++)
	{
		for(int j=1;j<=N;j++)
		{
			B[i-1][j-1] = A[i-1][j-1] + A[j-1][i-1];
		}
	}
}

void printMatrix(int matrix[M][N])
{
	for(int i = 1;i<=M;i++)
	{
		printf("| ");
		for(int j = 1;j<=N;j++)
		{
			printf("%2d ",matrix[i-1][j-1]);
		}
		printf("|\n");
	}
}