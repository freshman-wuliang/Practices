/*
已知学生的记录由学号和学习成绩构成，N名学生的数据已存入a结构体数组中
请编写函数fun，该函数的功能是：
找出成绩最低的学生记录，通过形参返回主函数(规定只有一个最低分)
*/

#include<stdio.h>

#define MAX_NUM_LEN 10
#define N 3

typedef struct
{
	char num[MAX_NUM_LEN+1];
	float score;
}StuInfo,*PStuInfo;

void printInfo(StuInfo stu[],int n);

StuInfo function(StuInfo stu[],int n);

int main(void)
{
	StuInfo stu[N] = {{"001",85.2},{"002",84.1},{"003",87.5}};
	
	printInfo(stu,N);
	printf("min:\n");
	printf("num:%s\tscore:%.2f\n",function(stu,N).num,function(stu,N).score);
	
	return 0;
}

void printInfo(StuInfo stu[],int n)
{
	for(int i=1;i<=n;i++)
	{
		printf("num:%s\tscore:%.2f\n",stu[i-1].num,stu[i-1].score);
	}
}

StuInfo function(StuInfo stu[],int n)
{
	float min = stu[0].score;
	int index = 1;
	
	for(int i=1;i<=n;i++)
	{
		if(stu[i-1].score < min)
		{
			min = stu[i-1].score;
			index = i;
		}
	}
	
	return stu[index-1];
}