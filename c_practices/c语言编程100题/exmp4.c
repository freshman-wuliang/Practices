/*
编写一个函数void fun(char *tt，int pp[])
统计在tt字符串中“a”到“z”26个字母各自出现的次数，并依次放在pp所指数组中。
例如，当输入字符串abcdefgabcdeabc后，程序的输出结果应该是：
3 3 3 2 2 1 1 0 0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
*/

#include<stdio.h>

#define CHAR_NUM 26
#define MAX_NUM 100

void function(char* tt,int pp[]);

int main(void)
{
	char input[MAX_NUM+1] = "abcdefgabcdeabc";
	int pp[CHAR_NUM];
	
	function(input,pp);
	for(int i=1;i<=CHAR_NUM;i++)
	{
		printf("%d ",pp[i-1]);
	}
	printf("\n");
	
	return 0;
}

void function(char* tt,int pp[])
{
	char* ptc;
	
	for(int i=1;i<=CHAR_NUM;i++)
	{
		pp[i-1] = 0;
	}
	
	ptc = tt;
	while(*ptc != '\0')
	{
		switch (*ptc)
		{
			case 'a' : pp[0]++;break;
			case 'b' : pp[1]++;break;
			case 'c' : pp[2]++;break;
			case 'd' : pp[3]++;break;
			case 'e' : pp[4]++;break;
			case 'f' : pp[5]++;break;
			case 'g' : pp[6]++;break;
			case 'h' : pp[7]++;break;
			case 'i' : pp[8]++;break;
			case 'j' : pp[9]++;break;
			case 'k' : pp[10]++;break;
			case 'l' : pp[11]++;break;
			case 'm' : pp[12]++;break;
			case 'n' : pp[13]++;break;
			case 'o' : pp[14]++;break;
			case 'p' : pp[15]++;break;
			case 'q' : pp[16]++;break;
			case 'r' : pp[17]++;break;
			case 's' : pp[18]++;break;
			case 't' : pp[19]++;break;
			case 'u' : pp[20]++;break;
			case 'v' : pp[21]++;break;
			case 'w' : pp[22]++;break;
			case 'x' : pp[23]++;break;
			case 'y' : pp[24]++;break;
			case 'z' : pp[25]++;break;
			default : return;
		}
		ptc++;
	}
}