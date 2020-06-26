/*
请编写函数fun，它的功能是：求出ss所指字符串中指定字符的个数，并返回此值。
例如，若输入字符串123412132，输入字符1，则输出3。
*/

#include<stdio.h>

#define MAX_STR_LEN 50

int function(char *ptstr,char ch);

int main(void)
{
	char str[] = "123412132";
	int count;
	
	printf("string:%s\n",str);
	count = function(str,'1');
	printf("'%c':%d\n",'1',count);
	
	return 0;
}

int function(char *ptstr,char ch)
{
	int count = 0;
	char *p = ptstr;
	
	while(*p)
	{
		if(*p == ch)
		{
			count++;
		}
		p++;
	}
	
	return count;
}