#include"SqList.h"
#include<stdio.h>

int main(void)
{
	SqList L1;
	SqList L2,L3,L4,L5;
	int e;
	int a1[5] = {1,2,3,4,5};
	int a2[6] = {0,2,5,8,7,3};
	int a3[4] = {4,1,8,5};
	int a4[4] = {1,3,5,9};
	int a5[6] = {2,3,5,8,10,12};

	InitSqList(&L1);
	if(SqListEmpty(L1))
	{
		printf("SqList is Empty!\n");
	}
	DestroySqList(&L1);
	InitSqList(&L1);
	CreatSqList(&L1,5,a1);
	PrintSqList(L1);
	ClearSqList(&L1);
	PrintSqList(L1);
	CreatSqList(&L1,5,a1);
	PrintSqList(L1);
	printf("SqList's length is %d\n",SqListLength(L1));
	GetElem(L1,2,&e);
	printf("SqList's secend element is %d\n",e);
	printf("4 is the %d element\n",LocateElem(L1,4));
	PriorElem(L1,4,&e);
	printf("4的前驱是:%d\n",e);
	NextElem(L1,4,&e);
	printf("4的后继是:%d\n",e);
	printf("将0插入第6个位置\n");
	printf("插入前:");
	PrintSqList(L1);
	printf("插入后:");
	InsertElem(&L1,6,0);
	PrintSqList(L1);
	printf("删除第一个元素\n");
	printf("删除前:");
	PrintSqList(L1);
	DeleteElem(&L1,1,&e);
	printf("删除后:");
	PrintSqList(L1);
	printf("被删除的元素为:%d\n",e);
	ClearSqList(&L1);
	CreatSqList(&L1,5,a1);
	printf("插入前:");
	PrintSqList(L1);
	for(int i=6;i<=11;i++)
	{
		InsertElem(&L1,i,i);
	}
	printf("插入后:");
	PrintSqList(L1);

	//unionSqList
	printf("\n\n");
	InitSqList(&L2);
	InitSqList(&L3);
	CreatSqList(&L2,6,a2);
	CreatSqList(&L3,4,a3);
	printf("L2:");
	PrintSqList(L2);
	printf("L3");
	PrintSqList(L3);
	printf("after union\n");
	UnionSqList(&L2,L3);
	PrintSqList(L2);

	//MergeSqList
	printf("\n\n");
	InitSqList(&L4);
	InitSqList(&L5);
	InitSqList(&L3);
	CreatSqList(&L4,4,a4);
	CreatSqList(&L5,6,a5);
	printf("before Merge\n");
	PrintSqList(L4);
	PrintSqList(L5);
	printf("after Merge\n");
	MergeSqList(L4,L5,&L3);
	PrintSqList(L3);

	return 0;
}
