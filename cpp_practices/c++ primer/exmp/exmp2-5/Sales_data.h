/*
*sales_data头文件
*定义了结构Sales_data和一些基本操作
*/

#ifndef SALES_DATA_H
#define SALES_DATA_H

#include<iostream>
#include<string>

typedef struct
{
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
}Sales_data;   //定义结构Sales_data

void inputData(Sales_data *ps);

void printData(Sales_data s);

bool isSame(Sales_data data1,Sales_data data2);

double sumData(Sales_data data1,Sales_data data2);

#endif