#include<stdio.h>

int main(void)
{
	int i,j;
	int array[10]={-1,9,8,7,6,5,4,3,2,1};
	int n = 9;
	
	printf("排序前:\n");
	for(i=1;i<=n;i++)
		printf("%d",array[i]);
	putchar('\n');
	
	for(i=2;i<=n;i++)     //遍历2到n-1的元素
	{
		if(array[i]<array[i-1])   //如果后面比前面小
		{
			array[0]=array[i];    //设置哨兵，保存i个元素的值
			for(j=i-1;array[j]>array[0];j--)    //在前面1到i-1查找插入位置
			{
				array[j+1] = array[j];   //移动位置
			}
			array[j+1] = array[0];   //插入位置
		}
	}
	
	printf("排序后:\n");
	for(i=1;i<=9;i++)
		printf("%d",array[i]);
	putchar('\n');
	
	return 0;
}