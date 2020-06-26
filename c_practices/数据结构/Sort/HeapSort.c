#include<stdio.h>

void HeapAdjust(int array[],int low,int high);

void HeapSort(int array[],int n);

int main(void)
{
	int array[10] = {10,9,8,7,6,5,4,3,2,1};
	int n = 10;
	
	printf("����ǰ:");
	for(int i=1;i<=n;i++)
		printf("%d",array[i-1]);
	putchar('\n');
	
	HeapSort(array,n);
	
	printf("�����:");
	for(int i=1;i<=n;i++)
		printf("%d",array[i-1]);
	putchar('\n');
	
	return 0;
}

void HeapAdjust(int array[],int low,int high)   //������
{
	int AdjustValue = array[low-1];   //��¼������ֵ
	int AdjustPos = low;              //��¼������λ��
	
	for(int i = 2*low;i <= high;i *= 2)   //�Ӵ�Ľ�����µ���
	{
		if(i<high && array[i-1]<array[i+1-1])
			i++;                           //�ҳ��������������ֵ
		if(array[i-1] > AdjustValue)         //����ֵ������С,�ı����λ��
		{
			array[AdjustPos-1] = array[i-1];
			AdjustPos = i;
		}
	}
	array[AdjustPos-1] = AdjustValue;    //�������ֵ
}

void HeapSort(int array[],int n)       //������
{
	for(int i=n/2;i>=1;i--)            //���󶥶�
		HeapAdjust(array,i,n);
		
	for(int i=n;i>=2;i--)
	{
		int t;
		t = array[1-1];
		array[1-1] = array[i-1];
		array[i-1] = t;         //�����Ѷ������һ��Ԫ��
		
		HeapAdjust(array,1,i-1);         //������1��i-1��Ԫ��
	}
}