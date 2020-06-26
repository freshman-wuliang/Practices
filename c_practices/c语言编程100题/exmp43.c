/*
编写一个函数，从传入的num个字符串中找出最长的一个字符串
并通过形参指针max传回该串地址(用****作为结束输入的标志)。
*/

#include<stdio.h>

#define MAX_STR_LEN 50

int mstrlen(char *ptstr);

void function(char str[][MAX_STR_LEN],int n,char **pmax);

int main(void)
{
	char str[4][MAX_STR_LEN] = {"abc","abcd","abcde","abcdef"};
	char * max;
	
	for(int i=1;i<=4;i++)
	{
		printf("string%d:%s\n",i,str[i-1]);
	}
	function(str,4,&max);
	printf("max string:%s\n",max);
	
	return 0;
}

int mstrlen(char *ptstr)
{
	int count = 0;
	
	while(*ptstr)
	{
		count++;
		ptstr++;
	}
	
	return count;
}

void function(char str[][MAX_STR_LEN],int n,char* *pptc)
{
	int max_len;
	int index;
	
	index = 0;
	max_len = mstrlen(str[0]);
	for(int i=1;i<=n;i++)
	{
		if(mstrlen(str[i-1]) > max_len)
		{
			max_len = mstrlen(str[i-1]);
			index = i-1;
		}
	}
	*pptc = str[index];
}