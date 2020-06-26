#include<stdio.h>
#include"DcLinkList.h"

int main(void)
{
	pDcLNode pHeadNode;
	int a1[6] = {1,2,3,4,5,6};
	int e;

	InitDcList(&pHeadNode);
	PrintDcList(pHeadNode);
	CreatDcList(pHeadNode,6,a1);
	PrintDcList(pHeadNode);
	if(DcListEmpty(pHeadNode))
		printf("链表空\n");
	else
		printf("链表非空\n");

	printf("清空链表\n");
	ClearDcList(pHeadNode);
	if(DcListEmpty(pHeadNode))
		printf("链表空\n");
	else
		printf("链表非空\n");
	InitDcList(&pHeadNode);
	CreatDcList(pHeadNode,6,a1);
	PrintDcList(pHeadNode);
	GetElem(pHeadNode,2,&e);
	printf("链表的第2个元素是:%d\n",e);
	printf("6是链表的第%d个元素\n",LocateElem(pHeadNode,6));
	printf("将0插入链表第2个位置\n");
	printf("插入前:");
	PrintDcList(pHeadNode);
	printf("插入后:");
	InsertElem(pHeadNode,2,0);
	PrintDcList(pHeadNode);
	printf("删除第4个元素\n");
	printf("删除前:");
	PrintDcList(pHeadNode);
	printf("删除后:");
	DeleteElem(pHeadNode,4,&e);
	PrintDcList(pHeadNode);
	printf("删除的元素为:%d\n",e);

	return 0;
}
