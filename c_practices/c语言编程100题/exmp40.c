/*
请编写函数fun，该函数的功能是：
移动字符串中的内容，移动的规则如下：
把第1到第m个字符，平移到字符串的最后
把第m+l到最后的字符移到字符串的前部。
例如，字符串中原有的内容为ABCDEFGHIJK，m的值为3
移动后，字符串中的内容应该是DEFGHIJKABC。
*/

#include<stdio.h>

#define MAX_STR_LEN 50

void function(char *ptstr,int index);

int main(void)
{
	char string[] = "ABCDEFGHIJK";
	
	printf("before:%s\n",string);
	function(string,3);
	printf("after:%s\n",string);
	
	return 0;
}

void function(char *ptstr,int index)
{
	char *p,*q;
	char tmp;
	
	//将q移到最后一个元素的位置
	q = ptstr;
	while(*q)
	{
		q++;
	}
	q--;
	
	//printf("q:%c\n",*q);
	for(int i=1;i<=index;i++)
	{
		tmp = *ptstr;
		p = ptstr + 1;
		while(p <= q)
		{
			*(p-1) = *(p);
			p++;
		}
		*q = tmp;
		//printf("str:%s\n",ptstr);
	}
}