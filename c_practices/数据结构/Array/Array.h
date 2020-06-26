#ifndef ARRAY_H
#define ARRAY_H

#include"config.h"
#include<stdarg.h>
#include<stdlib.h>
#include<stdio.h>

#define MAX_ARRAY_DIM 5

typedef struct
{
	int *base;
	int dim;
	int *bounds;
	int *constants;
}Array,*pArray;

Status InitArray(pArray pA,int dim,...);

Status DestroyArray(pArray pA);

static Status Locate(Array A,va_list ap,int *off);

Status Value(Array A,int *e,...);

Status Assign(Array A,int e,...);

void PrintArray(Array A);

#endif
