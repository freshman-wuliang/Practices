#include<stdio.h>

int main(void)
{
	int array[10] = {10,9,8,7,6,5,4,3,2,1};
	int n = 10;
	
	printf("排序前:");
	for(int i=1;i<=n;i++)
		printf("%d",array[i-1]);
	putchar('\n');
	
	for(int i=1;i<=n-1;i++)   //共进行n-1趟排序
	{
		int min = i + 1;      //记录最小元素的位置
		for(int j=i+2;j<=n;j++)   //查找i+1到n的最小元素
		{
			if(array[j-1] < array[min-1])   //如果比min小则更新min的值
				min = j;
		}
		
		if(array[min-1] < array[i-1])   //比较i与min的值，若i>min则交换i与min的值
		{
			int t;
			t = array[i-1];
			array[i-1] = array[min-1];
			array[min-1] = t;
		}
	}
	
	printf("排序后:");
	for(int i=1;i<=n;i++)
		printf("%d",array[i-1]);
	putchar('\n');
	
	return 0;
}