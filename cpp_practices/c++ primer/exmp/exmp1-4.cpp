/*
*键盘输入一系列数，统计每个数出现的次数
*使用while(std::cin >> val)输入数据
*/

#include<iostream>

int main(void)
{
    //currval是目前正在统计的数，val存放读入的数
    int currval,val;

    if(std::cin >> currval)
    {
        //count记录数据出现次数
        int count = 1;

        while(std::cin >> val)   //读取输入流中剩下的数
        {
            if(currval == val)
            {
                count++;
            }
            else
            {
                //输出上个统计的数的信息
                std::cout << currval << " occurs " << count << " times" << std::endl;

                //更新统计的数currval，与计数器count
                currval = val;
                count = 1;
            }
            
        }//while结束

        //输出最后一个统计数据的信息
        std::cout << currval << " occurs " << count << " times" << std::endl;
    }//if结束

    return 0;
}