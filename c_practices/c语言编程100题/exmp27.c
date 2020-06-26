/*
请编写一个函数fun，它的功能是：
求出1到m之内(含m)能被7或11整除的所有整数放在数组a中，通过n返回这些数的个数。
例如，若传送给m的值为50，则程序输出：
    7    11    14    21    22    28    33    35    42    44    49
*/

#include<stdio.h>

#define MAX_NUM  100

int function(int m,int array[MAX_NUM]);

int main(void)
{
	int array[MAX_NUM];
	int count;
	int num;
	
	printf("enter a number:");
	scanf("%d",&num);
	count = function(num,array);
	printf("count:%d\n",count);
	for(int i=1;i<=count;i++)
	{
		printf("%d ",array[i-1]);
	}
	putchar('\n');
	
	return 0;
}

int function(int m,int array[MAX_NUM])
{
	int count = 0;
	
	for(int i=1;i<=m;i++)
	{
		if(i % 7 == 0 || i % 11 == 0)
		{
			array[count] = i;
			count++;
		}
	}
	
	return count;
}