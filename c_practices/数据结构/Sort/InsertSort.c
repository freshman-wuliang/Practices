#include<stdio.h>

int main(void)
{
	int i,j;
	int array[10]={-1,9,8,7,6,5,4,3,2,1};
	int n = 9;
	
	printf("����ǰ:\n");
	for(i=1;i<=n;i++)
		printf("%d",array[i]);
	putchar('\n');
	
	for(i=2;i<=n;i++)     //����2��n-1��Ԫ��
	{
		if(array[i]<array[i-1])   //��������ǰ��С
		{
			array[0]=array[i];    //�����ڱ�������i��Ԫ�ص�ֵ
			for(j=i-1;array[j]>array[0];j--)    //��ǰ��1��i-1���Ҳ���λ��
			{
				array[j+1] = array[j];   //�ƶ�λ��
			}
			array[j+1] = array[0];   //����λ��
		}
	}
	
	printf("�����:\n");
	for(i=1;i<=9;i++)
		printf("%d",array[i]);
	putchar('\n');
	
	return 0;
}