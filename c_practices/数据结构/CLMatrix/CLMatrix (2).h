#ifndef CLMATRIX_H
#define CLMATRIX_H

#include<stdio.h>
#include<stdlib.h>
#include"config.h"

typedef struct M_Node
{
	int r,c;
	int v;
	struct M_Node *down;
	struct M_Node *right;
}M_Node,*pM_Node;

typedef struct
{
	pM_Node *rhead,*chead;
	int row;
	int col;
	int num;
}CLMatrix,*pCLMatrix;

Status CreateCLMatrix(pCLMatrix pM,int row,int col,int num,int array[][3]);

void PrintCLMatrix(CLMatrix M);

#endif
