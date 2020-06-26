#include<stdio.h>

#define N 10

void printArray(int array[],int n);

void sort(int array[],int n);

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
	for(int i=1;i<=n-1;i++)
	{
		for(int j=1;j<=n-i;j++)
		{
			if(array[j] < array[j-1])
			{
				int tmp = array[j-1];
				array[j-1] = array[j];
				array[j] = tmp;
			}
		}
	}
}