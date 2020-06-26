#include<stdio.h>
#include"ULinkList.h"

int main(void)
{
	LinkList List;
	int a1[6] = {1,3,5,7,9,2};

	InitList(&List);
	InsertElem();
	//CreatUList(&List,6,a1);
	//DestroyList(&List);
	PrintUList(List);

	return 0;
}
