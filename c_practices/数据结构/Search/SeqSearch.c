#include<stdio.h>

typedef int ElemPos;

ElemPos SeqSearch(int array[],int n,int key);

int main(void)
{
	int array[11] = {0,2,5,1,4,3,6,10,8,9,7};
	int n = 10;
	
	printf("待查数组:");
	for(int i=1;i<=n;i++)
		printf(" %d",array[i]);
	putchar('\n');
	
	printf("待查数据:%d\n",5);
	
	printf("查找结果:");
	printf("%d\n",SeqSearch(array,n,5));
	
	return 0;
	
}

ElemPos SeqSearch(int array[],int n,int key)
{
	array[0] = key;   //设置哨兵
	
	int i = n;
	while(key != array[i])
		i--;
	
	if(0 == i)
		return -1;
	else
		return i;
}