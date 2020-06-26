#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include"config.h"
#include<stdlib.h>
#include<stdio.h>

typedef struct
{
	float coef;   //系数
	int expn;     //指数
}data,*pdata;

typedef struct LNode
{
	data da;
	struct LNode *next;
}ListNode,*pListNode;

typedef pListNode Polynomail;

void InitPolyn(Polynomail *pp);

void CreatPolyn(Polynomail p,int num,int array[][2]);

void PrintPolyn(Polynomail p);

void DestroyPolyn(Polynomail *pp);

void ConvertPolyn(Polynomail p);

int PolynLength(Polynomail p);

void AddPolyn(Polynomail *ppa,Polynomail *ppb);

void SubPolyn(Polynomail *ppa,Polynomail *ppb);

#endif
