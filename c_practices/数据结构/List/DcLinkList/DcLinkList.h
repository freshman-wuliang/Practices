#ifndef DCLINKLIST_H
#define DCLINKLIST_H


#include<stdlib.h>
#include<stdio.h>
#include"config.h"

typedef struct DcLNode
{
	struct DcLNode *prior;
	int data;
	struct DcLNode *next;
}DcLNode,*pDcLNode;

void InitDcList(pDcLNode *ppHeadNode);

Status DestroyDcList(pDcLNode *ppHeadNode);

Status ClearDcList(pDcLNode pHeadNode);

Status DcListEmpty(pDcLNode pHeadNode);

Status GetElem(pDcLNode pHeadNode,int i,int *e);

Status LocateElem(pDcLNode pHeadNode,int e);

Status InsertElem(pDcLNode pHeadNode,int i,int e);

Status DeleteElem(pDcLNode pHeadNode,int i,int *e);

Status CreatDcList(pDcLNode pHeadNode,int num,int array[]);

void PrintDcList(pDcLNode pHeadNode);

#endif
