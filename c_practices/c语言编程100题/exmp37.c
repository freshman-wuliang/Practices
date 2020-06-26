/*
某学生的记录由学号、8门课程成绩和平均分组成
学号和8门课程的成绩已在主函数中给出。请编写函数fun
它的功能是：求出该学生的平均分放在记录的ave成员中。请自己定义正确的形参。
例如，若学生的成绩是85.5，76，69.5，85，91，72，64.5，87.5，则他的平均分应当是78.875。
*/

#include<stdio.h>

#define MAX_NUM_LEN 10

typedef struct
{
	char number[MAX_NUM_LEN+1];
	float score[8];
	float ave;
}StuInfo,*PStuInfo;

void function(StuInfo *pstu);

int main(void)
{
	StuInfo stu = {"001",{85.5,76,69.5,85,91,72,64.5,87.5}};
	
	function(&stu);
	printf("number:%s\n",stu.number);
	printf("score:");
	for(int i=1;i<=8;i++)
	{
		printf("%.2f ",stu.score[i-1]);
	}
	putchar('\n');
	printf("average:%.2f\n",stu.ave);
	
	return 0;
}

void function(StuInfo *pstu)
{
	float sum = 0.0;
	
	for(int i=1;i<=8;i++)
	{
		sum += pstu->score[i-1];
	}
	pstu->ave = sum / 8.0;
}