/*
*标准库vector的使用
*vecotor对象的初始化
*向vector对象中添加元素
访问vector对象
*vector对象的empty()方法和size()方法
*/

#include<iostream>
#include<vector>

using namespace std;

int main(void)
{
    //part1初始化vector对象
    vector<int> numbers;
    vector<string> s{"a","ab","abc"};

    //part2(添加元素)
    vector<int> int_numbers;   //空列表
    for(int i=1;i<=10;i++)
    {
        int_numbers.push_back(i);   //将1-10加入int_numbers中
    }

    //part3(使用下标访问vector对象)
    cout << int_numbers[0] << endl;
    //使用范围for语句访问
    for(auto num : int_numbers)
        cout << num << endl;
    
    for(auto &num : int_numbers)
        num += 10;

    for(auto num : int_numbers)
        cout << num << endl;
    
    //part4(empty()方法和size()方法)
    cout << "vector.empty: " << int_numbers.empty() << endl;
    cout << "vector.size: " << int_numbers.size() << endl;
    
    return 0;
}