#include"LinkList.h"
#include<stdio.h>

int main(void)
{
	pListNode pHeadNode,pHeadNode1,pHeadNode2,pHeadNode3;
	int a1[6] = {1,2,3,4,5,6};
	int a2[3] = {0,5,9};
	int a3[6] = {0,2,3,5,6,9};
	int e;

	InitLinkList(&pHeadNode);
	if(ListEmpty(pHeadNode))
		printf("链表空\n");
	else
		printf("链表非空\n");
	PrintLinkList(pHeadNode);
	CreatLinkList(&pHeadNode,6,a1);
	PrintLinkList(pHeadNode);
	printf("链表长度为:%d\n",ListLength(pHeadNode));
	if(ListEmpty(pHeadNode))
		printf("链表空\n");
	else
		printf("链表非空\n");
	GetElem(pHeadNode,3,&e);
	printf("链表的第%d个元素为%d\n",3,e);
	printf("%d是链表的第%d个元素\n",4,LocateElem(pHeadNode,4));
	printf("\n\n将0插入第5个位置:\n");
	printf("插入前:");
	PrintLinkList(pHeadNode);
	printf("插入后:");
	InsertElem(pHeadNode,5,0);
	PrintLinkList(pHeadNode);
	printf("\n\n删除第2个元素:\n");
	printf("删除前:");
	PrintLinkList(pHeadNode);
	printf("删除后:");
	DeleteElem(pHeadNode,2,&e);
	PrintLinkList(pHeadNode);
	printf("删除的元素为:%d\n",e);

	//UnionLinkList
	InitLinkList(&pHeadNode1);
	InitLinkList(&pHeadNode2);
	InitLinkList(&pHeadNode3);
	CreatLinkList(&pHeadNode1,3,a2);
	CreatLinkList(&pHeadNode2,6,a3);
	printf("\n\n取并前:\n");
	printf("L1:");
	PrintLinkList(pHeadNode1);
	printf("L2:");
	PrintLinkList(pHeadNode2);
	UnionLinkList(pHeadNode1,pHeadNode2,pHeadNode3);
	printf("取并后:\n");
	PrintLinkList(pHeadNode3);

	//MergeLinkList
	InitLinkList(&pHeadNode1);
	InitLinkList(&pHeadNode2);
	InitLinkList(&pHeadNode3);
	CreatLinkList(&pHeadNode1,3,a2);
	CreatLinkList(&pHeadNode2,6,a3);
	printf("\n\n合并前:\n");
	printf("L1:");
	PrintLinkList(pHeadNode1);
	printf("L2:");
	PrintLinkList(pHeadNode2);
	MergeLinkList(&pHeadNode1,&pHeadNode2,&pHeadNode3);
	printf("合并后:\n");
	PrintLinkList(pHeadNode3);


	return 0;
}
