/*
假定输入的字符串中只包含字母和*号。请编写函数fun
它的功能是：只删除字符串前导和尾部的*号，串中字母之间的*号都不删除。
形参n给出了字符串的长度，形参h给出了字符串中前导*号的个数，形参e给出了字符串中最后*号的个数
在编写函数时，不得使用C语言提供的字符串函数。
例如，若字符串中的内容为****A*BC*DEF*G*******，删除后，字符串中的内容则应当是A*BC*DEF*G。
*/

#include<stdio.h>

void function(char *str,int n,int h,int e);

int main(void)
{
	char str[] = "****A*BC*DEF*G*******";
	
	printf("before:%s\n",str);
	function(str,21,4,7);
	printf("after:%s\n",str);
	
	return 0;
}

void function(char *str,int n,int h,int e)
{
	char *p;
	int index = 0;
	
	for(p = str + h;p <= str + (n-e-1);p++)
	{
		str[index++] = *p;
	}
	str[index] = '\0';
}