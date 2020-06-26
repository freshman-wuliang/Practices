#include<iostream>

using namespace std;

int main(void)
{
	char ch;
	
	cout << "enter a char:";
	cin >> ch;
	
	ch = (ch >= 'A' && ch <= 'Z')? ch + 32 : ch;
	
	cout << "ch=" << ch << endl;
	return 0;
}