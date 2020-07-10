/*
*类型转换实例
*有符号int和无符号unsigned的转换
*/

#include<iostream>

int main(void)
{
    //part1
    /*unsigned u = 10;
    int i = -42;

    std::cout << i + i << std::endl;
    std::cout << u + i << std::endl;
    */

    //part2
    unsigned u = 10,u2 = 42;

    std::cout << u2 - u << std::endl;   //32
    std::cout << u - u2 << std::endl;   //unsigned(-32)

    int i = 10, i2 = 42;

    std::cout << i2 - i << std::endl;   //32
    std::cout << i - i2 << std::endl;   //-32
    std::cout << i - u << std::endl;   //0
    std::cout << u - i << std::endl;   //0

    return 0;
}

/*
*结论
*总是有符号向无符号转换
*/