/*
请编写函数fun，该函数的功能是：
统计一行字符串中单词的个数，作为函数值返回
一行字符串在主函数中输入，规定所有单词由小写字母组成
单词之间由若干个空格隔开，一行的开始没有空格
*/

#include<stdio.h>

int function(char sentence[]);

int main(void)
{
	char sentence[] = "nice to meet you! my name is wuliang.";
	int n;
	
	printf("sentence:%s\n",sentence);
	n = function(sentence);
	printf("word:%d\n",n);
	
	return 0;
}

int function(char sentence[])
{
	int count = 0;
	char *p = sentence;
	
	while(*p)
	{
		if((*p == ' ' && *(p+1) != ' ') || (*p != ' ' && *(p+1) == ' '))
		{
			count++;
		}
		p++;
	}
	
	return count / 2 + 1;
}