#include<stdio.h>

int binarySearch(int array[],int low,int high,int elem);

int main(void)
{
	int array[10] = {2,4,6,8,10,12,14,16,18,20};
	
	printf("index:%d\n",binarySearch(array,1,10,18));
	
	return 0;
}

int binarySearch(int array[],int low,int high,int elem)
{
	printf("low:%d,high:%d\n",low,high);
	if(low == high)
	{
		if(array[low-1] == elem)
			return low;
		else
			return 0;
	}
	
	int mid = (low + high) / 2;
	if(array[mid-1] > elem)
	{
		return binarySearch(array,low,mid-1,elem);
	}
	else if(array[mid-1] < elem)
	{
		return binarySearch(array,mid+1,high,elem);
	}
	else
	{
		return mid;
	}
}