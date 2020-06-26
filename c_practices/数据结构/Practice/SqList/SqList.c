#include<stdio.h>
#include"config.h"

#define MAXSIZE 50

typedef int ElemType;

typedef struct ListNode
{
	ElemType data[MAXSIZE];
	int length;
}SqList,*pSqList;

void PrintList(SqList L);

Status CreatList(pSqList pL,int n,ElemType array[]);

Status Delete_min(pSqList pL);     //删除最小元素

void Reverse(pSqList pL);    //顺序表逆置

Status Delete_X(pSqList pL,ElemType e);   //删除所有x元素

Status Delete_t2(pSqList pL,ElemType s,ElemType t);   //删除s与t之间的元素

Status Delete_3(pSqList pL,ElemType s,ElemType t);   //删除s与t之间的元素

Status Delete_same(pSqList pL);    //删除相同元素

Status Merge(SqList A,SqList B,pSqList pC);   //合并两个有序表

int main(void)
{
	int array1[5] = {1,2,3,4,5};
	int array2[4] = {6,7,8,9};
	int array3[9];
	int n = 10;
	SqList L1,L2,L3;
	
	CreatList(&L1,5,array1);
	CreatList(&L2,4,array2);
	CreatList(&L3,9,array3);
	PrintList(L1);
	PrintList(L2);
	Merge(L1,L2,&L3);
	PrintList(L3);
	putchar('\n');
	
	return 0;
}

void PrintList(SqList L)
{
	if(0 == L.length)
		printf("EMPTY\n");
	else
	{
		for(int i=1;i<=L.length;i++)
			printf("%d ",L.data[i-1]);
		putchar('\n');
	}
}

Status CreatList(pSqList pL,int n,ElemType array[])
{
	if(n<0 || n>MAXSIZE)
		return FALSE;
	
	for(int i=1;i<=n;i++)
		pL->data[i-1] = array[i-1];
	
	pL->length = n;
	
	return OK;
}

Status Delete_min(pSqList pL)
{
	int min;
	
	if(0 == pL->length)
	{
		printf("ERROR\n");
		return FALSE;
	}
	
	min = 1;
	for(int i=2;i<=pL->length;i++)
	{
		if(pL->data[i-1] < pL->data[min-1])
			min = i;
	}
	pL->data[min-1] = pL->data[pL->length-1];
	pL->length--;
	
	return OK;
}

void Reverse(pSqList pL)
{
	ElemType temp;
	
	for(int i=1;i<=(pL->length/2);i++)
	{
		temp = pL->data[i-1];
		pL->data[i-1] = pL->data[(pL->length-i+1)-1];
		pL->data[(pL->length-i+1-1)] = temp;
	}
}

Status Delete_X(pSqList pL,ElemType e)
{
	int count = 0;
	
	if(pL->length == 0)
		return FALSE;
	
	for(int i=1;i<=pL->length;i++)
	{
		if(pL->data[i-1] != e)
		{
			pL->data[count] = pL->data[i-1];
			count++;
		}
	}
	pL->length = count;
	
	return OK;
}

Status Delete_t2(pSqList pL,ElemType s,ElemType t)
{
	int i,j,n;
	
	if(pL->length == 0)
		return FALSE;
	
	for(i=1;i<=pL->length;i++)
	{
		if(pL->data[i-1] > s)
			break;
	}
	
	for(j=i;j<=pL->length;j++)
	{
		if(pL->data[j-1] >= t)
			break;
	}
	
	n = j - i;
	
	for(int k=j;k<=pL->length;k++)
	{
		pL->data[i-1] = pL->data[k-1];
		i++;
	}
	
	pL->length = pL->length - n;
	
	return OK;
}

Status Delete_3(pSqList pL,ElemType s,ElemType t)
{
	int count = 0;
	
	if(0 == pL->length || t < s)
		return FALSE;
	
	for(int i=1;i<=pL->length;i++)
	{
		if(pL->data[i-1] <= s || pL->data[i-1] >= t)
		{
			pL->data[count] = pL->data[i-1];
			count++;
		}
	}
	
	pL->length = count;
	
	return OK;
}

Status Delete_same(pSqList pL)
{
	int count = 0;
	ElemType tmp;
	
	if(0 == pL->length)
		return FALSE;
	
	tmp = pL->data[0];
	pL->data[count] = pL->data[0];
	count++;
	
	for(int i=2;i<=pL->length;i++)
	{
		if(pL->data[i-1] != tmp)
		{
			pL->data[count] = pL->data[i-1];
			count++;
			tmp = pL->data[i-1];
		}
	}
	
	pL->length = count;
}

Status Merge(SqList A,SqList B,pSqList pC)
{
	int a,b,c;
	
	if(0 == A.length)
	{
		for(int i=1;i<=A.length;i++)
			pC->data[i-1] = A.data[i-1];
		pC->length = A.length;
	}
	
	if(0 == B.length)
	{
		
	}
	
	if(A.length+B.length > MAXSIZE)
		return FALSE;
	
	a = 1,b = 1,c = 1;
	while(a <= A.length && b <= B.length)
	{
		if(A.data[a-1] <= B.data[b-1])
		{
			pC->data[c-1] = A.data[a-1];
			a++;
			c++;
		}
		else
		{
			pC->data[c-1] = B.data[b-1];
			b++;
			c++;
		}
	}
	
	while(a <= A.length)
	{
		pC->data[c-1] = A.data[a-1];
		a++;
		c++;
	}
	
	while(b <= B.length)
	{
		pC->data[c-1] = B.data[b-1];
		c++;
		b++;
	}
	
	pC->length = c - 1;
	
	return OK;
}