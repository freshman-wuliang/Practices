/*
*输出vector对象的容量和内容
*/

#include<iostream>
#include<vector>

using namespace std;

int main(void)
{
    vector<int> int_numbers;

    for(int i=1;i<=10;i++)
    {
        int_numbers.push_back(i);
    }//将1-10添加到int_numbers

    cout << "int_numbers have " << int_numbers.size() << " numbers" << endl;

    cout << "int_numbers:";
    for(auto n : int_numbers)
    {
        cout << n << " ";
    }
    cout << endl;

    return 0;
}