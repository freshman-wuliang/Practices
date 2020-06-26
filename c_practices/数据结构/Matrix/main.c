#include<stdio.h>
#include"Matrix.h"

int main(void)
{
	SMatrix M,T,A,B,S;
	int row = 3;
	int col = 4;
	int num = 3;
	int array[3][3] = {{1,1,3},{2,3,1},{3,4,2}};
	int array1[3][3] = {{1,1,2},{2,3,4},{3,3,1}};
	int array2[3][3] = {{1,2,3},{2,3,1},{3,4,2}};

	/*
	CreateSMatrix(&M,row,col,num,array);
	PrintSMatrix(M);
	CopySMatrix(M,&T);
	putchar('\n');
	PrintSMatrix(T);
	*/

	/*
	CreateSMatrix(&A,row,col,num,array1);
	CreateSMatrix(&B,row,col,num,array2);
	putchar('\n');
	PrintSMatrix(A);
	putchar('\n');
	PrintSMatrix(B);
	AddSMatrix(A,B,&S);
	putchar('\n');
	PrintSMatrix(S);
	*/

	//
	CreateSMatrix(&M,row,col,num,array);
	PrintSMatrix(M);
	TransSMatrix(M,&T);
	putchar('\n');
	PrintSMatrix(T);

	//
	CreateSMatrix(&A,row,col,num,array1);
	CreateSMatrix(&B,row,col,num,array2);
	putchar('\n');
	PrintSMatrix(A);
	putchar('\n');
	PrintSMatrix(B);
	SubSMatrix(A,B,&S);
	putchar('\n');
	PrintSMatrix(S);

	return 0;
}
