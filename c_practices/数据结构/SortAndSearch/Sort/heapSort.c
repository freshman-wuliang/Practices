#include<stdio.h>

#define N 10

void printArray(int array[],int n);

void buildMaxHeap(int array[],int n);

void adjust(int array[],int index);

void change(int array[],int index1,int index2);

void heapSort(int array[],int n);

int main(void)
{
    int array[N] = {2,6,5,3,4,7,1,9,10,8};

    printArray(array,N);
    heapSort(array,N);
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

void buildMaxHeap(int array[],int n)
{
    if(n/2 * 2 + 1 <= n)
    {
        for(int i= n/2;i>=1;i--)
        {
            adjust(array,i);
        }
    }
    else
    {
        if(array[n/2 * 2 - 1] > array[n/2 - 1])
        {
            int tmp = array[n/2 - 1];
            array[n/2 - 1] = array[n/2 * 2 - 1];
            array[n/2 * 2 - 1] = tmp;
        }
        for(int i= n/2 - 1;i>=1;i--)
        {
            adjust(array,i);
        }
    }
    
}

void adjust(int array[],int index)
{
    if(array[index-1] < array[2 * index - 1])
    {
        int tmp = array[index-1];
        array[index-1] = array[index * 2 - 1];
        array[index * 2 -1] = tmp;
    }
    if(array[index-1] < array[index * 2])
    {
        int tmp = array[index-1];
        array[index-1] = array[index * 2];
        array[index * 2] = tmp;
    }
}

void change(int array[],int index1,int index2)
{
    int tmp = array[index1 - 1];
    array[index1-1] = array[index2-1];
    array[index2-1] = tmp;
}

void heapSort(int array[],int n)
{
    for(int i=n-1;i>=1;i--)
    {
        buildMaxHeap(array,i+1);
        change(array,1,i+1);
    }
}