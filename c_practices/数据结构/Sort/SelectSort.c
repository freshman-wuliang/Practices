#include<stdio.h>

int main(void)
{
	int array[10] = {10,9,8,7,6,5,4,3,2,1};
	int n = 10;
	
	printf("����ǰ:");
	for(int i=1;i<=n;i++)
		printf("%d",array[i-1]);
	putchar('\n');
	
	for(int i=1;i<=n-1;i++)   //������n-1������
	{
		int min = i + 1;      //��¼��СԪ�ص�λ��
		for(int j=i+2;j<=n;j++)   //����i+1��n����СԪ��
		{
			if(array[j-1] < array[min-1])   //�����minС�����min��ֵ
				min = j;
		}
		
		if(array[min-1] < array[i-1])   //�Ƚ�i��min��ֵ����i>min�򽻻�i��min��ֵ
		{
			int t;
			t = array[i-1];
			array[i-1] = array[min-1];
			array[min-1] = t;
		}
	}
	
	printf("�����:");
	for(int i=1;i<=n;i++)
		printf("%d",array[i-1]);
	putchar('\n');
	
	return 0;
}