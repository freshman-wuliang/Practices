#ifndef MATRIX_H
#define MATRIX_H

#define MAXSIZE 12500

#include<stdio.h>
#include"config.h"

typedef struct 
{
	int m;   //行标
	int n;   //列标
	int e;   //值
}Triple,*pTriple;

typedef struct
{
	Triple data[MAXSIZE+1];
	int num;
	int row;
	int col;
}SMatrix,*pSMatrix;

Status CreateSMatrix(pSMatrix pM,int row,int col,int num,int array[][3]);

void PrintSMatrix(SMatrix M);

void CopySMatrix(SMatrix M,pSMatrix pT);

Status AddSMatrix(SMatrix A,SMatrix B,pSMatrix pC);

Status SubsMatrix(SMatrix A,SMatrix B,pSMatrix pC);

Status TransSMatrix(SMatrix A,pSMatrix pT);

#endif
