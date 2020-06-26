/*
请编写一个函数void fun(char*ss)，其功能是：
将字符串ss中所有下标为奇数位置上的字母转换为大写(若该位置上不是字母，则不转换)。
例如，若输入abc4EFgh，则应输出aBc4EFgH。
*/

#include<stdio.h>

void function(char *ss);

int main(void)
{
	char str[] = "abc4EFgh";
	
	printf("before:%s\n",str);
	function(str);
	printf("after:%s\n",str);
	
	return 0;
}

void function(char *ss)
{
	int index = 0;
	char *p = ss;
	
	while(*p)
	{
		if(index % 2 != 0)
		{
			if(*p >= 97 && *p <= 122)
			{
				*p = *p - 32;
			}
		}
		index++;
		p++;
	}
}