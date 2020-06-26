/*
请编写函数fun，该函数的功能是：
将M行N列的二维数组中的数据，按列的顺序依次放到一维数组中。
例如，若二维数组中的数据为:
|33 33 33 33|
|44 44 44 44|
|55 55 55 55|
则一维数组中的内容应是：33  44  55  33  44  55  33  44  55  33  44  55。
*/

#include<stdio.h>

#define M 3
#define N 4

void printMatrix(int matrix[][N],int row,int col);

void function(int matrix[][N],int array[],int n);

int main(void)
{
	int matrix[M][N] = {{33,33,33,33},{44,44,44,44},{55,55,55,55}};
	int array[M*N];
	
	printMatrix(matrix,M,N);
	function(matrix,array,M*N);
	printf("array:");
	for(int i=1;i<=M*N;i++)
	{
		printf("%d ",array[i-1]);
	}
	putchar('\n');
	
	return 0;
}

void printMatrix(int matrix[][N],int row,int col)
{
	for(int i=1;i<=row;i++)
	{
		printf("| ");
		for(int j=1;j<=col;j++)
		{
			printf("%d ",matrix[i-1][j-1]);
		}
		printf("|\n");
	}
}

void function(int matrix[][N],int array[],int n)
{
	int count = 0;
	
	for(int i=1;i<=N;i++)
	{
		for(int j=1;j<=M;j++)
		{
			array[count++] = matrix[j-1][i-1];
		}
	}
}