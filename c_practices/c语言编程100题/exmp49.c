/*
请编写函数fun，其功能是：
将s所指字符串中下标为偶数同时ASCII值为奇数的字符删除
s中剩余的字符形成的新串放在t所指的数组中。
例如，若s所指字符串中的内容为ABCDEFGl2345
其中字符C的ASCII码值为奇数，在数组中的下标为偶数，因此必须删除
而字符1的ASCII码值为奇数，在数组中的下标也为奇数，因此不应当删除
其他依此类推。最后t所指的数组中的内容应是BDFl2345。
*/

#include<stdio.h>

void function(char *ptstr);

int main(void)
{
	char str[] = "ABCDEFGl2345";
	
	printf("before:%s\n",str);
	function(str);
	printf("after:%s\n",str);
	
	return 0;
}

void function(char *ptstr)
{
	char *p = ptstr;
	int index = 0;
	int count = 0;
	
	while(*p)
	{
		if(index % 2 == 0 && *p % 2 != 0)
		{
			;
		}
		else
		{
			ptstr[count++] = *p;
		}
		p++;
		index++;
	}
	ptstr[count] = '\0';
}