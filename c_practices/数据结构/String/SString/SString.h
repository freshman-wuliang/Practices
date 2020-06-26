#ifndef SSTRING_H
#define SSTRING_H

#define MAXSTRLEN 255

#include<string.h>
#include<stdio.h>
#include"config.h"

typedef unsigned char SString[MAXSTRLEN+1];

void StrAssign(SString T,char array[]);

void StrCopy(SString T,SString S);

int StrEmpty(SString T);

int StrCompare(SString S,SString T);

int StrLength(SString S);

void ConCat(SString T,SString S1,SString S2);

void ClearString(SString S);

Status SubString(SString Sub,SString S,int pos,int len);

int Index(SString S,SString T);

int Index_B(SString S,SString T,int pos);

Status StrInsert(SString S,int pos,SString T);

Status StrDelete(SString S,int pos,int len);

Status Replace(SString S,SString T,SString V);

void PrintString(SString S);

#endif
