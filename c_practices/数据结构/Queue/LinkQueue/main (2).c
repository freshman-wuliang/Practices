#include<stdio.h>
#include"LinkQueue.h"

int main(void)
{
	Queue Q;
	int a1[5] = {1,2,3,4,5};
	int e;

	CreatQueue(&Q,5,a1);
	PrintQueue(Q);
	printf("对长:%d\n",QueueLength(Q));
	GetHead(Q,&e);
	printf("对头元素:%d\n",e);
	printf("\n将0入对\n");
	printf("入队前\n");
	PrintQueue(Q);
	EnQueue(&Q,0);
	printf("入队后\n");
	PrintQueue(Q);

	printf("\n出对\n");
	printf("出队前\n");
	PrintQueue(Q);
	DeQueue(&Q,&e);
	printf("出队后\n");
	PrintQueue(Q);
	printf("出对元素:%d\n",e);

	DestroyQueue(&Q);

	return 0;
}
