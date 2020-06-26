#include<stdio.h>

int partition(int array[],int low,int high);

void QuickSort(int array[],int low,int high);

int main(void)	
{
	int array[10] = {10,9,8,7,6,5,4,3,2,1};
	int n =10;
	
	printf("≈≈–Ú«∞:");
	for(int i=1;i<=n;i++)
		printf("%d",array[i-1]);
	putchar('\n');
	
	QuickSort(array,1,n);
	
	printf("≈≈–Ú∫Û:");
	for(int i=1;i<=n;i++)
		printf("%d",array[i-1]);
	putchar('\n');
	
	return 0;
}

int partition(int array[],int low,int high)
{
	int pivot = array[low-1];
	
	while(low < high)
	{
		while(low < high && array[high-1] >= pivot)
			high--;
		array[low-1] = array[high-1];
		
		while(low < high && array[low-1] <= pivot)
			low++;
		array[high-1] = array[low-1];
	}
	
	array[low-1] = pivot;
	
	return low;
}

void QuickSort(int array[],int low,int high)
{
	if(low < high)
	{
		int pivotpos = partition(array,low,high);
		
		QuickSort(array,low,pivotpos-1);
		QuickSort(array,pivotpos+1,high);
	}
}