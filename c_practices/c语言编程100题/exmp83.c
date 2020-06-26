/*
假定输入的字符串中只包含字母和*号
请编写函数fun，它的功能是：
将字符串尾部的*号全部删除，前面和中间的*号不删除。
例如，若字符串中的内容为****A*BC*DEF*G*******
删除后，字符串中的内容则应当是****A*BC*DEF*G
在编写函数时，不得使用C语言提供的字符串函数。
*/

#include<stdio.h>

#define MAX_STR_LEN 30

void function(char str[]);

int main(void)
{
	char str[MAX_STR_LEN+1] = "****A*BC*DEF*G*******";
	
	printf("before:%s\n",str);
	function(str);
	printf("after:%s\n",str);
	
	return 0;
}

void function(char str[])
{
	int count = 0;
	char *p = str;
	char *q = str;
	
	while(*q)
	{
		q++;
	}
	q--;
	
	while(*q == '*')
	{
		q--;
	}
	
	while(p <= q)
	{
		str[count++] = *p;
		p++;
	}
	
	str[count] = '\0';
}