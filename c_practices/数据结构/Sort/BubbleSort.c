#include<stdio.h>

int main(void)
{
	int array[10]={10,9,8,7,6,5,4,3,2,1};
	int n = 10;
	
	printf("排序前:");
	for(int i=1;i<=n;i++)
		printf("%d",array[i-1]);
	putchar('\n');
	
	for(int i=1;i<=n-1;i++)   //共n-1趟冒泡
	{
		int flag = 0;   //标志变量
		for(int j=1;j<=n-i;j++)   //一趟冒泡排序
		{
			if(array[j-1]>array[j+1-1])
			{
				int t = array[j-1];
				array[j-1] = array[j+1-1];
				array[j+1-1] = t;
				flag = 1;
			}
		}
		
		if(flag = 0)   //若一趟排序未发生交换则直接退出排序
			break;
	}
	
	printf("排序后:");
	for(int i=1;i<=n;i++)
		printf("%d",array[i-1]);
	putchar('\n');
	
	return 0;
}