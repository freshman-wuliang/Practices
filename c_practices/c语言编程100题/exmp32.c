/*
请编写函数fun，其功能是：
将s所指字符串中除了下标为奇数、同时ASCII值也为奇数的字符之外，其余的所有字符都删除，
串中剩余字符所形成的一个新串放在t所指的数组中。
例如，若s所指字符串中的内容为ABCDEFGl2345，
其中字符A的ASCII码值虽为奇数，但所在元素的下标为偶数，因此必需删除；
而字符1的ASCII码值为奇数，所在数组中的下标也为奇数，因此不应当删除，
其他依此类推。最后t所指的数组中的内容应是135
*/

#include<stdio.h>

#define MAX_STR_LEN 50

void function(char *ptstr1,char *ptstr2);

int main(void)
{
	char str1[] = "ABCDEFG12345";
	char str2[MAX_STR_LEN+1];
	
	printf("string1:%s\n",str1);
	function(str1,str2);
	printf("string2:%s\n",str2);
	
	return 0;
}

void function(char *ptstr1,char *ptstr2)
{
	int index = 0;
	int count = 0;
	
	while(*ptstr1)
	{
		if(index % 2 != 0 && *ptstr1 % 2 != 0)
		{
			ptstr2[count] = *ptstr1;
			count++;
		}
		index++;
		ptstr1++;
	}
}

