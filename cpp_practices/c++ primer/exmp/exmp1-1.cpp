/*
*将两个数V1和V2相加
*/
#include<iostream>

int main(void)
{
    std::cout << "enter two numbers:" << std::endl;

    int v1 = 0,v2 = 0;
    std::cin >> v1 >> v2;
    std::cout << "The sum of " << v1 << " and " << v2
              << " is " << v1 + v2 << std::endl;
    
    return 0;
}