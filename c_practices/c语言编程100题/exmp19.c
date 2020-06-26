/*
编写函数fun，该函数的功能是：
从字符串中删除指定的字符。同一字母的大、小写按不同字符处理。
例如：若程序执行时输入字符串为：turbo c and borland c++，从键盘上输入字符n
则输出后变为：turbo c ad borlad c++
如果输入的字符在字符串中不存在，则字符串照原样输出。
*/

#include<stdio.h>

#define MAX_STR_LEN 100

void function(char* ptch,char ch);

int main(void)
{
	char str[MAX_STR_LEN+1] = "turbo c and borland c++";
	char ch;
	
	printf("before string:%s\n",str);
	printf("enter the char:");
	scanf("%c",&ch);
	function(str,ch);
	printf("after string:%s\n",str);
	
	return 0;
}

void function(char* ptch,char ch)
{
	char* ptch_a;
	char *ptch_tmp;
	
	while(*ptch != '\0')
	{
		if(*ptch == ch)
		{
			ptch_a = ptch;
			ptch_tmp = ptch_a + 1;
			while(*ptch_tmp != '\0')
			{
				*ptch_a = *ptch_tmp;
				ptch_a++;
				ptch_tmp++;
			}
			*ptch_a = *ptch_tmp;
		}
		ptch++;
	}
}