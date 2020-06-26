/*
请编写函数fun，该函数的功能是：
将M行N列的二维数组中的数据，按行的顺序依次放到一维数组中
一维数组中数据的个数存放在形参n所指的存储单元中
例如，若二维数组中的数据为:
|33 33 33|
|44 44 44|
|55 55 55|
则一维数组中的内容应是：33 33 33 33 44 44 44 44 55 55 55 55。
*/

#include<stdio.h>

#define M 3
#define N 3

void function(int src[][N],int dest[]);

int main(void)
{
	int src[M][N] = {{33,33,33},{44,44,44},{55,55,55}};
	int dest[M*N];
	
	for(int i=1;i<=M;i++)
	{
		printf("| ");
		for(int j=1;j<=N;j++)
		{
			printf("%d ",src[i-1][j-1]);
		}
		printf("|\n");
	}
	
	function(src,dest);
	
	printf("result: ");
	for(int i=1;i<=M*N;i++)
	{
		printf("%d ",dest[i-1]);
	}
	printf("\n");
	
	return 0;
}

void function(int src[][N],int dest[])
{
	int index = 0;
	
	for(int i=1;i<=M;i++)
	{
		for(int j=1;j<=N;j++)
		{
			dest[index++] = src[i-1][j-1];
		}
	}
}