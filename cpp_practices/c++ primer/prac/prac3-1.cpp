/*
*使用范围for语句将string对象的字符全部改成'x'
*/

#include<iostream>
#include<string>

using namespace std;

int main(void)
{
    string s = "abcd";

    cout << "before: " << s << endl;

    for(auto &c : s)
        c = 'x';
    
    cout << "after: " << s << endl;

    return 0;
}