#ifndef CLINKLIST_H
#define CLINKLIST_H

#include"config.h"
#include<stdlib.h>
#include<stdio.h>

typedef struct CLNode
{
	int data;
	struct CLNode *next;
}CListNode,*pCListNode;

void InitCList(pCListNode *ppHeadNode);

void DestroyCList(pCListNode *ppHeadNode);

void ClearCList(pCListNode pHeadNode);

int CListEmpty(pCListNode pHeadNode);

Status GetElem(pCListNode pHeadNode,int i,int *e);

Status LocateElem(pCListNode pHeadNode,int e);

Status InsertElem(pCListNode pHeadNode,int i,int e);

Status DeleteElem(pCListNode pHeadNode,int i,int *e);

void CreatCList(pCListNode *ppHeadNode,int num,int array[]);

void PrintCList(pCListNode pHeadNode);

#endif
