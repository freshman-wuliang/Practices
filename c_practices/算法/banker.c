//死锁避免——银行家算法

#include<stdio.h>

#define SOURCE_NUM 3
#define PROCESS_NUM 4

typedef struct
{
	int pro_num;
	int max[SOURCE_NUM];
	int allocation[SOURCE_NUM];
	int need[SOURCE_NUM];
	int run_flag;
}Process;

void initNeed(int max[][SOURCE_NUM],int allocation[][SOURCE_NUM],int need[][SOURCE_NUM]);

int minAll(int array1[],int array2[],int num);

int findSuitable(Process p[],int avaliable[]);

int runAndWithdraw(Process p[],int avaliable[]);

int banker(Process p[],int avaliable[]);

void initProcess(Process p[],int max[][SOURCE_NUM],int allocation[][SOURCE_NUM],int need[][SOURCE_NUM]);

int main(void)
{
	int avaliable[SOURCE_NUM] = {0,2,1};
	int max[PROCESS_NUM][SOURCE_NUM] = {{2,2,1},{2,5,2},{1,4,2},{2,0,1}};
	int allocation[PROCESS_NUM][SOURCE_NUM] = {{2,0,0},{1,2,0},{0,1,1},{0,0,1}};
	int need[PROCESS_NUM][SOURCE_NUM];
	Process p[PROCESS_NUM];
	
	initNeed(max,allocation,need);
	initProcess(p,max,allocation,need);
	printf("flag:%d\n",banker(p,avaliable));
	
	return 0;
}

void initNeed(int max[][SOURCE_NUM],int allocation[][SOURCE_NUM],int need[][SOURCE_NUM])
{
	for(int i=1;i<=PROCESS_NUM;i++)
	{
		for(int j=1;j<=SOURCE_NUM;j++)
		{
			need[i-1][j-1] = max[i-1][j-1] - allocation[i-1][j-1];
		}
	}
}

int findSuitable(Process p[],int avaliable[])
{
	int flag = 0;
	
	for(int i=1;i<=PROCESS_NUM;i++)
	{
		if(minAll(p[i-1].need,avaliable,SOURCE_NUM) && p[i-1].run_flag == 0)
		{
			flag = i;
			break;
		}
	}
	
	return flag;
}

int minAll(int array1[],int array2[],int num)
{
	int flag = 1;
	
	for(int i=1;i<=num;i++)
	{
		if(array1[i-1] > array2[i-1])
		{
			flag = 0;
			break;
		}
	}
	
	return flag;
}

int runAndWithdraw(Process p[],int avaliable[])
{
	int pro_index;
	
	pro_index = findSuitable(p,avaliable);
	
	if(!pro_index)
		return 0;
	
	for(int i=1;i<=SOURCE_NUM;i++)
	{
		avaliable[i-1] += p[pro_index-1].allocation[i-1];
	}
	
	p[pro_index-1].run_flag = 1;
	
	return pro_index;
}

int banker(Process p[],int avaliable[])
{
	int flag;
	int process[PROCESS_NUM];
	int pro_count = 0;
	
	for(int i=1;i<=PROCESS_NUM;i++)
	{
		int pro_index;
		
		pro_index = runAndWithdraw(p,avaliable);
		if(!pro_index)
		{
			break;
		}
		
		process[pro_count++] = p[pro_index-1].pro_num;
	}
	
	if(pro_count < PROCESS_NUM)
	{
		flag = 0;
	}
	else
	{
		printf("process:");
		for(int i=1;i<=pro_count;i++)
		{
			printf("%d ",process[i-1]);
		}
		putchar('\n');
		flag = 1;
	}
	
	return flag;
}

void initProcess(Process p[],int max[][SOURCE_NUM],int allocation[][SOURCE_NUM],int need[][SOURCE_NUM])
{
	for(int i=1;i<=PROCESS_NUM;i++)
	{
		p[i-1].pro_num = i;
		for(int j=1;j<=SOURCE_NUM;j++)
		{
			p[i-1].max[j-1] = max[i-1][j-1];
		}
		
		for(int j=1;j<=SOURCE_NUM;j++)
		{
			p[i-1].allocation[j-1] = allocation[i-1][j-1];
		}
		
		for(int j=1;j<=SOURCE_NUM;j++)
		{
			p[i-1].need[j-1] = need[i-1][j-1];
		}
		
		p[i-1].run_flag = 0;
	}
}