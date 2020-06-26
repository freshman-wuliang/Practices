/*
编写函数int fun(int lim，int aa[MAX])
该函数的功能是求出小于或等于lim的所有素数并放在aa数组中，
该函数返回所求出的素数的个数。
*/

#include<stdio.h>

#define MAX 1000 //程序处理1000以内的数

int function(int lim,int aa[MAX]);

int isPrime(int num);

int main(void)
{
	int aa[MAX];
	int lim;
	int count;
	
	//printf("%d\n",isPrime(9));
	printf("enter the lim:");
	scanf("%d",&lim);
	count = function(lim,aa);
	printf("count:%d\n",count);
	printf("result:");
	for(int i=1;i<=count;i++)
	{
		printf("%d ",aa[i-1]);
	}
	printf("\n");
	
	return 0;
}

int function(int lim,int aa[MAX])
{
	int count = 0;
	
	for(int i=1;i<=lim;i++)
	{
		if(isPrime(i))
		{
			aa[count] = i;
			count++;
		}
	}
	
	return count;
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