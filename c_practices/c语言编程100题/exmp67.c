/*
学生的记录由学号和成绩组成，N名学生的数据已在主函数中放入结构体数组s中
请编写函数fun，它的功能是：
函数返回指定学号的学生数据，指定的学号在主函数中输入
若没找到指定学号，在结构体变量中给学号置空串
给成绩置-1，作为函数值返回（用于字符串比较的函数是strcmp）。
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

void displayInfo(StuInfo s[],int n);

StuInfo function(StuInfo s[],int n,char num[]);

int main(void)
{
	StuInfo s[N] = {{"001",85.0},{"002",75.0},{"003",65.0}};
	
	displayInfo(s,N);
	printf("num:%s\t",function(s,N,"004").num);
	printf("score:%.2f\n",function(s,N,"004").score);
	
	return 0;
}

void displayInfo(StuInfo s[],int n)
{
	for(int i=1;i<=n;i++)
	{
		printf("num:%s\tscore:%.2f\n",s[i-1].num,s[i-1].score);
	}
}

StuInfo function(StuInfo s[],int n,char num[])
{
	int i;
	StuInfo stu;
	
	for(i=1;i<=n;i++)
	{
		if(!strcmp(s[i-1].num,num))
		{
			break;
		}
	}
	
	if(i <= n)
	{
		return s[i-1];
	}
	else
	{
		stu.num[0] = '\0';
		stu.score = -1.0;
		return stu;
	}
}