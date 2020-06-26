/*
请编写函数fun，该函数的功能是：判断字符串是否为回文
若是则函数返回1，主函数中输出YES，否则返回0，主函数中输出NO
回文是指顺读和倒读都一样的字符串
例如，字符串LEVEL是回文，而字符串123312就不是回文
*/

#include<stdio.h>

int function(char *ptstr);

int main(void)
{
	char string1[] = "LEVEL";
	char string2[] = "123312";
	
	printf("string1:%s\n",string1);
	printf("result:");
	if(function(string1))
	{
		printf("YES\n");
	}
	else
	{
		printf("NO\n");
	}
	
	printf("string2:%s\n",string2);
	printf("result:");
	if(function(string2))
	{
		printf("YES\n");
	}
	else
	{
		printf("NO\n");
	}
	
	return 0;
}

int function(char *ptstr)
{
	char *p,*q;
	int flag = 1;
	
	//将q移到最后
	q = ptstr;
	while(*q)
	{
		q++;
	}
	q--;
	
	p = ptstr;
	while(p != q)
	{
		if(*p != *q)
		{
			flag = 0;
			break;
		}
		p++;
		q--;
	}
	
	return flag;
}