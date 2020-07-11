#include<iostream>
#include"Sales_data.h"

int main(void)
{
    Sales_data data1, data2;

    inputData(&data1);
    inputData(&data2);

    if(isSame(data1,data2))
    {
        std::cout << "sum is: " << sumData(data1,data2) << std::endl;
    }
    else
    {
        std::cout << "book is not same" << std::endl;
    }
    
    
    return 0;
}