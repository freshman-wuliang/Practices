#ifndef TRIPLET_H
#define TRIPLET_H

#include"config.h"
#include<stdio.h>

typedef struct   //定义三元组的类型
{
	int v1;
	int v2;
	int v3;
}Triplet,*pTriplet;

Status InitTriplet(pTriplet pt,int v1,int v2,int v3);

//Status DestroyTriplet(pTriplet pt);

Status Get(Triplet t,int i,int *e);

Status Put(pTriplet pt,int i,int e);

Status IsAscending(Triplet t);

Status IsDescending(Triplet t);

Status Max(Triplet t,int *e);

Status Min(Triplet t,int *e);

void PrintTriplet(Triplet t);

#endif
