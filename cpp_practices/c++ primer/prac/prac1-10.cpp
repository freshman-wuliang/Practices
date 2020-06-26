/*
*使用while，按照递减的顺序输出10到0的整数
*/

#include<iostream>

int main(void)
{
    int val = 10;

    while(val >= 0)
    {
        std::cout << val << " ";
        val--;
    }
    std::cout << std::endl;
    
    return 0;
}