/*
学生的记录由学号和成绩组成，N名学生的数据已在主函数中放入结构体数组s中
请编写函数fun，它的功能是：
把分数最低的学生数据放在h所指的数组中
注意：分数最低的学生可能不止一个，函数返回分数最低的学生的人数。
*/

#include<stdio.h>
#include<string.h>

#define MAX_NUM_LEN 10
#define N 3

typedef struct
{
	char num[MAX_NUM_LEN+1];
	float score;
}StuInfo,*PStuInfo;

void printStuInfo(StuInfo s[],int n);

int function(StuInfo s[],int n,StuInfo h[]);

int main(void)
{
	StuInfo s[N] = {{"001",75.2},{"002",75.8},{"003",75.2}};
	StuInfo h[N];
	int stu_num;
	
	printf("before:\n");
	printStuInfo(s,N);
	stu_num = function(s,N,h);
	printf("after:\n");
	printf("min_num:%d\n",stu_num);
	printStuInfo(h,stu_num);
	
	return 0;
}

void printStuInfo(StuInfo s[],int n)
{
	for(int i=1;i<=n;i++)
	{
		printf("num:%s\tscore:%.2f\n",s[i-1].num,s[i-1].score);
	}
}

int function(StuInfo s[],int n,StuInfo h[])
{
	int stu_num = 0;
	float min_score = s[0].score;
	
	for(int i=1;i<=n;i++)
	{
		if(s[i-1].score < min_score)
		{
			min_score = s[i-1].score;
		}
	}
	
	for(int i=1;i<=n;i++)
	{
		if(s[i-1].score == min_score)
		{
			strcpy(h[stu_num].num,s[i-1].num);
			h[stu_num].score = min_score;
			stu_num++;
		}
	}
	
	return stu_num;
}