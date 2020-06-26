/*
*使用while输出50到100的所有整数的和
*/

#include<iostream>

int main(void)
{
    int sum = 0, val = 50;

    while(val <= 100)
    {
        sum += val;
        val++;
    }

    std::cout << "sum of 50 to 100 inclusive is" << sum << std::endl;
    
    return 0;
}