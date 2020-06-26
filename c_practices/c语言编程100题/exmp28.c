/*
请编写一个函数fun，它的功能是：
找出一维整型数组元素中最大的值和它所在的下标，最大的值和它所在的下标通过形参传回。
数组元素中的值已在主函数中赋予。
主函数中x是数组名，n是x中的数据个数，max存放最大值，index存放最大值所在元素的下标。
*/

#include<stdio.h>

#define MAX_NUM 50

void function(int x[],int n,int *max,int *index);

int main(void)
{
	int x[10] = {2,9,8,11,16,24,6,4,1,22};
	int n = 10;
	int max;
	int index;
	
	printf("array:");
	for(int i=1;i<=10;i++)
	{
		printf("%d ",x[i-1]);
	}
	printf("\n");
	function(x,n,&max,&index);
	printf("max:%d\nindex:%d\n",max,index);
	
	return 0;
}

void function(int x[],int n,int *max,int *index)
{
	*max = x[0];
	
	for(int i=1;i<=n;i++)
	{
		if(x[i-1] > *max)
		{
			*max = x[i-1];
			*index = i;
		}
	}
}