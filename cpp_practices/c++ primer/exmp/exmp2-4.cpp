/*
*常量表达式与constexpr实例
*/

#include<iostream>

int main(void)
{
    constexpr double pi = 3.1415926;   //声明一个常量

    //尝试修改常量的值
    //pi = 3.2;
    //编译错误

    std::cout << "pi: " << pi << std::endl;

    return 0;
}