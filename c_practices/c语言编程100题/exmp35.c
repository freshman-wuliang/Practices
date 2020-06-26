/*
请编写一个函数，用来删除字符串中的所有空格。
例如，输入asd af aa z67，则输出为asdafaaz67。
*/

#include<stdio.h>

#define MAX_STR_LEN 50

void function(char *ptstr);

int main(void)
{
	char str[] = "asd af aa z67";
	printf("before:%s\n",str);
	function(str);
	printf("after:%s\n",str);
	
	return 0;
}

void function(char *ptstr)
{
	int index = 0;
	char *p = ptstr;
	
	while(*p)
	{
		if(*p != ' ')
		{
			ptstr[index] = *p;
			index++;
		}
		p++;
	}
	ptstr[index+1] = '\0';
}