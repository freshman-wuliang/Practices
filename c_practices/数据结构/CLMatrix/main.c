#include<stdio.h>
#include"CLMatrix.h"

int main(void)
{
	CLMatrix M;
	int row = 3;
	int col = 4;
	int num = 4;
	int array[4][3] = {{1,1,2},{1,3,4},{2,2,3},{3,3,1}};
	
	CreateCLMatrix(&M,row,col,num,array);
	PrintCLMatrix(M);
	
	return 0;
}
