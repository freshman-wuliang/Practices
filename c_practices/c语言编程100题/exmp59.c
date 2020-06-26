/*
请编写函数fun，该函数的功能是：
将放在字符串数组中的M个字符串（每串的长度不超过N），按顺序合并组成一个新的字符串。
例如，若字符串数组中的M个字符串为：
AAAA
BBBBBBB
CC    
则合并后的字符串的内容应是AAAABBBBBBBCC
*/

#include<stdio.h>

#define N 20
#define M 3

void function(char str[M][N+1],char dest[N*M+1]);

int main(void)
{
	char str[M][N+1] = {"AAAA","BBBBBBB","CC"};
	char dest[M*N+1];
	
	printf("before:\n");
	for(int i=1;i<=M;i++)
	{
		printf("%s\n",str[i-1]);
	}
	
	function(str,dest);
	
	printf("after:");
	printf("%s",dest);
	putchar('\n');
	
	return 0;
}

void function(char str[M][N+1],char dest[N*M+1])
{
	char *p;
	int count = 0;
	
	for(int i=1;i<=M;i++)
	{
		p = str[i-1];
		
		while(*p)
		{
			dest[count++] = *p;
			p++;
		}
	}
	
	dest[count] = '\0';
}