/*
请编写函数fun，该函数的功能是：
删去一维数组中所有相同的数，使之只剩一个
数组中的数已按由小到大的顺序排列，函数返回删除后数组中数据的个数。
例如，若一维数组中的数据是：
2  2  2  3  4  4  5  6  6  6  6  7  7  8  9  9  10  10  10
删除后，数组中的内容应该是：
2  3  4  5  6  7  8  9  10。
*/

#include<stdio.h>

#define MAXSZIE 30
#define N 19

void printArray(int array[],int n);

int function(int array[],int n);

int main(void)
{
	int array[MAXSZIE] = {2,2,2,3,4,4,5,6,6,6,6,7,7,8,9,9,10,10,10};
	int n;
	
	printArray(array,N);
	n = function(array,N);
	printArray(array,N - n);
	
	return 0;
}

void printArray(int array[],int n)
{
	for(int i=1;i<=n;i++)
	{
		printf("%d ",array[i-1]);
	}
	putchar('\n');
}

int function(int array[],int n)
{
	int count = 1;
	int tmp = array[0];
	
	for(int i=2;i<=n;i++)
	{
		if(array[i-1] != tmp)
		{
			array[count] = array[i-1];
			count++;
			tmp = array[i-1];
		}
	}
	
	return n - count;
}