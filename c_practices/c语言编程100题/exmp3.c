/*
编写函数void  fun(int x，int pp[]，int *n)
它的功能是：求出能整除x且不是偶数的各整数，并按从小到大的顺序放在pp所指的数组中，
这些除数的个数通过形参n返回。
例如，若x中的值为30，则有4个数符合要求，它们是1，3，5，15。
*/

#include<stdio.h>

#define MAX_NUM 100

void function(int x,int pp[],int* n);

int main(void)
{
	int pp[MAX_NUM];
	int x;
	int n;
	
	printf("enter the x:");
	scanf("%d",&x);
	
	function(x,pp,&n);
	printf("n=%d\n",n);
	for(int i=1;i<=n;i++)
	{
		printf("%d ",pp[i-1]);
	}
	printf("\n");
	
	return 0;
}

void function(int x,int pp[],int* n)
{
	int count = 0;
	
	for(int i=1;i<=x;i++)
	{
		if(x % i == 0 && i % 2 != 0)
		{
			pp[count++] = i;
		}
	}
	*n = count;
}