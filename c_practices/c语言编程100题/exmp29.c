/*
请编写一个函数fun，它的功能是：
将ss所指字符串中所有下标为奇数位置上的字母转换为大写(若该位置上不是字母，则不转换)
例如，若输入abc4EFg，则应输出aBc4EFg。
ascii码值：
A~Z(65~90),a~z(97~122),0~9(48~57)
*/

#include<stdio.h>

void function(char *ss);

int main(void)
{
	char ss[] = "abc4EFg";
	
	printf("before string:%s\n",ss);
	function(ss);
	printf("after string:%s\n",ss);
	
	return 0;
}

void function(char *ss)
{
	char *p = ss;
	int index = 0;
	
	while(*p)
	{
		if(index % 2 != 0)
		{
			if(*p >= 97 && *p <= 122)
			{
				*p -= 32;
			}
		}
		index++;
		p++;
	}
}