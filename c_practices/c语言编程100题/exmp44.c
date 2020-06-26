/*
编写一个函数，该函数可以统计一个长度为2的字符串在另一个字符串中出现的次数。
例如，假定输入的字符串为：asd asasdfg asd as zx67 asd mklo，子字符串为as，则应输出6。
*/

#include<stdio.h>


int function(char *pmain_str,char *pmode_str);

int main(void)
{
	char mnstr[] = "asd asasdfg asd as zx67 asd mklo";
	char mdstr[] = "as";
	
	printf("main string:%s\n",mnstr);
	printf("mode string:%s\n",mdstr);
	printf("count:%d\n",function(mnstr,mdstr));
	
	return 0;
}

int function(char *pmain_str,char *pmode_str)
{
	char *p = pmain_str;
	char *q = pmode_str;
	int count = 0;
	
	if((*q) == '\0')
		return -1;
	
	while(*p)
	{
		if(*p == *q)
		{
			p++;
			q++;
		}
		else
		{
			p++;
		}
		
		if(*q == '\0')
		{
			count++;
			q = pmode_str;
		}
	}
	
	return count;
}