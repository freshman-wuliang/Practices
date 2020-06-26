/*
假定输入的字符串中只包含字母和*号。请编写函数fun，它的功能是：
使字符串中尾部的*号不得多于n个；若多于n个，则删除多余的*号；
若少于或等于n个，则什么也不做，字符串中间和前面的*号不删除。
例如，字符串中的内容为****A*BC*DEF*G*******
若n的值为4，删除后，字符串中的内容则应当是****A*BC*DEF*G****
若n的值为7，则字符串中的内容仍为  ****A*BC*DEF*G*******
n的值在主函数中输入。在编写函数时，不得使用C语言提供的字符串函数。
*/

#include<stdio.h>

#define MAX_STR_LEN 50

void function(char *ptstr,int n);

int main(void)
{
	char str1[] = "****A*BC*DEF*G*******";
	char str2[] = "****A*BC*DEF*G*******";
	int n;
	
	printf("enter the n:");
	scanf("%d",&n);
	printf("before:%s\n",str1);
	function(str1,n);
	printf("after:%s\n",str1);
	
	return 0;
}

void function(char *ptstr,int n)
{
	char *p;
	int count = 0;
	
	p = ptstr;
	while(*p)
	{
		p++;
	}
	p--;
	
	while(*p == '*')
	{
		count++;
		p--;
	}
	//printf("count:%d\nn:%d\n",count,n);
	
	if(count > n)
	{
		for(int i=1;i<=n;i++)
		{
			p++;
		}
		*(++p) = '\0';
	}
}