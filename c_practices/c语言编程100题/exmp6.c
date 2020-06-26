/*
请编写一个函数void fun(char a[]，char b[]，int n)，其功能是：
删除一个字符串中指定下标的字符。其中，a指向原字符串，
删除后的字符串存放在b所指的数组中，n中存放指定的下标。
例如，输入一个字符串World，然后输入3，则调用该函数后的结果为Word。
*/

#include<stdio.h>

#define MAX_STR_LEN 50

void function(char a[],char b[],int n);

int main(void)
{
	char a[] = "world";
	char b[MAX_STR_LEN];
	
	function(a,b,0);
	printf("%s\n",b);
	
	return 0;
}

void function(char a[],char b[],int n)
{
	char* ptc;
	int count = 0;
	int i;
	
	ptc = a;
	i = 0;
	while(*ptc != '\0')
	{
		if(i != n)
		{
			b[count] = a[i];
			i++;
			count++;
		}
		else
		{
			i++;
		}
		ptc++;
	}
	b[count+1] = '\0';
}