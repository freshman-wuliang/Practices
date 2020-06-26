#ifndef SQLIST_H
#define SQLIST_H

#include<stdlib.h>
#include<stdio.h>
#include"config.h"

#define LIST_INIT_SIZE 10
#define LISTINCREMENT 10

typedef struct
{
	int * elem;
	int length;
	int listsize;
}SqList,* pSqList;

Status InitSqList(pSqList pL);   //初始化一个顺序表

Status DestroySqList(pSqList pL);   //销毁一个顺序表

Status ClearSqList(pSqList pL);   //清空一个顺序表

Status SqListEmpty(SqList L);   //顺序表判空

Status SqListLength(SqList L);   //顺序表的长度

Status GetElem(SqList L,int i,int *e);   //获取元素

int LocateElem(SqList L,int e);   //定位元素

Status PriorElem(SqList L,int e,int *pre_e);   //求前驱

Status NextElem(SqList L,int e,int *next_e);   //求后继

Status InsertElem(pSqList pL,int i,int e);   //插入元素

Status DeleteElem(pSqList pL,int i,int *e);   //删除元素

Status CreatSqList(pSqList pL,int length,int array[]);//创建顺序表

void PrintSqList(SqList L);   //打印顺序表

void UnionSqList(pSqList pL1,SqList L2);   //求并集

void MergeSqList(SqList L1,SqList L2,pSqList pL3);   //合并两个表


#endif
