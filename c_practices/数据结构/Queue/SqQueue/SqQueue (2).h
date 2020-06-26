#ifndef SQQUEUE_H
#define SQQUEUE_H

#define MAXQSIZE 15

#include<stdio.h>
#include<stdlib.h>
#include"config.h"

typedef struct
{
	int *base;
	int front;
	int rear;
}SqQueue,*pSqQueue;

Status InitQueue(pSqQueue pQ);

Status DestroyQueue(pSqQueue pQ);

Status ClearQueue(pSqQueue pQ);

Status QueueEmpty(SqQueue Q);

int QueueLength(SqQueue Q);

Status EnQueue(pSqQueue pQ,int e);

Status DeQueue(pSqQueue pQ,int *e);

void CreatQueue(pSqQueue pQ,int num,int array[]);

void PrintQueue(SqQueue Q);

void PrintAll(SqQueue Q);

#endif
