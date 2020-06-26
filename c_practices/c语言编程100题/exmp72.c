/*
请编写函数fun，其功能是：
将s所指字符串中下标为偶数的字符删除，串中剩余字符形成的新串放在t所指数组中。
例如，当s所指字符串中的内容为ABCDEFGHIJK
则在t所指数组中的内容应是，BDFHJ
注意：部分源程序给出如下。
*/

#include<stdio.h>

#define MAX_STR_LEN 20

void function(char s[],char t[]);

int main(void)
{
	char s[MAX_STR_LEN+1] = "ABCDEFGHIJK";
	char t[MAX_STR_LEN+1];
	
	printf("before:%s\n",s);
	function(s,t);
	printf("after:%s\n",t);
	
	return 0;
}

void function(char s[],char t[])
{
	int count = 0;
	int index = 0;
	char *p = s;
	
	while(*p)
	{
		if(index % 2 != 0)
		{
			t[count++] = *p;
		}
		p++;
		index++;
	}
	
	t[count] = '\0';
}