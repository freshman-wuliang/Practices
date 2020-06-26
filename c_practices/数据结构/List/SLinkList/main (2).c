#include<stdio.h>
#include"SLinkList.h"

int main(void)
{
	int a1[6] = {1,2,3,4,5,6};
	SLinkList SL;
	int e;

	InitSList(SL);
	CreatSList(SL,6,a1);
	PrintSList(SL);

	//Clear
	ClearSList(SL);
	PrintSList(SL);
	if(SListEmpty(SL))
		printf("链表空\n");
	else
		printf("链表非空\n");
	
	//
	InitSList(SL);
	CreatSList(SL,6,a1);
	PrintSList(SL);
	printf("表长:%d\n",SListLength(SL));
	GetElem(SL,3,&e);
	printf("链表的第3个元素是:%d\n",e);
	printf("将0插入第4个位置\n");
	printf("插入前:");
	PrintSList(SL);
	printf("插入后:");
	InsertElem(SL,4,0);
	PrintSList(SL);
	printf("删除第1个元素\n");
	printf("删除前:");
	PrintSList(SL);
	DeleteElem(SL,1,&e);
	printf("删除后:");
	PrintSList(SL);
	printf("删除的元素为:%d\n",e);

	return 0;
}
