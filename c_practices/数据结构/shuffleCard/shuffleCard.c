/*
洗牌算法
*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int generateRand(int lower,int upper);   //产生lower-upper之间的随机数

int shuffle(int array[],int n);   //将一个序列变成一个随机序列

void printArray(int array[],int n);

void initArray(int array[],int n);

int main(void)
{
	int array[10] = {1,2,3,4,5,6,7,8,9,10};
	
	for(int i=1;i<=10;i++)
	{
		printf("%d shuffle:\n",i);
		initArray(array,10);
		printf("before:");
		printArray(array,10);
		shuffle(array,10);
		printf("after:");
		printArray(array,10);
		putchar('\n');
	}
	
	return 0;
}

int generateRand(int lower,int upper)
{
	static unsigned int seed_add;
	
	srand((unsigned int)time(NULL) + seed_add);
	
	seed_add++;
	
	return (rand() % (upper - lower + 1)) + lower;
}

int shuffle(int array[],int n)
{
	for(int i=n;i>=2;i--)
	{
		int index = generateRand(1,i-1);
		int tmp = array[index-1];
		array[index-1] = array[i-1];
		array[i-1] = tmp;
	}
}

void printArray(int array[],int n)
{
	for(int i=1;i<=n;i++)
	{
		printf("%d ",array[i-1]);
	}
	putchar('\n');
}

void initArray(int array[],int n)
{
	for(int i=1;i<=n;i++)
	{
		array[i-1] = i;
	}
}