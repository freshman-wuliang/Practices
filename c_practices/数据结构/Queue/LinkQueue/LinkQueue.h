#ifndef LINKQUEUE_H
#define LINKQUEUE_H

#include<stdio.h>
#include<stdlib.h>
#include"config.h"

typedef struct QNode
{
	int data;
	struct QNode *next;
}QNode,*pQNode;

typedef struct
{
	pQNode front;
	pQNode rear;
}Queue,*pQueue;

Status InitQueue(pQueue pQ);

Status DestroyQueue(pQueue pQ);

Status ClearQueue(pQueue pQ);

Status QueueEmpty(Queue Q);

int QueueLength(Queue Q);

Status GetHead(Queue Q,int *e);

Status EnQueue(pQueue pQ,int e);

Status DeQueue(pQueue pQ,int *e);

void CreatQueue(pQueue pQ,int num,int array[]);

void PrintQueue(Queue Q);

#endif
