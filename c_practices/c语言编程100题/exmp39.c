/*
请编写函数fun，该函数的功能是：
移动一维数组中的内容；若数组中有n个整数
要求把下标从0到p（p小于等于n-1）的数组元素平移到数组的最后
例如，一维数组中的原始内容为：1，2，3，4，5，6，7，8，9，10；p的值为3
移动后，一维数组中的内容应为：5，6，7，8，9，10，1，2，3，4
*/

#include<stdio.h>

void function(int array[],int len,int index);

int main(void)
{
	int array[] = {5,6,7,8,1,2,3,4};
	
	printf("before:");
	for(int i=1;i<=8;i++)
	{
		printf("%d ",array[i-1]);
	}
	printf("\n");
	function(array,8,3);
	for(int i=1;i<=8;i++)
	{
		printf("%d ",array[i-1]);
	}
	printf("\n");
	
	return 0;
}

void function(int array[],int len,int index)
{
	int p,q;
	int tmp;
	
	p = 0;
	q = index+1;
	
	for(int i = 0;i< index + 1;i++)
	{
		tmp = array[p];
		array[p] = array[q];
		array[q] = tmp;
		p++;
		q++;
	}
	//printf("p:%d,q:%d\n",p,q);
	
	while(q < len)
	{
		tmp = array[q];
		for(int i=q;i>p;i--)
		{
			array[i] = array[i-1];
		}
		array[p] = tmp;
		p++;
		q++;
	}
}
