/*
m个人的成绩存放在score数组中，请编写函数fun，
它的功能是：将低于平均分的人数作为函数值返回，将低于平均分的分数放在below所指的数组中。
例如，当score数组中的数据为10、20、30、40、50、60、70、80、90时，
函数返回的人数应该是4，below中的数据应为10、20、30、40。
*/

#include<stdio.h>

#define MAX_SIZE 50   //最多五十个人

int function(int score[],int std_num,int below[]);

int main(void)
{
	int score[MAX_SIZE];
	int below[MAX_SIZE];
	int std_num;
	int low_aver_num;
	
	printf("input the student number:");
	scanf("%d",&std_num);
	
	//录入学生成绩
	printf("input student score(score1 score2 ...):\n");
	for(int i=1;i<=std_num;i++)
	{
		scanf("%d",&score[i-1]);
	}
	
	//处理并输出数据
	low_aver_num = function(score,std_num,below);
	printf("low average num:%d\n",low_aver_num);
	for(int i=1;i<=low_aver_num - 1;i++)
	{
		printf("%d ",below[i-1]);
	}
	printf("%d\n",below[low_aver_num-1]);
	
	return 0;
}

int function(int score[],int std_num,int below[])
{
	int num_count = 0;
	int average;
	int sum = 0;
	
	//计算平均值
	for(int i=1;i<=std_num;i++)
	{
		sum += score[i-1];
	}
	average = sum / std_num;
	
	//统计人数
	for(int i=1;i<=std_num;i++)
	{
		if(score[i-1] < average)
		{
			below[num_count++] = score[i-1];
		}
	}
	
	return num_count;
}