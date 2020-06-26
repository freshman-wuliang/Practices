/*
请编写函数fun，其功能是:
计算并输出下列多项式值：
Sn= (1-1/2) + (1/3-1/4)+...+(1/2n-1-1/2n)
例如，若主函数从键盘给n输入8后，则输出为S=0.662872。
*/

#include<stdio.h>

double function(int n);

int main(void)
{
	int n;
	
	printf("enter the n:");
	scanf("%d",&n);
	printf("result:%f\n",function(n));
	
	return 0;
}

double function(int n)
{
	double sum = 0.0;
	
	for(int i=1;i<=n;i++)
	{
		sum += (1.0/(2.0 * i - 1.0) - 1.0/(2.0 * i));
	}
	
	return sum;
}