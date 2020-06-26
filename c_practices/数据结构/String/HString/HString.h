#ifndef HSTRING_H
#define HSTRING_H

#include"config.h"
#include<stdlib.h>
#include<stdio.h>
#include<string.h>

typedef struct
{
	char *ch;
	int length;
}HString,*pHString;

Status StrAssign(pHString pH,char array[]);

int StrLength(HString S);

int StrCompare(HString S,HString T);

Status ClearString(pHString pH);

Status ConCat(pHString pH,HString S1,HString S2);

Status SubString(pHString psub,HString S,int pos,int len);

void PrintString(HString S);

#endif
