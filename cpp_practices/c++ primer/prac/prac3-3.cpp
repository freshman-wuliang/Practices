/*
*任务：使用vector存储从键盘读取的一组字符串
*将字符串改为大写
*输出（每个字符串占一行）
*/

#include<iostream>
#include<vector>
#include<string>
#include<cctype>

using namespace std;

int main(void)
{
    vector<string> strs;   //定义空vector对象
    string s;

    while(cin >> s)
    {
        strs.push_back(s);
    }

    //输出vector对象
    cout << "strs: ";
    for(auto s : strs)
    {
        cout << s << " ";
    }
    cout << endl;

    //改变vector对象
    for(auto &s : strs)
    {
        for(auto &c : s)
        {
            c = toupper(c);
        }
    }

    cout << "strs: " << endl;
    for(auto s : strs)
    {
        cout << s << endl;
    }

    return 0;
}