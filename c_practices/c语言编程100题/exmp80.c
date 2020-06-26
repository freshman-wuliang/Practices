/*
程序定义了NxN的二维数组，并在主函数中自动赋值
请编写函数fun(int a[][N]，int n)，该函数的功能是
使数组左下半三角元素中的值乘以n
例如：若n的值为3，a数组中的值为
|1 9 7|
|2 3 8|
|4 5 6|
则返回主程序后a数组中的值应为
|3 9 7|
|6 9 8|
|12 15 18|
*/

#include<stdio.h>

#define N 3

void function(int array[][N],int n);

int main(void)
{
	int array[N][N] = {{1,9,7},{2,3,8},{4,5,6}};
	
	printf("before:\n");
	for(int i=1;i<=N;i++)
	{
		printf("| ");
		for(int j=1;j<=N;j++)
		{
			printf("%d ",array[i-1][j-1]);
		}
		printf("|\n");
	}
	
	function(array,N);
	
	printf("after:\n");
	for(int i=1;i<=N;i++)
	{
		printf("| ");
		for(int j=1;j<=N;j++)
		{
			printf("%d ",array[i-1][j-1]);
		}
		printf("|\n");
	}
	
	return 0;
}

void function(int array[][N],int n)
{
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(i >= j)
			{
				array[i-1][j-1] *= n;
			}
		}
	}
}