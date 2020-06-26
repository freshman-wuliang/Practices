/*
请编写函数fun，它的功能是：
求出1到1000之内能被7或11整除、但不能同时被7和11整除的所有整数
并将它们放在a所指的数组中，通过n返回这些数的个数。
*/

#include<stdio.h>

#define LOW 1
#define UP 1000
#define MAX_SIZE 1000

int function(int number[]);

int main(void)
{
	int number[MAX_SIZE];
	int n;
	
	n = function(number);
	printf("num:%d\n",n);
	for(int i=1;i<=n;i++)
	{
		printf("%d\n",number[i-1]);
	}
	
	return 0;
}

int function(int number[])
{
	int count = 0;
	
	for(int i=LOW;i<=UP;i++)
	{
		if (i%7 == 0 || i%11 == 0)
		{
			if(((i%7 == 0)&&(i%11 != 0)) || ((i%7 !=0)&&(i%11 == 0)))
			{
				number[count++] = i;
			}
		}
	}
	
	return count;
}