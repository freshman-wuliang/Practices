/*
假定输入的字符串中只包含字母和*号。
请编写函数fun，它的功能是：
使字符串的前导*号不得多于n个；若多于n个，则删除多余的*号
若少于或等手n个，则什么也不做
字符串中间和尾部的*号不删除。
例如，若字符串中的内容为*******A*BC*DEF*G****，假设n的值为4
删除后，字符串中的内容则应当是****A*BC*DEF*G****
若n的值为8，则字符串中的内容仍为*******A*BC*DEF*G****
n的值在主函数中输入。
在编写函数时，不得使用C语言提供的字符串函数。
*/

#include<stdio.h>

#define MAX_STR_LEN 25

void function(char str[],int n);

int main(void)
{
	char str[MAX_STR_LEN+1] = "*******A*BC*DEF*G****";
	
	printf("before:%s\n",str);
	function(str,8);
	printf("after:%s\n",str);
	
	return 0;
}

void function(char str[],int n)
{
	char *p = str;
	int count = 0;
	int index = 0;
	
	while(*p == '*')
	{
		p++;
		count++;
	}
	
	if(count <= n)
	{
		p = str;
		while(*p)
		{
			str[index++] = *p;
			p++;
		}
	}
	else
	{
		for(int i=1;i<=n;i++)
		{
			str[index++] = str[i-1];
		}
		
		while(*p)
		{
			str[index++] = *p;
			p++;
		}
	}
	
	str[index] = '\0';
}