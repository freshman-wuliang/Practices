#ifndef QUEUE_H
#define QUEUE_H

#include<stdlib.h>
#include<stdio.h>

typedef int Queue_ElemType;

typedef struct Node
{
	Queue_ElemType data;
	struct Node *next;
}QueueNode,*PQueueNode;

typedef struct
{
	QueueNode *front;
	QueueNode *rear;
}Queue,*PQueue;

void initQueue(Queue *pq);

void destroyQueue(Queue *pq);

void clearQueue(Queue *pq);

int emptyQueue(Queue q);

int QueueLength(Queue q);

Queue_ElemType getHead(Queue q);

void enQueue(Queue *pq,Queue_ElemType elem);

Queue_ElemType deQueue(Queue *pq);

//assist function
void createQueue(Queue *pq,Queue_ElemType array[],int n);

void displayQueue(Queue q);

#endif