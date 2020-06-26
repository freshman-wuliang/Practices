/*
假定输入的字符串中只包含字母和*号。请编写函数fun
它的功能是：删除字符串中所有的*号
在编写函数时，不得使用C语言提供的字符串函数。
例如，若字符串中的内容为****A*BC*DEF*G*******
删除后，字符串中的内容则应当是ABCDEFG。
*/

#include<stdio.h>

void function(char *str);

int main(void)
{
	char string[] = "****A*BC*DEF*G*******";
	
	printf("before:%s\n",string);
	function(string);
	printf("after:%s\n",string);
	
	return 0;
}

void function(char *str)
{
	char *p = str;
	int count = 0;
	
	while(*p)
	{
		if(*p != '*')
		{
			str[count++] = *p;
		}
		p++;
	}
	
	str[count] = '\0';
}