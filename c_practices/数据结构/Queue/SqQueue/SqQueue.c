#include"SqQueue.h"

Status InitQueue(pSqQueue pQ)
{
	pQ->base = (int*)malloc(MAXQSIZE*sizeof(int));
	if(!pQ->base)
		exit(OVERFLOW);

	pQ->front = 0;
	pQ->rear = 0;
	for(int i=0;i<MAXQSIZE;i++)
		pQ->base[i] = 0;

	return OK;
}

Status DestroyQueue(pSqQueue pQ)
{
	if(!pQ->base)
		return FALSE;
	free(pQ->base);
	pQ->base = NULL;
	return OK;
}

Status ClearQueue(pSqQueue pQ)
{
	if(!pQ->base)
		return FALSE;

	pQ->front = 0;
	pQ->rear = 0;

	return OK;
}

Status QueueEmpty(SqQueue Q)
{
	if(!Q.base)
		exit(ERROR);
	if(Q.front == Q.rear)
		return 1;
	else
		return 0;
}

int QueueLength(SqQueue Q)
{
	if(!Q.base)
		exit(ERROR);

	return (Q.rear+MAXQSIZE-Q.front)%MAXQSIZE;
}

Status EnQueue(pSqQueue pQ,int e)
{
	if(!pQ->base)
		return FALSE;
	if((pQ->rear+1)%MAXQSIZE == pQ->front)
		return FALSE;

	pQ->base[pQ->rear] = e;
	pQ->rear = (pQ->rear+1)%MAXQSIZE;

	return OK;
}

Status DeQueue(pSqQueue pQ,int *e)
{
	if(!pQ->base)
		return FALSE;
	if(pQ->front == pQ->rear)
		return FALSE;

	*e = pQ->base[pQ->front];
	pQ->base[pQ->front] = 0;   //PrintAll
	pQ->front = (pQ->front+1)%MAXQSIZE;

	return OK;
}

void CreatQueue(pSqQueue pQ,int num,int array[])
{
	InitQueue(pQ);

	for(int i=0;i<num;i++)
		EnQueue(pQ,array[i]);
}

void PrintQueue(SqQueue Q)
{
	int p;

	if(!Q.base)
	{
		printf("NULL\n");
		return;
	}
	if(Q.front == Q.rear)
	{
		printf("Empty\n");
		return;
	}

	p = Q.front;
	while(p != Q.rear)
	{
		printf(" %d",Q.base[p]);
		p = (p+1)%MAXQSIZE;
	}
	putchar('\n');
}

void PrintAll(SqQueue Q)
{
	if(!Q.base)
	{
		printf("NULL\n");
		return;
	}
	if(Q.front == Q.rear)
	{
		printf("Empty\n");
		return;
	}

	for(int i=0;i<MAXQSIZE;i++)
		printf(" %d",Q.base[i]);
	putchar('\n');
}
