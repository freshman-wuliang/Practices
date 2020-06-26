/*
请编写函数fun，该函数的功能是：
统计各年龄段的人数。N个年龄通过调用随机函数获得，并放在主函数的age数组中
要求函数把0至9岁年龄段的人数放在d[0]中
把10至19岁年龄段的人数放在d[1]中
把20至29岁年龄段的人数放在d[2]中
其余依此类推
把100岁(含100)以上年龄的人数都放在d[10]中
结果在主函数中输出。
*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define N 11
#define MAXAGE 120

void function(int age[],int n,int d[]);

int main(void)
{
	int d[N];
	int age[N];
	
	for(int i = 1;i<=N;i++)
	{
		srand(time(NULL) + i);
		age[i-1] = (rand() % MAXAGE + 1);
	}
	printf("age:");
	for(int i=1;i<=N;i++)
	{
		printf("%d ",age[i-1]);
	}
	putchar('\n');
	
	function(age,N,d);
	
	printf("result:");
	for(int i=1;i<=N;i++)
	{
		printf("%d ",d[i-1]);
	}
	putchar('\n');
	
	return 0;
}

void function(int age[],int n,int d[])
{
	for(int i=1;i<=n;i++)
	{
		d[i-1] = 0;
	}
	
	for(int i=1;i<=n;i++)
	{
		switch (age[i-1] / 10)
		{
			case 0 : d[0]++; break;
			case 1 : d[1]++; break;
			case 2 : d[2]++; break;
			case 3 : d[3]++; break;
			case 4 : d[4]++; break;
			case 5 : d[5]++; break;
			case 6 : d[6]++; break;
			case 7 : d[7]++; break;
			case 8 : d[8]++; break;
			case 9 : d[9]++; break;
			default : d[10]++;
		}
	}
}