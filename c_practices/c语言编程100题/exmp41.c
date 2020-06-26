/*
请编写函数fun，该函数的功能是：
将M行N列的二维数组中的字符数据，按列的顺序依次放在一个字符串中。
例如，若二维数组中的数据为：
|W W W W|
|S S S S|
|H H H H| 
则字符串中的内容应是WSHWSHWSHWSH
*/

#include<stdio.h>
#include<string.h>

#define M 3
#define N 4
#define MAX_STR_LEN 50

void printMatrix(char cMatrix[M][N],int row,int col);

void function(char cMatrix[M][N],char *ptstr);

int main(void)
{
	char cMatrix[M][N] = {{'W','W','W','W'},{'S','S','S','S'},{'H','H','H','H'}};
	char str[MAX_STR_LEN+1];
	
	printf("Matrix:\n");
	printMatrix(cMatrix,M,N);
	function(cMatrix,str);
	printf("string:%s\n",str);
	
	return 0;
}

void printMatrix(char cMatrix[M][N],int row,int col)
{
	for(int i=1;i<=row;i++)
	{
		printf("| ");
		for(int j=1;j<=col;j++)
		{
			printf("%c ",cMatrix[i-1][j-1]);
		}
		printf("|\n");
	}
}

void function(char cMatrix[M][N],char *ptstr)
{
	int count = 0;
	
	for(int i=1;i<=N;i++)
	{
		for(int j=1;j<=M;j++)
		{
			ptstr[count++] = cMatrix[j-1][i-1];
		}
	}
	ptstr[count] = '\0';
}