#include"LinkQueue.h"

Status InitQueue(pQueue pQ)
{
	pQ->front = (pQNode)malloc(sizeof(QNode));
	if(!pQ->front)
		exit(ERROR);

	pQ->rear = pQ->front;
	pQ->front->next = NULL;

	return OK;
}

Status DestroyQueue(pQueue pQ)
{
	pQNode p,q;

	p = pQ->front;
	while(p)
	{
		q = p->next;
		free(p);
		p = q;
	}
	pQ->front = NULL;
	pQ->rear = NULL;

	return OK;
}

Status ClearQueue(pQueue pQ)
{
	pQNode p;

	if(!pQ->front || !pQ->rear)
		return FALSE;
	p = pQ->front->next;
	while(p)
	{
		pQ->front->next = p->next;
		free(p);
		p = pQ->front->next;
	}

	pQ->rear = pQ->front;

	return OK;
}

Status QueueEmpty(Queue Q)
{
	if(!Q.front || !Q.rear)
		exit(ERROR);
	if(Q.front == Q.rear)
		return 1;
	else
		return 0;
}

int QueueLength(Queue Q)
{
	int count = 0;
	pQNode p;

	if(!Q.front || !Q.rear)
		exit(ERROR);

	p = Q.front;
	while(p->next)
	{
		p = p->next;
		count++;
	}

	return count;
}

Status GetHead(Queue Q,int *e)
{
	if(!Q.front || !Q.rear)
		return FALSE;
	if(Q.front == Q.rear)
		return FALSE;

	*e = Q.front->next->data;
	return OK;
}

Status EnQueue(pQueue pQ,int e)
{
	pQNode p;

	if(!pQ->front || !pQ->rear)
		return FALSE;

	p = (pQNode)malloc(sizeof(QNode));
	if(!p)
		exit(OVERFLOW);
	p->data = e;
	p->next = NULL;

	pQ->rear->next = p;
	pQ->rear = p;

	return OK;
}

Status DeQueue(pQueue pQ,int *e)
{
	pQNode p;

	if(!pQ->front || !pQ->rear)
		return FALSE;
	if(pQ->front == pQ->rear)
		return FALSE;

	p = pQ->front->next;
	if(p == pQ->rear)
	{
		pQ->rear = pQ->front;
		*e = p->data;
		free(p);
	}
	else
	{
		pQ->front->next = p->next;
		*e = p->data;
		free(p);
	}

	return OK;
}

void CreatQueue(pQueue pQ,int num,int array[])
{
	InitQueue(pQ);

	for(int i=0;i<num;i++)
		EnQueue(pQ,array[i]);
}

void PrintQueue(Queue Q)
{
	pQNode p;

	if(!Q.front || !Q.rear)
	{
		printf("NULL\n");
		return;
	}
	if(Q.front == Q.rear)
	{
		printf("Empty\n");
		return;
	}

	p = Q.front->next;
	while(p)
	{
		printf(" %d",p->data);
		p = p->next;
	}
	putchar('\n');
}
