#ifndef ULINKLIST_H
#define ULINKLIST_H

#include"config.h"
#include<stdlib.h>
#include<stdio.h>

typedef struct LNode
{
	int data;
	struct LNode *next;
}ListNode,*pListNode,*Position;

typedef struct
{
	ListNode head;
	ListNode tail;
	int len;
}LinkList,*pLinkList;

Status MakeNode(pListNode *ppNode,int e);

Status FreeNode(pListNode *ppNode);

Status InitList(pLinkList pList);

Status DestroyList(pLinkList pList);

Status ClearList(pLinkList pList);

Status InsFirst(pLinkList,pListNode s);

Status DelFirst(pLinkList pList);

Status Append(pLinkList pList,pListNode s);

Status Remove(pLinkList pList);

Status InsBefore(pLinkList pList,pListNode p,pListNode s);

Status InsAfter(pLinkList pList,pListNode p,pListNode s);

Status SetCurElem(pListNode p,int e);

int GetCurElem(pListNode p);

Status ListEmpty(pLinkList pList);

Position GetHead(pLinkList pList);

Position GetLast(pLinkList pList);

Position PriorPos(pLinkList pList,pListNode p);

Position NextPos(pLinkList pList,pListNode p);

Status LocatePos(pLinkList pList,int i,pListNode *ppNode);

Position LocateElem(pLinkList pList,int e);

Status InsertElem(pLinkList pList,int i,int e);

void CreatUList(pLinkList pList,int num,int array[]);

void PrintUList(pLinkList pList);

/**********/
Status AscendUList(pLinkList pList);   //升序排列

Status ChangeOrd(pLinkList pList,pListNode p,pListNode q);   //交换相邻的两个节点

#endif
