#ifndef SEQLIST_H
#define SEQLIST_H

#include<stdlib.h>
#include<stdio.h>

typedef enum
{
	false = 0,
	true = 1
}bool;          //定义bool类型

typedef int SListType;

typedef struct
{
	SListType *ptelem;
	int length;
}SeqList,*PSeqList;

void initSeqList(SeqList *ptlist);

void destroySeqList(SeqList *ptlist);

void creatSeqList(SeqList *ptlist,SListType elem[],int list_len);

void printSeqList(SeqList list);

void clearSeqList(SeqList *ptlist);

int seqListLength(SeqList list);

int seqListEmpty(SeqList list);

void insertSeqList(SeqList *ptlist,int index,SListType elem);

SListType deleteSeqList(SeqList *ptlist,int index);

#endif