/*
学生的记录由学号和成绩组成
N名学生的数据已在主函数中放入结构体数组s中
请编写函数fun，它的功能是；
把低于平均分的学生数据放在b所指的数组中
低于平均分的学生人数通过形参n传回
平均分通过函数值返回
*/

#include<stdio.h>
#include<string.h>

#define MAX_NUM_LEN 20
#define N 3

typedef struct
{
	char num[MAX_NUM_LEN+1];
	float score;
}StuInfo,PStuInfo;

float function(StuInfo s[],int *pn,StuInfo b[]);

int main(void)
{
	StuInfo s[N] = {{"001",85.0},{"002",87.5},{"003",90.2}};
	StuInfo b[N];
	float ave;
	int n;
	
	for(int i = 1;i<=N;i++)
	{
		printf("num:%s\tscore:%.2f\n",s[i-1].num,s[i-1].score);
	}
	
	printf("after:\n");
	ave = function(s,&n,b);
	
	printf("ave:%.2f\n",ave);
	printf("under the ave num:%d\n",n);
	for(int i = 1;i<=n;i++)
	{
		printf("num:%s\tscore:%.2f\n",b[i-1].num,b[i-1].score);
	}
	
	return 0;
}

float function(StuInfo s[],int *pn,StuInfo b[])
{
	float ave = 0.0;
	int stu_num = 0;
	
	for(int i=1;i<=N;i++)
	{
		ave += s[i-1].score;
	}
	ave /= N;
	
	for(int i=1;i<=N;i++)
	{
		if(s[i-1].score < ave)
		{
			strcpy(b[stu_num].num,s[i-1].num);
			b[stu_num++].score = s[i-1].score;
		}
	}
	
	*pn = stu_num;
	
	return ave;
}