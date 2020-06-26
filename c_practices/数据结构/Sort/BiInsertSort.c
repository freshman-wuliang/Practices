#include<stdio.h>

int main(void)
{
	int array[10]={0,9,8,7,6,5,4,3,2,1};
	int n = 9;
	int i,j;
	int low,mid,high;
	
	printf("≈≈–Ú«∞:\n");
	for(i=1;i<=n;i++)
		printf("%d",array[i]);
	putchar('\n');
	
	for(i=2;i<=n;i++)
	{
		array[0] = array[i];
		low = 1;
		high = i - 1;
		while(low <= high)
		{
			mid = (low + high) / 2;
			if(array[0] < array[mid])
				high = mid - 1;
			else
				low = mid + 1;
		}
		for(j = i-1;j>=high+1;j--)
		{
			array[j+1] = array[j];
		}
		array[high+1] = array[0];
	}
	
	printf("≈≈–Ú∫Û:\n");
	for(i=1;i<=n;i++)
		printf("%d",array[i]);
	putchar('\n');
}