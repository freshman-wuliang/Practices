/*
学生的记录由学号和成绩组成，N名学生的数据已在主函数中放入结构体数组s中
请编写函数fun，它的功能是：
把指定分数范围内的学生数据放在b所指的数组中,分数范围内的学生人数由函数值返回。
例如,输入的分数是60和69,则应当把分数在60到69的学生数据进行输出
包含60分和69分的学生数据。主函数中将把60放在low中，把69放在heigh中。
*/

#include<stdio.h>
#include<string.h>

#define N 4
#define MAX_NUM_LEN 10

typedef struct
{
	char num[MAX_NUM_LEN+1];
	float score;
}StuInfo,PStuInfo;

int function(StuInfo s[],float low,float high,StuInfo b[]);

void printInfo(StuInfo student[],int num);


int main(void)
{
	StuInfo s[N] = {{"001",55.1},{"002",64.2},{"003",68.0},{"004",65.4}};
	StuInfo b[N];
	float low,high;
	int num;
	
	printf("before:\n");
	printInfo(s,N);
	
	printf("enter low and high:");
	scanf("%f,%f",&low,&high);
	
	num = function(s,low,high,b);
	
	printf("after:\n");
	printInfo(b,num);
	
	return 0;
}

int function(StuInfo s[],float low,float high,StuInfo b[])
{
	int stu_num = 0;
	
	if(low > high)
		return 0;
	
	for(int i=1;i<=N;i++)
	{
		if(s[i-1].score >= low && s[i-1].score <= high)
		{
			strcpy(b[stu_num].num,s[i-1].num);
			b[stu_num++].score = s[i-1].score;
		}
	}
	
	return stu_num;
}

void printInfo(StuInfo student[],int num)
{
	for(int i=1;i<=num;i++)
	{
		printf("num:%s\tscore:%.2f\n",student[i-1].num,student[i-1].score);
	}
}