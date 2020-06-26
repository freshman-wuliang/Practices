#include<stdio.h>
#include"SString.h"

int main(void)
{
	SString S,S1,S2,T;
	char a[10] = "abcdabfg";
	char a1[5] = "0123";
	char a2[6] = "bf";
	char a3[6] = "xyz";
	char a4[6] = "abca";

	/*StrAssign(S,a);
	PrintString(S);
	printf("串长为:%d\n",StrLength(S));
	StrAssign(S1,a1);
	StrAssign(S2,a2);
	PrintString(S1);
	PrintString(S2);
	printf("\nconcat:\n");
	ConCat(T,S1,S2);
	PrintString(T);
	printf("\ncompare:\n");
	ClearString(S1);
	ClearString(S2);
	StrAssign(S1,a3);
	StrAssign(S2,a4);
	PrintString(S1);
	PrintString(S2);
	printf("result:%d\n",StrCompare(S1,S2));*/
	//StrInsert
	/*StrAssign(S,a);
	StrAssign(T,a1);
	PrintString(S);
	PrintString(T);
	printf("insert:\n");
	StrInsert(S,5,T);
	PrintString(S);*/

	//Index
	StrAssign(S,a);
	StrAssign(T,a2);
	PrintString(S);
	PrintString(T);
	printf("index:\n");
	printf("%d\n",Index_B(S,T,1));

	//StrDelete
	/*StrAssign(S,a);
	PrintString(S);
	printf("Delete:\n");
	StrDelete(S,2,3);
	PrintString(S);*/

	//Replace
	/*StrAssign(S,a);
	StrAssign(S1,a2);
	StrAssign(T,a3);
	PrintString(S);
	PrintString(S1);
	PrintString(T);
	printf("replace:\n");
	Replace(S,S1,T);
	PrintString(S);*/

	return 0;
}
