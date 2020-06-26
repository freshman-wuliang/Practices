#include"LinkList.h"

/*initSLinkList*/
void initSLinkList(SLinkList *ptlist)
{
	(*ptlist) = (PLinkNode)malloc(sizeof(LinkNode));
	if(!(*ptlist))
	{
		exit(1);
	}
	
	(*ptlist)->next = NULL;
}

/*destroySLinkList*/
void destroySLinkList(SLinkList *ptlist)
{
	PLinkNode p,q;
	
	if(!(*ptlist))
		return;
	
	p = *ptlist;
	q = p->next;
	while(q)
	{
		free(p);
		p = q;
		q = p->next;
	}
	free(p);
	*ptlist = NULL;
}

/*creatSLinkList*/
void creatSLinkList(SLinkList list,int list_len,SLListType elem[])
{
	PLinkNode p,q;
	
	if(!list)
		return;
	
	if(list->next)
		return;
	
	p = list;
	for(int i=1;i<=list_len;i++)
	{
		q = (PLinkNode)malloc(sizeof(LinkNode));
		if(!q)
		{
			exit(1);
		}
		
		q->elem = elem[i-1];
		q->next = NULL;
		
		p->next = q;
		p = q;
	}
}

/*printSLinkList*/
void printSLinkList(SLinkList list)
{
	PLinkNode p;
	
	if(list == NULL)
	{
		printf("Single LinkList is destroyed\n");
		return;
	}
	
	if(list->next == NULL)
	{
		printf("Single LinkList is empty\n");
		return;
	}
	
	p = list->next;
	printf("SLinkList:");
	while(p)
	{
		printf("%d ",p->elem);
		p = p->next;
	}
	printf("\n");
}

/*clearSLinkList*/
void clearSLinkList(SLinkList list)
{
	PLinkNode p,q;
	
	if(!list)
		return;
	
	p = list->next;
	while(p)
	{
		q = p->next;
		free(p);
		p = q;
	}
	
	list->next = NULL;
}

/*SLinkListLength*/
int SLinkListLength(SLinkList list)
{
	
}

//sngSLinkList

//SLinkList end