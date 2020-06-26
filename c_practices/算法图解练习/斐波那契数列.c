#include<stdio.h>

int factorial(int n);

int main(void)
{
	printf("factorial(6):%d\n",factorial(6));
	return 0;
}

int factorial(int n)
{
	if(n == 1 || n == 2)
		return 1;
	
	return factorial(n-1) + factorial(n-2);
}