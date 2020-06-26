#include<stdio.h>
#include"SqStack.h"

int main(void)
{
	int a1[3] = {1,2,3};
	SqStack S;
	int e;

	//InitStack(&S);
	CreatStack(&S,3,a1);
	PrintStack(S);
	GetTop(S,&e);
	printf("栈顶元素为:%d\n",e);
	printf("栈长为:%d\n",StackLength(S));
	printf("将4-10依次入栈\n");
	printf("入栈前:\n");
	PrintStack(S);
	for(int i=4;i<=10;i++)
	{
		Push(&S,i);
	}
	printf("入栈后:\n");
	PrintStack(S);
	printf("\n\n将6-10依次出栈\n");
	printf("出栈前:\n");
	PrintStack(S);
	printf("出栈:\n");
	for(int i=6;i<=10;i++)
	{
		Pop(&S,&e);
		printf("出栈元素为:%d\n",e);
	}
	printf("出栈后:\n");
	PrintStack(S);

	printf("\n\n清空栈\n");
	ClearStack(&S);
	if(StackEmpty(S))
		printf("已空\n");
	else
		printf("未清空\n");
	PrintStack(S);

	return 0;
}
