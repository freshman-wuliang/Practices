/*
下列程序定义了N*N的二维数组，并在主函数中自动赋值。
请编写函数fun(int a[N][N]，该函数的功能是：使数组左下半三角元素中的值全部置成0。
例如：a数组中的值为：
|1 9 7|
|2 3 8|
|4 5 6|                               
则返回主程序后a数组中的值应为:
|0 9 7|
|0 0 8|
|0 0 0|
*/

#include<stdio.h>

#define DIMENSION 3

void function(int a[DIMENSION][DIMENSION]);

void printMatrix(int a[DIMENSION][DIMENSION]);

int main(void)
{
	int a[DIMENSION][DIMENSION] = {{1,9,7},{2,3,8},{4,5,6}};
	
	printf("before:\n");
	printMatrix(a);
	function(a);
	printf("after:\n");
	printMatrix(a);
	return 0;
}

void function(int a[DIMENSION][DIMENSION])
{
	for(int i=0;i<DIMENSION;i++)
	{
		for(int j=0;j<DIMENSION;j++)
		{
			if(i >= j)
			{
				a[i][j] = 0;
			}
		}
	}
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