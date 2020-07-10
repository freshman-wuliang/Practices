/*
*引用实例
*/

#include<iostream>

int main(void)
{
    int i, &ri = i;

    i = 5;
    ri = 10;

    std::cout << i << ' ' << ri << std::endl;   //10 10
    
    return 0;
}