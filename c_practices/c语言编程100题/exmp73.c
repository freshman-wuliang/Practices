/*
假定输入的字符串中只包含字母和*号
请编写函数fun，它的功能是：
除了字符串前导和尾部的*号之外，将串中其他*号全部删除
形参h已指向字符串中第—个字母，形参p已指向字符串中最后一个字母。
在编写函数时，不得使用C语言提供的字符串函数。
例如，若字符串中的内容为****A*BC*DEF*G********
删除后，字符串中的内容则应当是****ABCDEFG********
*/

#include<stdio.h>

#define MAX_STR_LEN 50

void function(char str[],char *h,char *p);

int main(void)
{
	char str[MAX_STR_LEN+1] = "****A*BC*DEF*G********";
	char *h = &str[0];
	char *p = str;
	
	while(*p)
	{
		p++;
	}
	p--;

	printf("before:%s\n",str);
	function(str,h,p);
	printf("after:%s\n",str);
	
	return 0;
}

void function(char str[],char *h,char *p)
{
	char *m = h;
	char *n = p;
	int count = 0;
	
	while(*m == '*')
	{
		m++;
	}
	
	while(*n == '*')
	{
		n--;
	}
	
	for(char *i = h;i < m;i++)
		str[count++] = *i;
	
	for(char *i = m;i <= n;i++)
	{
		if(*i != '*')
		{
			str[count++] = *i;
		}
	}
	
	for(char *i = n+1;i <= p;i++)
		str[count++] = *i;
	
	str[count] = '\0';
}