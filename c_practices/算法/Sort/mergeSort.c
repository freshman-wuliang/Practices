/*
*两路归并算法实现
*/

#include<stdio.h>

#define N 10

void printArray(int array[],int n);   //打印数组的函数

void mergeSort(int data[],int n);   //归并排序函数

void copyArray(int source[],int des[],int n);   //复制数组函数

void merge (int array[],int low1,int high1,int low2,int high2,int array2[],int begin);

int main(void)
{
    int data[N] = {2,4,1,3,6,8,9,7,5,10};   //待排数据

    return 0;
}

void printArray(int array[],int n)
{
    for(int i=1;i<=n;i++)
    {
        printf("%d ",array[i-1]);
    }
    printf("\n");
}//printArray函数实现

void mergeSort(int data[],int n)
{
    int tmp[N];
    int index = 0;
    copyArray(data,tmp,n);

    for(int i=1;i<=n;i *= 2)
    {
        int merge_count = (n / i) / 2;

        for(int j=1;j<=merge_count;j++)
        {
        }
    }
}//mergeSort函数实现

void copyArray(int source[],int des[],int n)
{
    for(int i=1;i<=n;i++)
    {
        des[i-1] = source[i-1];
    }
}//copyArray函数实现

/*
*merge函数功能：
*将数组array从low1到high1的元素和从low2到high2的元素合并（[low1,high1]和[low2,high2]均为
*有序序列），合并的结果存储到array2数组中，且存储位置规定为从begin位置开始到数组结束
*/
void merge (int array[],int low1,int high1,int low2,int high2,int array2[],int begin)
{
    int count = begin;
    int p = low1,q = low2;   //两个指针

    while(p <= high1 && q <= high2)
    {
        if(array[p-1] < array[q-1])
        {
            array2[count++] = array[p-1];
            p++;
        }
        else
        {
            array2[count++] = array[q-1];
            q++;
        }
        
    }

    while(p <= high1)
    {
        array2[count++] = array[p-1];
        p++;
    }

    while(q <= high2)
    {
        array2[count++] = array[q-1];
        q++; 
    }
}//merge函数实现