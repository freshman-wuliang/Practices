/*
请编写一个函数fun，它的功能是：比较两个字符串的长度
(不得调用C语言提供的求字符串长度的函数)
函数返回较长的字符串。若两个字符串长度相同，则返回第一个字符串。
例如，输入：beijing shanghai<CR>(<CR>为回车键)，函数将返回shanghai。
*/

#include<stdio.h>

#define MAX_STR_LEN 50

int strLen(char *ptstr);

char *function(char *ptstr1,char *ptstr2);

int main(void)
{
	char str1[MAX_STR_LEN];
	char str2[MAX_STR_LEN];
	char *p;
	
	//printf("%d\n",strLen(str1));
	printf("enter two string:");
	scanf("%s%s",str1,str2);
	p = function(str1,str2);
	printf("the longer string is:%s\n",p);
	//printf("%s,%s",str1,str2);
	
	return 0;
}

int strLen(char *ptstr)
{
	char *p = ptstr;
	int count = 0;
	
	while(*p)
	{
		count++;
		p++;
	}
	
	return count;
}

char *function(char *ptstr1,char *ptstr2)
{
	return (strLen(ptstr1) >= strLen(ptstr2))? ptstr1:ptstr2;
}