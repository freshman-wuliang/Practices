#include"Queue.h"

void initQueue(Queue *pq)
{
	pq->front = (QueueNode*)malloc(sizeof(QueueNode));
	if(!pq->front)
	{
		printf("memory full\n");
		exit(1);
	}
	
	pq->front->next = NULL;
	pq->rear = pq->front;
}

void destroyQueue(Queue *pq)
{
	if(!pq->front && !pq->rear)
		return;
	
	if(!pq->front->next)
	{
		free(pq->front);
		pq->front = NULL;
		pq->rear = NULL;
		return;
	}
	
	QueueNode *p,*q;
	
	p = pq->front->next;
	q = p->next;
	while(q)
	{
		free(p);
		p = q;
		q = q->next;
	}
	free(p);
	free(pq->front);
	pq->front = NULL;
	pq->rear = NULL;
}

void clearQueue(Queue *pq)
{
	if(!pq->front && !pq->rear)
		return;
	
	if(!pq->front->next)
		return;
	
	QueueNode *p,*q;
	
	p = pq->front;
	q = p->next;
	while(q)
	{
		free(p);
		p = q;
		q = q->next;
	}
	free(p);
	pq->rear = pq->front;
	pq->front->next = NULL;
}

int emptyQueue(Queue q)
{
	if(!q.front && !q.rear)
		return -1;
	
	if(q.front->next == NULL)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int QueueLength(Queue q)
{
	if(!q.front && !q.rear)
		return -1;
	
	QueueNode *p = q.front->next;
	int count = 0;
	
	while(p)
	{
		count++;
		p = p->next;
	}
	
	return count;
}

QueueElemType getHead(Queue q)
{
	if(!q.front && !q.rear)
		exit(1);
	
	if(q.front->next == NULL)
	{
		return q.front->data;
	}
	else
	{
		return q.front->next->data;
	}
}

void enQueue(Queue *pq,QueueElemType elem)
{
	if(!pq->front && !pq->rear)
		return;
	
	QueueNode *p;
	p = (QueueNode*)malloc(sizeof(QueueNode));
	if(!p)
	{
		printf("memory full\n");
		exit(1);
	}
	
	p->data = elem;
	p->next = NULL;
	pq->rear->next = p;
	pq->rear = p;
}

QueueElemType deQueue(Queue *pq)
{
	QueueElemType elem;
	
	if(!pq->front && !pq->rear)
		exit(1);
	
	if(!pq->front->next)
		return pq->front->data;
	
	QueueNode *p = pq->front->next;
	elem = p->data;
	if(p->next != NULL)
	{
		pq->front->next = p->next;
		free(p);
	}
	else
	{
		free(p);
		pq->rear = pq->front;
		pq->front->next = NULL;
	}
	
	return elem;
}

//assist function
void createQueue(Queue *pq,QueueElemType array[],int n)
{
	for(int i=1;i<=n;i++)
	{
		enQueue(pq,array[i-1]);
	}
}

void displayQueue(Queue q)
{
	printf("Queue:");
	if(emptyQueue(q) == -1)
	{
		printf("destroyed\n");
	}
	else if(emptyQueue(q) == 1)
	{
		printf("empty\n");
	}
	else
	{
		QueueNode *p = q.front->next;
		
		while(p)
		{
			printf("0x%p ",p->data);
			p = p->next;
		}
		putchar('\n');
	}
}