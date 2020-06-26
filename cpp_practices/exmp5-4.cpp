#include<iostream>

using namespace std;

void function(int a[2][3],int b[3][2]);

int main(void)
{
	int a[2][3] = {{1,2,3},{4,5,6}};
	int b[3][2];
	
	for(int i=1;i<=2;i++)
	{
		cout << '|';
		for(int j=1;j<=3;j++)
		{
			cout << a[i-1][j-1] << ' ';
		}
		cout << '|' << endl;
	}
	
	function(a,b);
	
	for(int i=1;i<=3;i++)
	{
		cout << '|';
		for(int j=1;j<=2;j++)
		{
			cout << b[i-1][j-1] << ' ';
		}
		cout << '|' << endl;
	}
	
	return 0;
}

void function(int a[2][3],int b[3][2])
{
	for(int i=1;i<=2;i++)
	{
		for(int j=1;j<=3;j++)
		{
			b[j-1][i-1] = a[i-1][j-1];
		}
	}
}