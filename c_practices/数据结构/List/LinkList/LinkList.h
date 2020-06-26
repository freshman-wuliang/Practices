#ifndef LINKLIST_H
#define LINKLIST_H

#include"config.h"
#include<stdlib.h>
#include<stdio.h>

typedef struct LNode
{
	int data;
	struct LNode *next;
}ListNode,* pListNode;

Status InitLinkList(pListNode *ppHeadNode);

Status DestroyLinkList(pListNode *ppHeadNode);

Status ClearLinkList(pListNode pHeadNode);

Status ListEmpty(pListNode pHeadNode);

Status ListLength(pListNode pHeadNode);

Status GetElem(pListNode pHeadNode,int i,int *e);

Status LocateElem(pListNode pHeadNode,int e);

Status InsertElem(pListNode pHeadNode,int i,int e);

Status DeleteElem(pListNode pHeadNode,int i,int *e);

Status CreatLinkList(pListNode *ppHeadNode,int num,int array[]);

void PrintLinkList(pListNode pHeadNode);

void UnionLinkList(pListNode pHeadNode1,pListNode pHeadNode2,pListNode pHeadNode3);

void MergeLinkList(pListNode *ppHeadNode1,pListNode *ppHeadNode2,pListNode *ppHeadNode3);

#endif
