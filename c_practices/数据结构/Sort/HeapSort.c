#include<stdio.h>

void HeapAdjust(int array[],int low,int high);

void HeapSort(int array[],int n);

int main(void)
{
	int array[10] = {10,9,8,7,6,5,4,3,2,1};
	int n = 10;
	
	printf("排序前:");
	for(int i=1;i<=n;i++)
		printf("%d",array[i-1]);
	putchar('\n');
	
	HeapSort(array,n);
	
	printf("排序后:");
	for(int i=1;i<=n;i++)
		printf("%d",array[i-1]);
	putchar('\n');
	
	return 0;
}

void HeapAdjust(int array[],int low,int high)   //调整堆
{
	int AdjustValue = array[low-1];   //记录调整的值
	int AdjustPos = low;              //记录调整的位置
	
	for(int i = 2*low;i <= high;i *= 2)   //从大的结点向下调整
	{
		if(i<high && array[i-1]<array[i+1-1])
			i++;                           //找出左右子树的最大值
		if(array[i-1] > AdjustValue)         //调整值比子树小,改变调整位置
		{
			array[AdjustPos-1] = array[i-1];
			AdjustPos = i;
		}
	}
	array[AdjustPos-1] = AdjustValue;    //插入调整值
}

void HeapSort(int array[],int n)       //堆排序
{
	for(int i=n/2;i>=1;i--)            //建大顶堆
		HeapAdjust(array,i,n);
		
	for(int i=n;i>=2;i--)
	{
		int t;
		t = array[1-1];
		array[1-1] = array[i-1];
		array[i-1] = t;         //交换堆顶与最后一个元素
		
		HeapAdjust(array,1,i-1);         //调整从1到i-1的元素
	}
}