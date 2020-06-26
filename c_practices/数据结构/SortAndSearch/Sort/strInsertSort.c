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
	for(int i=2;i<=n;i++)
	{
		int j;
		for(j=1;j<=i-1;j++)
		{
			if(array[i-1] < array[j-1])
				break;
		}
		
		int tmp = array[i-1];
		for(int k=i;k>=j+1;k--)
		{
			array[k-1] = array[k-2];
		}
		array[j-1] = tmp;
	}
}