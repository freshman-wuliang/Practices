/*
请编写一个函数fun，它的功能是：
求出一个2*M整型二维数组中最大元素的值，并将此值返回调用函数。
例
|5 7 3 1|
|4 12 6 8|
结果:12
*/

#include<stdio.h>

#define M 4

int function(int array[2][M],int row,int col);

int main(void)
{
	int array[2][M] = {{5,7,3,1},{4,12,6,8}};
	
	printf("matrix:\n");
	for(int i=1;i<=2;i++)
	{
		printf("| ");
		for(int j=1;j<=M;j++)
		{
			printf("%d ",array[i-1][j-1]);
		}
		printf("|\n");
	}
	printf("result:%d\n",function(array,2,M));
	
	return 0;
}

int function(int array[2][M],int row,int col)
{
	int max;
	
	max = array[0][0];
	for(int i=1;i<=row;i++)
	{
		for(int j=1;j<=col;j++)
		{
			if(array[i-1][j-1] > max)
			{
				max = array[i-1][j-1];
			}
		}
	}
	
	return max;
}