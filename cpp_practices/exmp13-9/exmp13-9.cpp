#include<iostream>
#include<fstream>

using namespace std;

int main(void)
{
	ifstream infile("f1.dat",ios::in);
	
	if(!infile)
	{
		cerr << "open error" << endl;
		exit(1);
	}
	
	int array[10];
	int max = 0;
	int index;
	
	for(int i=1;i<=10;i++)
	{
		infile >> array[i-1];
		if(array[i-1] > max)
		{
			max = array[i-1];
			index = i;
		}
	}
	
	for(int i=1;i<=10;i++)
	{
		cout << array[i-1] << " ";
	}
	cout << endl;
	cout << "max:" << max << " " << "index:" << index << endl;
	
	infile.close();
	
	return 0;
}