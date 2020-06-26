/*
*查看注释不正确，编译器返回信息
*/

#include<iostream>

// /*
// *嵌套注释
// *
// */

int main(void)
{
    std::cout << "/*" << std::endl;
    std::cout << "*/" << std::endl;
    std::cout << /* "*/" */ << std::endl;
    
    return 0;
}