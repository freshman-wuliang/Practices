#include<fstream>
#include<iostream>

using namespace std;

int main(void)
{
	int array[10];
	ofstream outfile("f1.dat",ios::out);
	
	if(!outfile)
	{
		cout << "open failed!" << endl;
		exit(1);
	}
	
	cout << "enter 10 number" << endl;
	for(int i=1;i<=10;i++)
	{
		cin >> array[i-1];
	}
	
	for(int i=1;i<=10;i++)
	{
		outfile << array[i-1] << " ";
	}
	
	outfile.close();
	
	cout << "write success" << endl;
	
	return 0;
}