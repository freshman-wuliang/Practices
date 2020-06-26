#include<stdio.h>

#define N 10

int sumArray(int array[],int low,int high);

int main(void)
{
	int array[N] = {1,2,3,4,5,6,7,8,9,10};
	
	printf("sum:%d\n",sumArray(array,1,10));
	
	return 0;
}

int sumArray(int array[],int low,int high)
{
	if(high == 0)
		return 0;
	if(high == low)
		return array[low-1];
	
	return array[low-1] + sumArray(array,low+1,high);
}