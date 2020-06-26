#ifndef SQSTACK_H
#define SQSTACK_H

#define STACK_INIT_SIZE 50
#define STACK_INCREMENT 10

#include"config.h"
#include<stdlib.h>
#include<stdio.h>

typedef struct
{
	int *base;
	int *top;
	int StackSize;
	int flag;
}SqStack,*pSqStack;

Status InitStack(pSqStack pS);

Status DestroyStack(pSqStack pS);

Status ClearStack(pSqStack pS);

Status StackEmpty(SqStack S);

int StackLength(SqStack S);

Status GetTop(SqStack S,int *e);

Status Push(pSqStack pS,int e);

Status Pop(pSqStack,int *e);

void CreatStack(pSqStack pS,int num,int array[]);

void PrintStack(SqStack S);

#endif
