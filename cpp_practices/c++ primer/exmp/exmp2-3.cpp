/*
*指针的引用实例
*/

#include<iostream>

int main(void)
{
    int i = 10;
    int &ri = i;   //int变量的引用

    std::cout << "i = " << ri << std::endl;

    int *pi = &i;   //指向i的指针
    
    /*重点*/
    int *&rpi = pi;   //指针pi的引用

    std::cout << "*pi: " << *pi << std::endl;  //result(10)

    int j = 1;

    rpi = &j;   //将pi变为指向j
    std::cout << "*pi: " << *pi << std::endl;   //result(1)

    *rpi = -1;   //将j的值改变为-1
    std::cout << "j: " << j << std::endl;   //result(-1)

    return 0;
}