/*
编写一个函数void fun(int m，int k，int xx[])，该函数的功能是：
将大于整数m且紧靠m的k个素数存入xx所指的数组中。
例如，若输入：17，5，则应输出：19，23，29，31，37。
*/

#include<stdio.h>

#define MAX_NUM 50

int isPrimeNum(int num);

void function(int m,int k,int xx[]);

int main(void)
{
	int m;
	int k;
	int xx[MAX_NUM];
	
	printf("enter the m,k:");
	scanf("%d,%d",&m,&k);
	function(m,k,xx);
	for(int i=1;i<=k;i++)
	{
		printf("%d ",xx[i-1]);
	}
	printf("\n");
	
	return 0;
}

int isPrimeNum(int num)
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

void function(int m,int k,int xx[])
{
	int count = 0;
	
	while(count < k)
	{
		if(isPrimeNum(++m))
		{
			xx[count++] = m;
		}
	}
}