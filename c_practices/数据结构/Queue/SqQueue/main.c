#include<stdio.h>
#include"SqQueue.h"

int main(void)
{
	int e;
	int a1[5] = {1,2,3,4,5};
	SqQueue Q;

	CreatQueue(&Q,5,a1);
	PrintQueue(Q);
	PrintAll(Q);
	if(QueueEmpty(Q))
		printf("对空\n");
	else
		printf("对非空\n");
	printf("对长:%d\n",QueueLength(Q));
	printf("将6入对\n");
	EnQueue(&Q,6);
	PrintQueue(Q);
	PrintAll(Q);

	printf("出对\n");
	DeQueue(&Q,&e);
	printf("出对后:\n");
	PrintQueue(Q);
	PrintAll(Q);
	printf("出对元素为:%d\n",e);

	for(int i=7;i<=14;i++)
		EnQueue(&Q,i);

	for(int i=0;i<5;i++)
	{
		DeQueue(&Q,&e);
		printf("出对元素:%d\n",e);
	}
	for(int i=10;i<=15;i++)
		EnQueue(&Q,i);

	printf("对长:%d\n",QueueLength(Q));
	PrintQueue(Q);
	PrintAll(Q);


	DestroyQueue(&Q);

	return 0;
}
