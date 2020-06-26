/*
请编写函数fun，其功能是：
将所有大于1小于整数m的非素数存入xx所指数组中
非素数的个数通过k传回。
例如，若输入17，则应输出：9和4 6 8 9 10 12 14 15 16。
*/

#include<stdio.h>

#define MAX_NUM 500

int isPrime(int num);

int function(int m,int xx[]);

int main(void)
{
	int xx[MAX_NUM];
	int count;
	
	count = function(17,xx);
	printf("count:%d\n",count);
	printf("result:");
	for(int i=1;i<=count;i++)
	{
		printf("%d ",xx[i-1]);
	}
	putchar('\n');
	
	return 0;
}

int isPrime(int num)
{
	int flag = 1;
	
	for(int i=2;i<=num-1;i++)
	{
		if(num % i == 0)
		{
			flag = 0;
			break;
		}
	}
	
	return flag;
}

int function(int m,int xx[])
{
	int count = 0;
	
	for(int i=2;i<=m-1;i++)
	{
		if(!isPrime(i))
		{
			xx[count++] = i;
		}
	}
	
	return count;
}