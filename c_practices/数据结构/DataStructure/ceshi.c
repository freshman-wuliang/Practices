#include<stdio.h>
#include"datastr.h"

int main(void)
{
	SLinkList list;
	SLListType elem[] = {1,2,3,4,5,6};
	
	initSLinkList(&list);
	printSLinkList(list);
	creatSLinkList(list,6,elem);
	printSLinkList(list);
	clearSLinkList(list);
	printSLinkList(list);
	destroySLinkList(&list);
	
	return 0;
}

