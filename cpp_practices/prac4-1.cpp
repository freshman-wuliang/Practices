#include<iostream>

using namespace std;

int maxComDiv(int a,int b);

int minComMun(int a,int b);

int main(void)
{
	int a,b;
	
	cout << "enter two num:";
	cin >> a >> b;
	cout << "maxComDiv:" << maxComDiv(a,b) << endl;
	cout << "minComMun:" << minComMun(a,b) << endl;
	
	return 0;
}

int maxComDiv(int a,int b)
{
	int max = 1;
	
	for(int i=1;i<=min(a,b);i++)
	{
		if(a % i == 0 && b % i == 0)
		{
			max = i;
		}
	}
	
	return max;
}

int minComMun(int a,int b)
{
	int min;
	
	for(int i = max(a,b);i<=a * b;i++)
	{
		if(i % a == 0 && i % b == 0)
		{
			min = i;
			break;
		}
	}
	
	return min;
}

inline int max(int a,int b)
{
	return a > b? a : b;
}

inline int min(int a,int b)
{
	return a > b? b : a;
}