#include<stdio.h>
#include<stdlib.h>
#include"config.h"

typedef int ElemType;

typedef struct DListNode
{
	ElemType data;
	struct DListNode *next;
}DListNode,*pDListNode;

typedef pDListNode DLinkList;

Status InitList(DLinkList *pL);   //初始化

int main(void)
{
	return 0;
}