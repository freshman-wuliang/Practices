#include<stdio.h>

#define N 10

int step(int n);

void getAddArray(int n,int step,int addArray[]);

void getTmpArray(int n,int array[],int addArray[],int tmpArray[]);

void partSort(int array[],int low,int high);

int getArrayNum(int n,int step);

void copyArray(int n,int array1[],int array2[]);

void shellInsertSort(int array[],int n);

void printArray(int array[],int n);

int main(void)
{
	int array[N] = {2,6,5,3,4,7,1,9,10,8};
	
	printArray(array,N);
	shellInsertSort(array,N);
	printArray(array,N);
	
	return 0;
}

int step(int n)
{
	static int count;
	int step = n / 2;
	
	for(int i=1;i<=count;i++)
	{
		step /= 2;
	}
	
	count++;
	
	return step;
}

void getAddArray(int n,int step,int addArray[])
{
	int index = 0;
	
	for(int i=1;i<=step;i++)
	{
		addArray[index++] = i;
		int tmp = i + step;
		while(tmp <= n)
		{
			addArray[index++] = tmp;
			tmp += step;
		}
	}
}

void getTmpArray(int n,int array[],int addArray[],int tmpArray[])
{
	int index = 0;
	
	for(int i=1;i<=n;i++)
	{
		tmpArray[index++] = array[addArray[i-1]-1];
	}
}

void partSort(int array[],int low,int high)
{
	for(int i=low+1;i<=high;i++)
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

int getArrayNum(int n,int step)
{
	static int count;
	
	if(n % step == 0)
	{
		count++;
		return n / step;
	}
	else
	{
		int tmp = n % step;
		
		if(count+1 <= tmp)
		{
			count++;
			return N / step + 1;
		}
		else
		{
			count++;
			return N / step;
		}
	}
}

void copyArray(int n,int array1[],int array2[])
{
	for(int i=1;i<=n;i++)
	{
		array1[i-1] = array2[i-1];
	}
}

void shellInsertSort(int array[],int n)
{
	int dk;
	int addArray[N];
	int tmpArray[N];
	
	while((dk = step(n)) >= 1)
	{
		getAddArray(n,dk,addArray);
		getTmpArray(n,array,addArray,tmpArray);
		
		int low = 1;
		for(int i=1;i<=dk;i++)
		{
			int tmp = getArrayNum(N,dk);
			partSort(tmpArray,low,low+tmp-1);
			copyArray(n,array,tmpArray);
			low += tmp;
		}
		
		printf("step(%d):",dk);
		printArray(array,n);
	}
}

void printArray(int array[],int n)
{
	for(int i=1;i<=n;i++)
	{
		printf("%d ",array[i-1]);
	}
	putchar('\n');
}