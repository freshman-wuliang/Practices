/*
*string类的使用实例
*string类的初始化
*读写string的对象
*读取位置个数的string对象（使用while(cin >> s)实现）
*使用getline(cin,string)读取一行的内容
*empty和size操作
*string对象的比较操作符(==,!=,>=,<=等)
*string对象相加及string对象与字符串相加
*遍历string对象中的每个字符(使用基于范围的for循环)
*使用范围for改变string对象中的某个字符(for循环定义变量是必须使用引用)
*使用下标访问string对象的某个字符
*/

#include<iostream>
#include<string>
#include<cctype>

using namespace std;

int main(void)
{
    /*
    //part1(声明和初始化)
    string s1;  //s1是一个空串
    string s2 = s1;   //用s1构造一个s2
    string s3 = "hello world";   //用字符串初始化
    string s4(5,'a');   //s4中内容为5个a

    cout << "s3: " << s3 << endl;
    cout << "s4: " << s4 << endl;

    //part2(读写string的对象)
    string s5;
    cin >> s5;   //从标准输入流is中读入s5（忽略前面的空白且遇到' '和'\n'停止）
    cout << "s5: " << s5 << endl;

    //part3(读取位置个数的string对象)
    string s6;
    while(cin >> s6)   //只要cin读入的是合法的string对象就一直读,直到EOF或错误
    {
        cout << "s6: " << s6 << endl;
    }
   
   //part4(使用getline(cin,string)读取一行的内容)
   string s7;
   getline(cin,s7);
   cout << "s7: " << s7 << endl;
   /*
   *getline(cin,string)读入时遇到\n结束，读入\n但是不存储\n，如果开始
   *就是\n则s7中的内容为空
   */

    //part5()
    /*string s8;
    getline(cin,s8);
    if(s8.empty() == true)
    {
        cout << "s8 is empty" << endl;
    }
    else
    {
        cout << "s8 length is: " << s8.size() << endl;
    }*/

    //part6(string对象的比较)
    /*string s1 = "hello world";
    string s2 = s1;
    if(s1 == s2)
    {
        cout << "s1 == s2" << endl;
    }
    else
    {
        cout << "s1 != s2" << endl;
    }*/

    //part7(string对象相加)
    /*string s1 = "hello ";
    string s2 = "world";
    cout << "s1 + s2 : " << s1 + s2 << endl;
    cout << "s1 + " << "\"world\" " << s1 + "world" << endl;*/

    //part8(遍历string对象)
    string s1 = "hello world";
    /*for(auto i : s1)
    {
        cout << i << endl;
    }

    for(auto &c : s1)
    {
        c = toupper(c);   //使用标准库函数ctype.h(cctype)
    }
    cout << "s1: " << s1 << endl;*/
    decltype(s1.size()) index = 0;
    if(!s1.empty() && index < s1.size())   //如果s1不为空且下标小于s1的长度
    {
        s1[index] = toupper(s1[index]);
    }
    cout << "s1: " << s1 << endl;

    return 0;
}
