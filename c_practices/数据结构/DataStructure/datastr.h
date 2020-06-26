/*
*author:wuliang
*start date:2020-03-11
*finish date: xxx
*/

//notes:before you use the libary,please define the elemtype.otherwise,compiler will report an error
//for example,using 'typedef (type) seqlist_elem' to define the element of sequential list.

#ifndef DATASTR_H
#define DATASTR_H

#include<stdlib.h>
#include<stdio.h>

typedef enum
{
	false = 0,
	true = 1
}bool;          //定义bool类型



/*[1].linear list*/

/****************list begin****************/

/*[1.1].sequential list*/
//seqlist begin

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

//seqlist end

/*[1.2].Single LinkList*/

//SLinkList begin

typedef int SLListType;

typedef struct Node
{
	SLListType elem;
	struct Node *next;
}LinkNode,*PLinkNode;

typedef PLinkNode SLinkList;

void initSLinkList(SLinkList *ptlist);

void destroySLinkList(SLinkList *ptlist);

void creatSLinkList(SLinkList list,int list_len,SLListType elem[]);

void printSLinkList(SLinkList list);

void clearSLinkList(SLinkList list);

int SLinkListLength(SLinkList list);

//SLinkList end

/****************list end*****************/
#endif