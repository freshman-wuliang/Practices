/*
编写一个函数int fun(int*s，int t，int *k)，用来求出数组的最大元素在数组中的下标并存放在k所指的存储单元中。
例如，输入如下整数：876  675  896  10l  30l  40l  980  43l  451  777 ，则输出结果为：6，980。
*/

#include<stdio.h>

int function(int* ptis,int t,int* ptin);

int main(void)
{
	int s[] = {876,675,896,101,301,401,980,431,451,777};
	int t = 10;
	int k;
	int n;
	
	n = function(s,t,&k);
	printf("%d,%d\n",n,k);
	v 
	return 0;
}

int function(int* ptis,int t,int* ptin)
{
	int flag = 0;
	int result;
	
	result = ptis[0];
	for(int i=2;i<=t;i++)
	{
		if(ptis[i-1] > result)
		{
			result = ptis[i-1];
			flag = i - 1;
		}
	}
	
	*ptin = result;
	
	return flag;
}