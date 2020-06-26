#include<stdio.h>
#include"Queue.h"

int main(void)
{
	Queue q;
	Queue_ElemType array[6] = {1,2,3,4,5,6};
	
	initQueue(&q);
	//printf("empty:%d\n",emptyQueue(q));
	//printf("length:%d\n",QueueLength(q));
	//displayQueue(q);
	createQueue(&q,array,6);
	displayQueue(q);
	enQueue(&q,7);
	displayQueue(q);
	printf("deElem:%d\n",deQueue(&q));
	displayQueue(q);
	//printf("head:%d\n",getHead(q));
	//printf("length:%d\n",QueueLength(q));
	//printf("empty:%d\n",emptyQueue(q));
	destroyQueue(&q);
	//printf("length:%d\n",QueueLength(q));
	//displayQueue(q);
	//printf("empty:%d\n",emptyQueue(q));
}