/*
*读入一组整数存入vector对象
*输出每队相邻整数的和
*依次输出第1和最后的和、第2和倒数第2的和...
*/

#include<iostream>
#include<vector>

using namespace std;

int main(void)
{
    vector<int> int_numbers;
    int int_num;
    while(cin >> int_num)
    {
        int_numbers.push_back(int_num);
    }

    cout << "int_numbers: ";
    for(auto n : int_numbers)
    {
        cout << n << " ";
    }
    cout << endl;

    for(decltype(int_numbers.size()) i=1;i<=int_numbers.size() - 1;i++)
    {
        cout << "sum" << i << ": " << int_numbers[i-1] + int_numbers[i] << endl;
    }

    cout << endl;
    for(decltype(int_numbers.size()) i = 1,j = int_numbers.size();i <= j;i++,j--)
    {
        cout << "sum" << i << ": " << int_numbers[i-1] + int_numbers[j-1] << endl;
    }

    return 0;
}