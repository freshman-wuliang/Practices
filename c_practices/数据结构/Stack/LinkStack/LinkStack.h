#ifndef LINKSTACK_H
#define LINKSTACK_H

#include<stdio.h>
#include"config.h"
#include<stdlib.h>

typedef struct SNode
{
	int data;
	struct SNode *next;
}SNode,*pSNode;

typedef struct 
{
	pSNode top;
	pSNode base;
}Stack,*pStack;

Status InitStack(pStack pS);

Status DestroyStack(pStack pS);

Status ClearStack(pStack pS);

Status  StackEmpty(Stack S);

int StackLength(Stack S);

Status GetTop(Stack S,int *e);

Status Push(pStack pS,int e);

Status Pop(pStack pS,int *e);

void CreatStack(pStack pS,int num,int array[]);

void PrintStack(Stack S);

#endif
