/*
编写一个函数fun，它的功能是：
实现两个字符串的连接（不使用库函数strcat），即把p2所指的字符串连接到p1所指的字符串后。
例如，分别输入下面两个字符串：  
FirStString--
SecondString
则程序输出：FirstString--SecondString
*/

#include<stdio.h>

#define MAX_STR_LEN 50

void function(char *dest,char *src);

int main(void)
{
	char dest[MAX_STR_LEN+1] = "FirStString--";
	char src[MAX_STR_LEN+1] = "SecondString";
	
	printf("string1:%s\n",dest);
	printf("string2:%s\n",src);
	function(dest,src);
	printf("link:%s\n",dest);
	
	return 0;
}

void function(char *dest,char *src)
{
	char *p,*q;
	
	p = dest;
	q = src;
	
	while(*p)
	{
		p++;
	}
	
	while(*q)
	{
		*p = *q;
		p++;
		q++;
	}
	*p = *q;
}