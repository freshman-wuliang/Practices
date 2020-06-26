/*
请编写函数fun，对长度为7个字符的字符串，除首、尾字符外
将其余5个字符按ASCII码降序排列。
例如，若原来的字符串为CEAedca，则排序后输出为CedcEAa。
注：ASCII码
0~9:(48~57)
A~Z:(65~90)
a~z:(97~122)
*/

#include<stdio.h>

#define STR_LEN 7

void function(char *ptch);

void bubSort(char array[],int n);

int main(void)
{
	char ch[STR_LEN+1] = "CEAedca";
	//int ceshi[10] = {2,5,4,8,1,6,7,9,15,11};
	
	/*bubSort(ceshi,10);
	for(int i=0;i<10;i++)
	{
		printf("%d ",ceshi[i]);
	}
	printf("\n");
	*/
	printf("before string:%s\n",ch);
	function(ch);
	printf("after string:%s\n",ch);
	
	return 0;
}

void function(char *ptch)
{
	char *ptch_a;
	
	ptch_a = ptch + 1;
	bubSort(ptch_a,STR_LEN-2);
}

void bubSort(char array[],int n)
{
	char tmp;
	
	for(int i=1;i<=n-1;i++)
	{
		for(int j=1;j<=n-i;j++)
		{
			if(array[j-1] < array[j])
			{
				tmp = array[j];
				array[j] = array[j-1];
				array[j-1] = tmp;
			}
		}
	}
}