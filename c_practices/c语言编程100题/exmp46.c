/*
学生的记录由学号和成绩组成，N名学生的数据已在主函数中放入结构体数组s中
请编写函数fun，它的功能是：按分数的高低排列学生的记录，高分在前。
*/

#include<stdio.h>
#include<string.h>

#define MAX_NUM_LEN 20
#define STU_NUM 5

typedef struct
{
	char number[MAX_NUM_LEN+1];
	float score;
}StuInfo,*PStuInfo;

void function(StuInfo student[],int stu_num);

int main(void)
{
	StuInfo student[STU_NUM];
	PStuInfo p;
	char num[STU_NUM][MAX_NUM_LEN+1] = {"001","002","003","004","005"};
	float scr[STU_NUM] = {84.2,62.4,90.5,94,78};
	
	//初始化结构体数组
	for(int i=1;i<=STU_NUM;i++)
	{
		p = &student[i-1];
		for(int j=1;j<=4;j++)
		{
			p->number[j-1] = num[i-1][j-1];
		}
		p->score = scr[i-1];
	}
	
	printf("before:\n");
	//打印结构体数组
	for(int i=1;i<=STU_NUM;i++)
	{
		printf("number:%s\tscore:%.2lf\n",student[i-1].number,student[i-1].score);
	}
	
	function(student,STU_NUM);
	printf("after:\n");
	for(int i=1;i<=STU_NUM;i++)
	{
		printf("number:%s\tscore:%.2lf\n",student[i-1].number,student[i-1].score);
	}
	return 0;
}

void function(StuInfo student[],int stu_num)
{
	char num[MAX_NUM_LEN+1];
	float scr;
	
	for(int i=1;i<=stu_num - 1;i++)
	{
		for(int j=1;j<=stu_num - i;j++)
		{
			//交换前后两个学生的值
			if(student[j-1].score < student[j].score)
			{
				strcpy(num,student[j-1].number);
				scr = student[j-1].score;
				
				strcpy(student[j-1].number,student[j].number);
				student[j-1].score = student[j].score;
				strcpy(student[j].number,num);
				student[j].score = scr;
			}
		}
	}
}