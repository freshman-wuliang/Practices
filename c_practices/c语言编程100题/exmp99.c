/*
请编写函数fun，其功能是：
计算并输出3到n之间所有素数的平方根之和。
例如，若主函数从键盘给n输入100后，则输出为sum＝148.874270
注意：n的值要求大于2但不大于100
*/

#include<stdio.h>
#include<math.h>

double function(int n);

//assist function
int isPrime(int n);

int main(void)
{
	int n;
	
	printf("enter the n:");
	scanf("%d",&n);
	printf("result:%lf\n",function(n));
	
	return 0;
}

int isPrime(int n)
{
	int flag = 1;
	
	for(int i=2;i<=n-1;i++)
	{
		if(n % i == 0)
		{
			flag = 0;
			break;
		}
	}
	
	return flag;
}

double function(int n)
{
	double sum = 0.0;
	
	for(int i=3;i<=n;i++)
	{
		if(isPrime(i))
		{
			sum += sqrt(i);
		}
	}
	
	return sum;
}