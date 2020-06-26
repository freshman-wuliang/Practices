#include<stdio.h>
#include"HString.h"

int main(void)
{
	char a1[6] = "abcde";
	char a2[6] = "12345";
	char a3[10] = "abcdefgh";
	HString S,T,A;

	StrAssign(&S,a1);
	StrAssign(&T,a2);
	PrintString(S);
	PrintString(T);
	printf("串长:%d\n",StrLength(S));
	printf("串长:%d\n",StrLength(T));
	ConCat(&A,S,T);
	PrintString(A);
	printf("串长:%d\n",StrLength(A));

	ClearString(&S);
	ClearString(&T);
	StrAssign(&S,a3);
	printf("\n\n");
	PrintString(S);
	SubString(&T,S,2,3);
	PrintString(T);



	return 0;
}

