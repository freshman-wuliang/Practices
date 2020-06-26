#include<stdio.h>

int sumArray(int array[],int low,int high);

int main(void)
{
	int array[10] = {1,2,3,4,5,6,7,8,9,10};
	
	printf("max:%d\n",sumArray(array,1,4));
	
	return 0;
}

int sumArray(int array[],int low,int high)
{
	if(low == high)
	{
		return array[low-1];
	}
	
	if(array[low-1] > sumArray(array,low+1,high))
		return array[low-1];
	else
		return sumArray(array,low+1,high);
}