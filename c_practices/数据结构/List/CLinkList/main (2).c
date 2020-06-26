#include<stdio.h>
#include"CLinkList.h"

int main(void)
{
	pCListNode pHeadNode;
	int a1[5] = {1,2,3,4,5};
	int e;

	InitCList(&pHeadNode);
	PrintCList(pHeadNode);
	CreatCList(&pHeadNode,5,a1);
	PrintCList(pHeadNode);
	if(CListEmpty(pHeadNode))
		printf("List is empty\n");
	else
		printf("List is not empty\n");
	printf("清空链表\n");
	ClearCList(pHeadNode);
	if(CListEmpty(pHeadNode))
		printf("List is empty\n");
	else
		printf("List is not empty\n");
	InitCList(&pHeadNode);
	CreatCList(&pHeadNode,5,a1);
	PrintCList(pHeadNode);
	GetElem(pHeadNode,3,&e);
	printf("链表的第3个元素是:%d\n",e);
	printf("4是链表的第%d个元素\n",LocateElem(pHeadNode,4));
	printf("将0插入链表的第3个元素\n");
	printf("插入前:");
	PrintCList(pHeadNode);
	InsertElem(pHeadNode,3,0);
	printf("插入后:");
	PrintCList(pHeadNode);
	printf("删除第2个元素\n");
	printf("删除前:");
	PrintCList(pHeadNode);
	DeleteElem(pHeadNode,2,&e);
	printf("删除后:");
	PrintCList(pHeadNode);
	printf("删除的元素是:%d\n",e);

	return 0;
}
