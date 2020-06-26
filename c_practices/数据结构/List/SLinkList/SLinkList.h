#ifndef SLINKLIST_H
#define SLINKLIST_H

#include"config.h"
#include<stdlib.h>
#include<stdio.h>

#define MAXSIZE 100

typedef struct
{
	int data;
	int cur;
}component,SLinkList[MAXSIZE];

void InitSList(SLinkList SL);

void DestroySList(SLinkList SL);

int Malloc(SLinkList SL);

void Free(SLinkList SL,int cur);

Status ClearSList(SLinkList SL);

Status SListEmpty(SLinkList SL);

int SListLength(SLinkList SL);

Status GetElem(SLinkList SL,int i,int *e);

Status InsertElem(SLinkList SL,int i,int e);

Status DeleteElem(SLinkList SL,int i,int *e);

Status CreatSList(SLinkList SL,int num,int array[]);

void PrintSList(SLinkList SL);

#endif
