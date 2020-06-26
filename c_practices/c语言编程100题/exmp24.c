/*
请编写一个函数fun，
它的功能是：将一个数字字符串转换为一个整数(不得调用C语言提供的将字符串转换为整数的函数)。
例如，若输入字符串“-1234”，则函数把它转换为整数值-1234
*/

#include<stdio.h>

int isPosNum(char *ptstr);

int strLength(char *ptstr);

int constrNum(int n);

int function(char *ptstr);

int main(void)
{
	char string1[] = "1234";
	char string2[] = "-4567";
	
	printf("string1:%s\n",string1);
	printf("result:%d\n",function(string1));
	printf("string2:%s\n",string2);
	printf("result:%d\n",function(string2));
	
	return 0;
}

int isPosNum(char *ptstr)
{
	char *p;
	
	p = ptstr;
	
	return *p == '-'? 0 : 1;
}

int strLength(char *ptstr)
{
	int count = 0;
	char *p = ptstr;;
	
	if(*p == '-')
	{
		p++;
	}
	
	while(*p)
	{
		count++;
		p++;
	}
	
	return count;
}

int constrNum(int n)
{
	int sum = 1;
	
	for(int i=1;i<=n;i++)
	{
		sum *= 10;
	}
	
	return sum;
}

int function(char *ptstr)
{
	int sum = 0;
	int num_digit;
	char *p;
	
	p = ptstr;
	num_digit = strLength(p);
	//printf("num_digit:%d\n",num_digit);
	
	if(*p == '-')
	{
		p++;
	}
	
	for(int i=num_digit;i>=1;i--)
	{
		switch (*p)
		{
			case '1' : sum += 1 * constrNum(i-1);break;
			case '2' : sum += 2 * constrNum(i-1);break;
			case '3' : sum += 3 * constrNum(i-1);break;
			case '4' : sum += 4 * constrNum(i-1);break;
			case '5' : sum += 5 * constrNum(i-1);break;
			case '6' : sum += 6 * constrNum(i-1);break;
			case '7' : sum += 7 * constrNum(i-1);break;
			case '8' : sum += 8 * constrNum(i-1);break;
			case '9' : sum += 9 * constrNum(i-1);break;
			default : break;
		}
		p++;
	}
	
	if(isPosNum(ptstr))
	{
		return sum;
	}
	else
	{
		return sum * (-1);
	}
}