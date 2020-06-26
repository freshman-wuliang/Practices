#include<iostream>

#define N 10

using namespace std;

class Array
{
	public :
		void setArray(int src[],int n);
		
		void printArray(void);
		
		int maxElem(void);
		
	private :
		int array[10];
};

int main(void)
{
	Array a;
	int src[N] = {12,12,39,-34,17,134,0,45,-91,76};
	
	a.setArray(src,N);
	a.printArray();
	cout << "max:" << a.maxElem() << endl;
	
	return 0;
}

void Array::setArray(int src[],int n)
{
	if(n >= 10)
	{
		for(int i=1;i<=10;i++)
		{
			array[i-1] = src[i-1];
		}
	}
	else
	{
		for(int i=1;i<=n;i++)
		{
			array[i-1] = src[i-1];
		}
		for(int i=n;i<=10;i++)
		{
			array[i-1] = 0;
		}
		
	}
}

void Array::printArray(void)
{
	for(int i=1;i<=10;i++)
	{
		cout << array[i-1] << ' ';
	}
	cout << endl;
}

int Array::maxElem(void)
{
	int max = array[0];
	
	for(int i=1;i<=10;i++)
	{
		if(array[i-1] > max)
		{
			max = array[i-1];
		}
	}
	
	return max;
}