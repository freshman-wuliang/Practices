#include<stdio.h>

typedef int ElemPos;

ElemPos Binary_Search(int array[],int n,int key);

int main(void)
{
	int array[10] = {1,2,3,4,5,6,7,8,9,10};
	
	printf("待查数组:\n");
	for(int i=1;i<=10;i++)
		printf(" %d",array[i-1]);
	putchar('\n');
	
	printf("待查元素:%d\n",9);
	
	printf("位置:%d\n",Binary_Search(array,10,9));
	
	return 0;
}

ElemPos Binary_Search(int array[],int n,int key)
{
	int low,mid,high;
	
	low = 1;
	high = n;
	
	while(low <= high)
	{
		mid = (low + high)/2;
		
		if(array[mid-1] > key)
			high = mid - 1;
		else if(array[mid-1] < key)
			low = mid + 1;
		else
			return mid;
	}
	
	return -1;
}