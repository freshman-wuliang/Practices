/*
已知学生的记录由学号和学习成绩构成，N名学生的数据已存入a结构体数组中
请编写函数fun，该函数的功能是：找出成绩最高的学生记录
通过形参返回主函数(规定只有一个最高分)
*/

#include<stdio.h>
#include<string.h>

#define N 3
#define MAX_NUM_LEN 10

typedef struct
{
	char num[MAX_NUM_LEN+1];
	float score;
}StuInfo,*PStuInfo;

StuInfo *function(StuInfo a[],int n);

int main(void)
{
	StuInfo a[N];
	PStuInfo p;
	char ch[N][MAX_NUM_LEN+1] = {"001","002","003"};
	float scr[N] = {75.3,85.3,95.3};
	
	//init
	for(int i=1;i<=N;i++)
	{
		strcpy(a[i-1].num,ch[i-1]);
		a[i-1].score = scr[i-1];
	}
	
	//print
	for(int i=1;i<=N;i++)
	{
		printf("num:%s\tscore:%.2lf\n",a[i-1].num,a[i-1].score);
	}
	
	p = function(a,N);
	
	printf("high score student num:%s\n",p->num);
	printf("high score student score:%.2lf\n",p->score);
	
	return 0;
}

StuInfo *function(StuInfo a[],int n)
{
	int index = 0;
	float max = a[0].score;
	
	for(int i=1;i<=n;i++)
	{
		if(a[i-1].score > max)
		{
			index = i-1;
			max = a[i-1].score;
		}
	}
	
	return &a[index];
}