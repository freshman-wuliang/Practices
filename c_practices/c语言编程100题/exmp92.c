/*
请编写函数fun，它的功能是计算：
s =  (ln(1)+ln(2)+ln(3)+...+ln(m))^0.5，
s作为函数值返回
在C语言中可调用log(n)函数求ln(n)
log函数的引用说明是：double log(double x)
例如，若m的值为20，则fun函数值为6.506583。
*/

#include<stdio.h>
#include<math.h>

double function(int m);

int main(void)
{
	int m;
	
	printf("enter the m:");
	scanf("%d",&m);
	printf("result:%f\n",function(m));
	
	return 0;
}

double function(int m)
{
	double sum = 0.0;
	
	for(int i=1;i<=m;i++)
	{
		sum += log(i);
	}
	
	return sqrt(sum);
}