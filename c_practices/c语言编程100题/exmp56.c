/*
假定输入的字符串中只包含字母和*号
请编写函数fun，它的功能是；
除了尾部的*号之外，将字符串中其他*号全部删除
形参p已指向字符串中最后的一个字母。
在编写函数时，不得使用C语言提供的字符串函数。
例如，若字符串中的内容为****A*BC*DEF*G*******
删除后，字符串中的则内容应当是ABCDEFG*******
*/

#include<stdio.h>

#define MAX_STR_LEN 50

void function(char *ptstr,char *p);

int main(void)
{
	char *p;
	char str[MAX_STR_LEN+1] = "****A*BC*DEF*G*******";
	
	p = str;
	while(*p)
	{
		p++;
	}
	p--;
	
	//printf("*p=%c",*p);
	
	printf("before:%s\n",str);
	function(str,p);
	printf("after:%s\n",str);
	
	return 0;
}

void function(char *ptstr,char *p)
{
	char *q = ptstr;
	char *m = p;
	int count = 0;
	
	while(*m == '*')
	{
		m--;
	}
	//printf("*m = %c\n",*m);
	
	while(q < m)
	{
		if(*q != '*')
		{
			ptstr[count++] = *q;
		}
		q++;
	}
	
	while(*m)
	{
		ptstr[count++] = *m;
		m++;
	}
	
	ptstr[count] = *m;
}