#include<stdio.h>
#include"LinkStack.h"


Status Convert(int num,pStack pS);

int main(void)
{
	Stack S;
	int num;

	InitStack(&S);
	printf("输入一个十进制数\n");
	scanf("%d",&num);
	Convert(num,&S);
	PrintStack(S);

	return 0;
}

Status Convert(int num,pStack pS)
{
	while(num)
	{
		Push(pS,num%2);
		num = num/2;
	}
}
