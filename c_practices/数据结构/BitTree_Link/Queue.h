#ifndef QUEUE_H
#define QUEUE_H

#include"Config.h"
#include<stdlib.h>
#include<stdio.h>

void initQueue(Queue *pq);

void destroyQueue(Queue *pq);

void clearQueue(Queue *pq);

int emptyQueue(Queue q);

int QueueLength(Queue q);

QueueElemType getHead(Queue q);

void enQueue(Queue *pq,QueueElemType elem);

QueueElemType deQueue(Queue *pq);

//assist function
void createQueue(Queue *pq,QueueElemType array[],int n);

void displayQueue(Queue q);

#endif