#include<stdio.h>

#define N 6

int findMinIndex(int array[],int low,int high);

void swapElem(int array[],int index_a,int index_b);

void selectSort(int array[],int n);

int main(void)
{
	int array[N] = {23,12,34,24,27,10};
	
	selectSort(array,N);
	for(int i=1;i<=N;i++)
	{
		printf("%d ",array[i-1]);
	}
	putchar('\n');
	
	return 0;
}

int findMinIndex(int array[],int low,int high)
{
	int index = low;
	int min = array[low-1];
	
	for(int i=low;i<=high;i++)
	{
		if(array[i-1] < min)
		{
			min = array[i-1];
			index = i;
		}
	}
	
	return index;
}

void swapElem(int array[],int index_a,int index_b)
{
	int tmp;
	
	tmp = array[index_a - 1];
	array[index_a - 1] = array[index_b - 1];
	array[index_b - 1] = tmp;
}

void selectSort(int array[],int n)
{
	for(int i=1;i<=n-1;i++)
	{
		swapElem(array,i,findMinIndex(array,i,n));
	}
}