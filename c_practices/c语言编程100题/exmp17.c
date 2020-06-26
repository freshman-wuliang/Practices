/*
请编一个函数fun(char* s)，该函数的功能是把字符串中的内容逆置。
例如：字符串中原有的字符串为abcdefg，则调用该函数后，串中的内容为gfedcba。
*/

#include<stdio.h>

#define MAX_STR_LEN 50

void function(char* ptc);

int main(void)
{
	char string[MAX_STR_LEN+1] = "abcdefg";
	
	printf("string:%s\n",string);
	function(string);
	printf("result:%s\n",string);
	
	return 0;
}

void function(char* ptc)
{
	char* ptc_a,*ptc_b;  //写成char* ptc_a,ptc_b报错
	char tmp;
	
	ptc_a = ptc;
	ptc_b = ptc;
	
	while((*ptc_b) != '\0')
	{
		ptc_b++;
	}
	ptc_b--;
	
	while(ptc_a != ptc_b)
	{
		tmp = (*ptc_a);
		(*ptc_a) = (*ptc_b);
		(*ptc_b) = tmp;
		ptc_a++;
		ptc_b--;
	}
}