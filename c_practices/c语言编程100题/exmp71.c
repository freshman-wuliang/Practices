/*
请编写函数fun，其功能是：
将两个两位数的正整数a、b合并形成一个整数放在c中
合并的方式是：将a数的十位和个位数依次放在c数的十位和千位上
b数的十位和个位数依次放在c数的百位和个位上。
例如，当a=45，b=12，调用该函数后，c=5142。
*/

#include<stdio.h>

int function(int a,int b);

int main(void)
{
	int a = 45,b = 12;
	int c;
	
	c = function(a,b);
	printf("result:%d\n",c);
	
	return 0;
}

int function(int a,int b)
{
	int sum = 0;
	
	sum += (a / 10) * 10;
	sum += (a % 10) * 1000;
	sum += (b / 10) * 100;
	sum += (b % 10);
	
	return sum;
}