#include<stdio.h>

#define N 10

int binarySearch(int array[],int n,int elem);

int main(void)
{
	int array[N] = {23,25,31,34,36,42,48,49,51,55};
	
	printf("index:%d\n",binarySearch(array,N,43));
	
	return 0;
}

int binarySearch(int array[],int n,int elem)
{
	int low = 1;
	int high = n;
	int mid = (low + high) / 2;
	
	while(low <= high)
	{
		if(array[mid-1] > elem)
		{
			high = mid - 1;
			mid = (low + high) / 2;
		}
		else if(array[mid-1] < elem)
		{
			low = mid + 1;
			mid = (low + high) / 2;
		}
		else
		{
			return mid;
		}
	}
	
	return 0;
}