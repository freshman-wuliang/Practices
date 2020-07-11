#include"Sales_data.h"

void inputData(Sales_data *ps)
{
    std::cin >> ps->bookNo >> ps->units_sold >> ps->revenue;
}

void printData(Sales_data s)
{
    std::cout << s.bookNo << " " << s.units_sold << " " << s.revenue << std::endl;
}

bool isSame(Sales_data data1,Sales_data data2)
{
    if(data1.bookNo == data2.bookNo)
        return true;
    else
        return false;
}

double sumData(Sales_data data1,Sales_data data2)
{
    double result;

    result = data1.units_sold * data1.revenue + data2.units_sold * data2.revenue;

    return result;
}