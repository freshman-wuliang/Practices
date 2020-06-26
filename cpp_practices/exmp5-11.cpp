#include<iostream>
#include<string>

using namespace std;

int main(void)
{
	string str1,str2,str3,temp;
	
	cout << "input three string:";
	cin >> str1 >> str2 >> str3;
	
	temp = str1 > str2? str1 : str2;
	temp = temp > str3? temp : str3;
	cout << temp << ' ';
	
	if(temp == str1)
	{
		cout << str2 > str3? str2 : str3 << ' ';
		cout << str2 > str3? str3 : str2 << endl;
	}
	else
	{
		if(temp == str2)
		{
			cout << str1 > str3? str1 : str3 << ' ';
			cout << str1 > str3? str3 : str1 << endl;
		}
		else
		{
			cout << str1 > str2? str1 : str2 << ' ';
			cout << str1 > str2? str2 : str1 << endl;
		}
	}
	
	return 0;
}