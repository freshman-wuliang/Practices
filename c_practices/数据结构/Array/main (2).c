#include<stdio.h>
#include"Array.h"

int main(void)
{
	Array A;
	int count = 1;
	int e;

	InitArray(&A,2,2,2);
	
	for(int i=0;i<2;i++)
	{
		for(int j=0;j<2;j++)
		{
			Assign(A,count,i,j);
			count++;
		}
	}

	PrintArray(A);
	Value(A,&e,0,1);
	printf("A[0][1] = %d\n",e);
	DestroyArray(&A);

	return 0;
}
