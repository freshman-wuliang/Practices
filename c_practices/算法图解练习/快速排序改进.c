#include<stdio.h>

void Qsort(int array[],int low,int high);

void swap(int array[],int a,int b);

int main(void)
{
	int array[10] = {2,4,1,3,5,7,6,9,8,10};
	
	//swap(array,1,10);
	Qsort(array,1,10);
	for(int i=1;i<=10;i++)
	{
		printf("%d ",array[i-1]);
	}
	putchar('\n');
	
	return 0;
}

void Qsort(int array[],int low,int high)
{
	if(low >= high)
	{
		return;
	}
	
	int base_value = array[low-1];
	int low_p = low+1;
	int high_p = high;
	
	while(low_p < high_p)
	{
		while(low_p < high_p && array[high_p-1] > base_value)
			high_p--;
		while(low_p < high_p && array[low_p-1] <= base_value)
			low_p++;
		swap(array,low_p,high_p);
	}
	
	if(base_value > array[high_p-1])
	{
		swap(array,low,high_p);
		Qsort(array,low,high_p-1);
		Qsort(array,high_p+1,high);
	}
	else
	{
		Qsort(array,low,high_p-1);
		Qsort(array,high_p,high);
	}
}

void swap(int array[],int a,int b)
{
	int tmp = array[a-1];
	
	array[a-1] = array[b-1];
	array[b-1] = tmp;
}