#ifndef STACK_H
#define STACK_H

#include"Config.h"
#include<stdlib.h>
#include<stdio.h>

void initStack(Stack *ps);

void destroyStack(Stack *ps);

void clearStack(Stack *ps);

int emptyStack(Stack s);

int StackSize(Stack s);

StackElemType getTop(Stack s);

void pushStack(Stack *ps,StackElemType elem);

StackElemType popStack(Stack *ps);

//assist function
#define ALL 0
#define PART 1

void createStack(Stack *ps,StackElemType array[],int n);

void displayStack(Stack s,int flag);

#endif