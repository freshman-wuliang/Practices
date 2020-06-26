#include<stdio.h>

#define N 10

void Qsort(int array[],int low,int high);

int main(void)
{
	int array[N] = {2,4,1,3,5,7,6,9,8,10};
	
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
	printf("low:%d\thigh:%d\n",low,high);
	if(high == 0 || low >= high)
	{
		putchar('\n');
		return;
	}
	
	int base_value = array[low-1];
	int min[N],max[N];
	int min_count = 0;
	int max_count = 0;
	int array_base = low;
	for(int i=low+1;i<=high;i++)
	{
		if(array[i-1] > base_value)
		{
			max[max_count++] = array[i-1];
		}
		else
		{
			min[min_count++] = array[i-1];
		}
	}
	printf("min_c:%d\tmax_c:%d\n",min_count,max_count);
	
	for(int i=1;i<=min_count;i++)
	{
		array[array_base-1] = min[i-1];
		array_base++;
	}
	array[array_base-1] = base_value;
	array_base++;
	for(int i=1;i<=max_count;i++)
	{
		array[array_base-1] = max[i-1];
		array_base++;
	}
	
	for(int i=low;i<=high;i++)
	{
		printf("%d ",array[i-1]);
	}
	printf("\n\n");
	
	Qsort(array,low,low + min_count - 1);
	Qsort(array,high - max_count + 1,high);
}