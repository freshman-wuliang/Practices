/*
学生的记录由学号和成绩组成，N名学生的数据已在主函数中放入结构体数组s中
请编写函数fun，它的功能是：把分数最高的学生数据放在h所指的数组中
注意：分数最高的学生可能不只一个，函数返回分数最高的学生的人数。
*/

#include<stdio.h>
#include<string.h>

#define MAX_NUM_SIZE 20

typedef struct
{
	char number[MAX_NUM_SIZE+1];
	float score;
}StuInfo,*PStuInfo;

int function(StuInfo s[],int n,StuInfo h[]);

void printStuInfo(StuInfo s[],int n);

int main(void)
{
	StuInfo s[] = {
		{"001",85.3},{"002",87.6},{"003",90.1},{"004",90.1}
	};
	StuInfo h[4];
	int n;
	
	printf("student information\n");
	printStuInfo(s,4);
	n = function(s,4,h);
	printf("max:%d people\n",n);
	printStuInfo(h,n);
	
	return 0;
}

int function(StuInfo s[],int n,StuInfo h[])
{
	int count = 0;
	float max_score;
	
	max_score = s[0].score;
	for(int i=1;i<=n;i++)
	{
		if(s[i-1].score > max_score)
		{
			max_score = s[i-1].score;
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(s[i-1].score == max_score)
		{
			h[count].score = s[i-1].score;
			strcpy(h[count].number,s[i-1].number);
			count++;
		}
	}
	
	return count;
}

void printStuInfo(StuInfo s[],int n)
{
	for(int i=1;i<=n;i++)
	{
		printf("number:%s\tscore:%.2f\n",s[i-1].number,s[i-1].score);
	}
}