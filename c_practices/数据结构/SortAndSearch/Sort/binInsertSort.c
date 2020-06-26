#include<stdio.h>

#define N 10

void printArray(int array[],int n);

void sort(int array[],int n);

int binSearch(int array[],int n,int elem);

int main(void)
{
	int array[N] = {2,6,5,3,4,7,1,9,10,8};
	
	printArray(array,N);
	sort(array,N);
	printArray(array,N);
	
	return 0;
}

void printArray(int array[],int n)
{
	for(int i=1;i<=n;i++)
	{
		printf("%d ",array[i-1]);
	}
	putchar('\n');
}

void sort(int array[],int n)
{
	for(int i=2;i<=n;i++)
	{
		int index;
		index = binSearch(array,i-1,array[i-1]);
		
		int tmp = array[i-1];
		for(int j=i;j>=index+1;j--)
		{
			array[j-1] = array[j-2];
		}
		array[index-1] = tmp;
	}
}

int binSearch(int array[],int n,int elem)
{
	int index;
	int low = 1;
	int high = n;
	int mid;
	
	if(low > high)
		return 0;
	
	while(low <= high)
	{
		mid = (low + high) / 2;
		
		if(array[mid-1] > elem)
		{
			high = mid - 1;
		}
		else if(array[mid-1] < elem)
		{
			low = mid + 1;
		}
		else
		{
			index = mid + 1;
			break;
		}
	}
	
	if(low > high)
	{
		index = low;
	}
	
	return index;
}