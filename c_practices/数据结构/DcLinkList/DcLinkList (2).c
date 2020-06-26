#include"DcLinkList.h"

void InitDcList(pDcLNode *ppHeadNode)
{
	(*ppHeadNode) = (pDcLNode)malloc(sizeof(DcLNode));

	if(!(*ppHeadNode))
		exit(OVERFLOW);
	(*ppHeadNode)->prior = (*ppHeadNode);
	(*ppHeadNode)->next = (*ppHeadNode);
}

Status DestroyDcList(pDcLNode *ppHeadNode)
{
	pDcLNode p;

	if(!(*ppHeadNode))
		return FALSE;

	p = (*ppHeadNode);

	while(p->next != (*ppHeadNode))
	{
		p = p->next;
		(*ppHeadNode)->next = p->next;
		free(p);
		p = (*ppHeadNode)->next;
	}
	free(p);

	if(p != *ppHeadNode)
		free(*ppHeadNode);
	(*ppHeadNode) = NULL;

	return OK;
}

Status ClearDcList(pDcLNode pHeadNode)
{
	pDcLNode p;

	if(!pHeadNode)
		return FALSE;

	p = pHeadNode->next;

	while(p != pHeadNode)
	{
		pHeadNode->next = p->next;
		free(p);
		p = pHeadNode->next;
	}

	pHeadNode->prior = pHeadNode;
	pHeadNode->next = pHeadNode;

	return OK;
}

Status DcListEmpty(pDcLNode pHeadNode)
{
	if(!pHeadNode)
		exit(ERROR);

	if(pHeadNode->next == pHeadNode)
		return 1;
	else
		return 0;
}

Status GetElem(pDcLNode pHeadNode,int i,int *e)
{
	pDcLNode p;
	int j;

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

Status LocateElem(pDcLNode pHeadNode,int e)
{
	pDcLNode p;
	int count = 0;

	if(pHeadNode->next == pHeadNode)
		return FALSE;
	p = pHeadNode->next;
	while(p != pHeadNode)
	{
		count++;
		if(p->data == e)
			break;
		p = p->next;
	}

	if(p == pHeadNode)
		return FALSE;
	else
		return count;
}

Status InsertElem(pDcLNode pHeadNode,int i,int e)
{
	pDcLNode p,q;
	int j;

	if(!pHeadNode)
		return FALSE;
	if(i<1)
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

	q = (pDcLNode)malloc(sizeof(DcLNode));
	if(!q)
		exit(OVERFLOW);

	q->data = e;
	q->next = p->next;
	q->prior = p;
	p->next = q;
	q->next->prior = q;

	return OK;
}

Status DeleteElem(pDcLNode pHeadNode,int i,int *e)
{
	pDcLNode p,q;
	int j;

	if(pHeadNode->next == pHeadNode)
		return FALSE;

	if(i<1)
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

	q = p->next;
	*e = q->data;
	p->next = q->next;
	q->next->prior = p;
	free(q);

	return OK;
}

Status CreatDcList(pDcLNode pHeadNode,int num,int array[])
{
	for(int i=0;i<num;i++)
	{
		if(!InsertElem(pHeadNode,i+1,array[i]))
			return FALSE;
	}
	return OK;
}

void PrintDcList(pDcLNode pHeadNode)
{
	pDcLNode p;

	if(!pHeadNode)
	{
		printf("NULL\n");
		return;
	}

	if(pHeadNode->next == pHeadNode)
	{
		printf("Empty\n");
		return;
	}

	p = pHeadNode->next;

	while(p!= pHeadNode)
	{
		printf(" %d",p->data);
		p = p->next;
	}
	putchar('\n');
}


