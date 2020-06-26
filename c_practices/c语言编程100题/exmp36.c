/*
假定输入的字符串中只包含字母和*号。请编写函数fun
它的功能是：将字符串中的前导*号全部移到字符串的尾部。
例如，字符串中的内容为*******A*BC*DEF*G****
移动后，字符串中的内容应当是A*BC*DEF*G***********
在编写函数时，不得使用C语言提供的字符串函数
*/

#include<stdio.h>

#define MAX_STR_LEN 50

void function(char *ptstr);

int main(void)
{
	char str[] = "*******A*BC*DEF*G****";
	
	printf("before:%s\n",str);
	function(str);
	printf("after:%s\n",str);
	
	return 0;
}

void function(char *ptstr)
{
	int ch_num = 0;
	int index = 0;
	char *p = ptstr;
	
	//统计'*'的数量，并且推指针
	while(*p == '*')
	{
		ch_num++;
		p++;
	}
	
	//printf("ch_num:%d\n*p:%c\n",ch_num,*p);
	while(*p)
	{
		ptstr[index] = *p;
		index++;
		p++;
	}
	//printf("str:%s\n",ptstr);
	
	p = ptstr + index;
	for(int i=1;i<=ch_num;i++)
	{
		*p = '*';
		p++;
	}
	*(++p) = '\0';
	
}