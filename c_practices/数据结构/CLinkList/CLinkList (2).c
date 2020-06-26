#include"CLinkList.h"

void InitCList(pCListNode *ppHeadNode)
{
	(*ppHeadNode) = (pCListNode)malloc(sizeof(CListNode));
	if(!(*ppHeadNode))
		exit(ERROR);
	(*ppHeadNode)->next = (*ppHeadNode);
}

void DestroyCList(pCListNode *ppHeadNode)
{
	pCListNode p,q;

	if(!(*ppHeadNode))
		exit(ERROR);

	p = (*ppHeadNode)->next;
	while(p != (*ppHeadNode))
	{
		q = p->next;
		free(p);
		p = q;
	}

	free(p);
	(*ppHeadNode) = NULL;
}

void ClearCList(pCListNode pHeadNode)
{
	pCListNode p,q;

	if(!pHeadNode)
		exit(ERROR);

	p = pHeadNode->next;
	if(p == pHeadNode)
		return;

	while(p->next != pHeadNode)
	{
		q = p->next;
		free(p);
		p = q;
	}
	free(p);
	pHeadNode->next = pHeadNode;
}

int CListEmpty(pCListNode pHeadNode)
{
	if(!pHeadNode)
		exit(ERROR);

	if(pHeadNode->next == pHeadNode)
		return 1;
	else
		return 0;
}

Status GetElem(pCListNode pHeadNode,int i,int *e)
{
	int j;
	pCListNode p;

	if(!pHeadNode)
		return FALSE;

	if(i<1)
		return FALSE;

	if(pHeadNode->next == pHeadNode)
		return FALSE;

	p = pHeadNode->next;

	for(j=0;j<i-1;j++)
	{
		if(p->next == pHeadNode)
			break;
		p = p->next;
	}

	if(j != i-1)
		return FALSE;

	*e = p->data;

	return OK;
}

Status LocateElem(pCListNode pHeadNode,int e)
{
	int count = 1;
	pCListNode p;

	if(!pHeadNode)
		return FALSE;

	p = pHeadNode->next;
	while(p != pHeadNode)
	{
		if(p->data == e)
			break;
		p = p->next;
		count++;
	}
	if(p == pHeadNode)
		return FALSE;
	else
		return count;
}

Status InsertElem(pCListNode pHeadNode,int i,int e)
{
	pCListNode p,q;
	int j;

	if(!pHeadNode)
		return FALSE;

	if(i < 1)
		return FALSE;

	p = pHeadNode;
	for(j=0;j<i-1;j++)
	{
		if(p->next == pHeadNode)
			break;
		p = p->next;
	}

	if(j != i-1)
		return FALSE;
	else
	{
		q = (pCListNode)malloc(sizeof(CListNode));
		q->data = e;
		q->next = p->next;
		p->next = q;
		return OK;
	}
}

Status DeleteElem(pCListNode pHeadNode,int i,int *e)
{
	pCListNode p,q;
	int j;

	if(!pHeadNode)
		return FALSE;

	if(pHeadNode->next == pHeadNode)
		return FALSE;

	p = pHeadNode;
	for(j=0;j<i-1;j++)
	{
		if(p->next == pHeadNode)
			break;
		p = p->next;
	}

	if(p->next == pHeadNode)
		return FALSE;
	else
	{
		q = p->next;
		*e = q->data;
		p->next = q->next;
		free(q);
		return OK;
	}
}

void CreatCList(pCListNode *ppHeadNode,int num,int array[])
{
	InitCList(ppHeadNode);

	for(int i=0;i<num;i++)
	{
		if(!InsertElem(*ppHeadNode,i+1,array[i]))
			return;
	}
}

void PrintCList(pCListNode pHeadNode)
{
	pCListNode p;

	if(!pHeadNode)
	{
		printf("ERROR\n");
		return;
	}

	if(pHeadNode->next == pHeadNode)
	{
		printf("Empty\n");
		return;
	}

	p = pHeadNode->next;

	while(p != pHeadNode)
	{
		printf(" %d",p->data);
		p = p->next;
	}
	putchar('\n');
}
