#include<stdio.h>

#define N 10

void printArray(int array[],int n);

void sort(int array[],int n);

void swap(int array[],int index1,int index2);

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
        for(int j=i+1;j<=n;j++)
        {
            if(array[i-1] > array[j-1])
            {
                swap(array,i,j);
            }
        }
    }
}

void swap(int array[],int index1,int index2)
{
    int tmp;

    tmp = array[index1-1];
    array[index1-1] = array[index2-1];
    array[index2-1] = tmp;
}