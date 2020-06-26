/*
*输入未知个数的数，求它们的和
*实现方法：使用while检测输入流cin的状态
*如果cin输入有效（输入类型与变量类型匹配/未到文件末尾end-of-file）
*则对输入的数进行累加
*/

#include<iostream>

int main(void)
{
    int sum = 0, val;

    while(std::cin >> val)   //检测流cin的状态
    {
        sum += val;
    }

    std::cout << "The sum is " << sum << std::endl;

    return 0;
}

/*
*不同的操作系统对于EOF的输入方式不同
*windows: ctrl+z然后按enter键
*UNIX/Mac OS:ctrl+D
*/