/*
请编写函数fun，其功能是：
将两个两位数的正整数a、b合并形成一个整数放在c中
合并的方式是：
将a数的十位和个位数依次放在c数的千位和十位上
b数的十位和个位数依次放在c数的百位和个位上。
例如，当a=45，b=12，调用该函数后，c=4152。
*/

#include<stdio.h>

void function(int a,int b,int *pc);

int main(void)
{
	int a = 45,b = 12,c;
	
	printf("a=%d,b=%d\n",a,b);
	function(a,b,&c);
	printf("c = %d\n",c);
	
	return 0;
}
void function(int a,int b,int *pc)
{
	int m,n;
	int sum = 0;
	
	m = a / 10;
	n = a % 10;
	sum += (m*1000 + n*10);
	m = b /10;
	n = b % 10;
	sum += (m*100 + n);
	
	*pc = sum;
}