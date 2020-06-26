/*
请编写函数fun，其功能是：
将s所指字符串中ASCII值为奇数的字符删除
串中剩余字符形成一个新串放在t所指的数组中。
例如，若s所指字符串中的内容为ABCDEFGl2345
其中字符A的ASCII码值为奇数
字符1的ASCII码值也为奇数
都应当删除，其他依次类推
最后t所指的数组中的内容应是BDF24。
*/

#include<stdio.h>

#define MAX_STR_LEN 50

void function(char *ps,char *pt);

int main(void)
{
	char s[MAX_STR_LEN+1] = "ABCDEFG12345";
	char t[MAX_STR_LEN+1];
	
	printf("string:%s\n",s);
	function(s,t);
	printf("result:%s\n",t);
	
	return 0;
}

void function(char *ps,char *pt)
{
	char *p = ps;
	int count = 0;
	
	while(*p)
	{
		if(*p % 2 == 0)
		{
			pt[count++] = *p;
		}
		p++;
	}
	pt[count] = '\0';
	
}