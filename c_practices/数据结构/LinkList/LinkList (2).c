#include"LinkList.h"

Status InitLinkList(pListNode *ppHeadNode)
{
	(*ppHeadNode) = (pListNode)malloc(1 * sizeof(ListNode));

	if(!(*ppHeadNode))
		exit(OVERFLOW);

	(*ppHeadNode)->next = NULL;
	return OK;
}

Status DestroyLinkList(pListNode *ppHeadNode)
{
	if(!(*ppHeadNode))
		exit(ERROR);

	ClearLinkList(*ppHeadNode);   //销毁之前先清空
	free(*ppHeadNode);   //释放头结点的内存
	*ppHeadNode = NULL;
	return OK;
}

Status ClearLinkList(pListNode pHeadNode)
{
	pListNode p,q;   //辅助指针

	if(!pHeadNode)
		exit(ERROR);

	p = pHeadNode->next;   //p指向第一个节点
	pHeadNode->next = NULL;   //头结点的next变成NULL

	while(p->next)
	{
		q = p->next;   //q保存p的next指针
		free(p);
		p = q;
	}
	free(p);   //释放最后一个节点
	
	return OK;
}

Status ListEmpty(pListNode pHeadNode)
{
	if(!pHeadNode)
		exit(ERROR);
	if(!pHeadNode->next)
		return 1;
	else 
		return 0;
}

Status ListLength(pListNode pHeadNode)
{
	int count = 0;   //计数器
	pListNode p;   //后推指针

	if(!pHeadNode)
		exit(ERROR);

	p = pHeadNode->next;

	while(p)
	{
		count++;
		p = p->next;
	}

	return count;
}

Status GetElem(pListNode pHeadNode,int i,int *e)
{
	pListNode p;
	int j;

	if(!pHeadNode)
		exit(ERROR);
	if(i < 1)
		return FALSE;

	p = pHeadNode;
	if(!p->next)
		return FALSE;

	for(j=0;j<i;j++)
	{
		p = p->next;
		if(!p)
			break;
	}
	if(j == i)
	{
		*e = p->data;
		return OK;
	}
	else
		return FALSE;
}

Status LocateElem(pListNode pHeadNode,int e)
{
	pListNode p;
	int count = 0;

	if(!pHeadNode)
		exit(ERROR);
	if(!pHeadNode->next)
		return FALSE;

	p = pHeadNode->next;
	count++;

	while(p)
	{
		if(p->data == e)
			break;
		p = p->next;
		count++;
	}

	if(!p)
		return FALSE;
	else
		return count;
}

Status InsertElem(pListNode pHeadNode,int i,int e)
{
	pListNode p,q,r;
	int j = 0;

	if(!pHeadNode)
		exit(ERROR);

	if(i < 1)
		return FALSE;
	p = pHeadNode;

	for(j=0;j<i-1;j++)
	{
		if(!p->next)
			break;
		p = p->next;
	}

	if(j != i-1)
		return FALSE;

	r = (pListNode)malloc(1 * sizeof(ListNode));
	r->data = e;
	q = p->next;
	p->next = r;
	r->next = q;

	return OK;
}

Status DeleteElem(pListNode pHeadNode,int i,int *e)
{
	pListNode p,q;
	int j;

	if(!pHeadNode)
		exit(ERROR);
	if(i < 1)
		return FALSE;

	p = pHeadNode;
	for(j=0;j<i-1;j++)
	{
		if(!p->next)
			break;
		p = p->next;
	}
	if(j!=i-1 || !p->next)
		return FALSE;

	q = p->next;
	*e = q->data;
	p->next = q->next;
	free(q);

	return OK;
}

Status CreatLinkList(pListNode *ppHeadNode,int num,int array[])
{
	InitLinkList(ppHeadNode);
	if(num < 0)
		return FALSE;
	for(int i=0;i<num;i++)
		InsertElem(*ppHeadNode,i+1,array[i]);
	return OK;
}

void PrintLinkList(pListNode pHeadNode)
{
	pListNode p;
	if(!pHeadNode)
		exit(ERROR);
	if(!pHeadNode->next)
	{
		printf("EMPTY\n");
		return;
	}

	p = pHeadNode;
	while(p->next)
	{
		p = p->next;
		printf(" %d",p->data);
	}
	putchar('\n');
}

void UnionLinkList(pListNode pHeadNode1,pListNode pHeadNode2,pListNode pHeadNode3)
{
	pListNode p;
	int k = 0;

	if(!pHeadNode1 || !pHeadNode2 || !pHeadNode3)
		exit(ERROR);

	p = pHeadNode1->next;
	while(p)   //复制表1到表3
	{
		InsertElem(pHeadNode3,++k,p->data);
		p = p->next;
	}

	p = pHeadNode2->next;
	while(p)
	{
		if(!LocateElem(pHeadNode1,p->data))
			InsertElem(pHeadNode3,++k,p->data);
		p = p->next;
	}
}

void MergeLinkList(pListNode *ppHeadNode1,pListNode *ppHeadNode2,pListNode *ppHeadNode3)
{
	pListNode p,q,r;

	if(!*ppHeadNode1 || !*ppHeadNode2)
		exit(ERROR);

	p = (*ppHeadNode1)->next;
	q = (*ppHeadNode2)->next;
	r = *ppHeadNode1;

	(*ppHeadNode3) = (*ppHeadNode1);
	free(*ppHeadNode2);
	*ppHeadNode2 = NULL;
	*ppHeadNode1 = NULL;

	while(p && q)
	{
		if(p->data <= q->data)
		{
			r->next = p;
			p = p->next;
			r = r->next;
		}
		else
		{
			r->next = q;
			q = q->next;
			r = r->next;
		}
	}

	if(!p)
		r->next = q;
	if(!q)
		r->next = p;
}
