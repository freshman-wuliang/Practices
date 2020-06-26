/*
*用户输入两个整数v1和v2，使用while输出v1到v2之间的整数
*v1小于v2
*/

#include<iostream>

int main(void)
{
    int v1,v2;

    std::cout << "enter two numbers:" << std::endl;
    std::cin >> v1 >> v2;

    while(v1 <= v2)
    {
        std::cout << v1 << " ";
        v1++;
    }
    std::cout << std::endl;
    
    return 0;
}