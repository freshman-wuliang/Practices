#ifndef SEQLIST_H
#define SEQLIST_H

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