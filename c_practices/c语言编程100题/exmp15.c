/*
请编写一个函数unsigned fun(unsigned  w)，w是一个大于10的无符号整数
若w是n(n≥2)位的整数，则函数求出w的后n-1位的数作为函数值返回。
例如：w值为5923，则函数返回923；若w值为923，则函数返回23。
*/

#include<stdio.h>

int digitCount(unsigned int w);

int function(unsigned int w);

int main(void)
{
	unsigned int w = 5923;
	
	printf("num:%d\n",w);
	printf("result:%d\n",function(w));
	
	return 0;
}

int digitCount(unsigned int w)
{
	int count = 1;
	
	while(w / 10)
	{
		count++;
		w /= 10;
	}
	
	return count;
}

int function(unsigned int w)
{
	int result = 0;
	int count = 1;
	int digit_count;
	
	digit_count = digitCount(w);
	for(int i=1;i<=digit_count-1;i++)
	{
		result += ((w % 10) * count);
		count *= 10;
		w /= 10;
	}
	
	return result;
}