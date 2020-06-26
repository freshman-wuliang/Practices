/*
请编写函数fun，其功能是：
将s所指字符串中ASCII值为偶数的字符删除
串中剩余字符形成一个新串放在t所指的数组中。
例如，若s所指字符串中的内容为ABCDEFGl2345
其中字符B的ASCII码值为偶数、…、字符2的ASCII码值为偶数、…
都应当删除，其他依此类推。最后t所指的数组中的内容应是ACEGl35。
*/

#include<stdio.h>

#define MAX_STR_LEN 20

void function(char s[],char t[]);

int main(void)
{
	char s[MAX_STR_LEN+1] = "ABCDEFG12345";
	char t[MAX_STR_LEN+1];
	
	printf("before:%s\n",s);
	function(s,t);
	printf("after:%s\n",t);
	
	return 0;
}

void function(char s[],char t[])
{
	int count = 0;
	char *p = s;
	
	while(*p)
	{
		if(*p % 2 != 0)
		{
			t[count++] = *p;
		}
		p++;
	}
	t[count] = '\0';
	
}