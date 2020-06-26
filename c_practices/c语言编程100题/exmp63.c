/*
请编写一个函数fun，它的功能是：计算并输出给定整数n的所有因子(不包括1与自身)之和。规定n的值不大于1000。备注：整数n的因子－n可以整除的数。
例如，若主函数从键盘给n输入的值为856，则输出为sum=763。
*/

#include<stdio.h>

int function(int num);

int main(void)
{
	int n;
	
	printf("enter the num:");
	scanf("%d",&n);
	printf("result:%d\n",function(n));
	
	return 0;
}

int function(int num)
{
	int sum = 0;
	
	for(int i=2;i<=num-1;i++)
	{
		if(num % i == 0)
		{
			sum += i;
		}
	}
	
	return sum;
}