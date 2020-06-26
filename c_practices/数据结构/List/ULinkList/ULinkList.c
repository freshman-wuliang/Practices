#include"ULinkList.h"

Status MakeNode(pListNode *ppNode,int e)
{
	(*ppNode) = (pListNode)malloc(sizeof(ListNode));

	if(!(*ppNode))
		return FALSE;

	(*ppNode)->data = e;
	(*ppNode)->next = NULL;

	return OK;
}

Status FreeNode(pListNode *ppNode)
{
	if(!(*ppNode))
		return FALSE;

	free(*ppNode);
	(*ppNode) = NULL;

	return OK;
}

Status InitList(pLinkList pList)
{
	pList->head = (pListNode)malloc(sizeof(ListNode));
	if(!pList->head)
		return FALSE;

	pList->head->next = NULL;
	pList->tail = pList->head;
	pList->len = 0;

	return OK;
}

Status DestroyList(pLinkList pList)
{
	pListNode p,q;

	if(!pList->head || !pList->tail)
		return FALSE;

	p = pList->head;
	while(p)
	{
		q = p->next;
		free(p);
		p = q;
	}

	pList->head = NULL;
	pList->tail = NULL;

	return OK;
}

Status CleadList(pLinkList pList)
{
	pListNode p,q;

	if(!pList->head || !pList->tail)
		return FALSE;

	p = pList->head->next;
	while(p)
	{
		q = p->next;
		free(p);
		p = q;
	}

	pList->tail = pList->head;
	pList->len = 0;

	return OK;
}

Status InsFirst(pLinkList pList,pListNode s)
{
	if(!pList->head || !s)
		return FALSE;

	s->next = pList->head->next;
	pList->head->next = s;

	pList->len++;

	if(!s->next)
		pList->tail = s;

	return OK;
}

Status DelFirst(pLinkList pList)
{
	pListNode p;

	if(!pList->head || !pList->head->next)
		return FALSE;

	p = pList->head->next;
	pList->head->next = p->next;

	if(!p->next)
		pList->tail = pList->head;

	free(p);
	pList->len--;

	return OK;
}

Status Append(pLinkList pList,pListNode s)
{
	int count = 0;
	pListNode p;

	if(!pList->head)
		return FALSE;

	if(!s)
		return OK;

	p = s;
	count = 1;
	while(p->next)
	{
		p = p->next;
		count++;
	}

	pList->tail->next = s;
	pList->tail = p;
	pList->len += count;

	return OK;
}

Status Remove(pLinkList pList)
{
	pListNode p;

	if(!pList->head)
		return FALSE;
	if(!pList->len)
		return OK;

	p = pList->head;
	for(int i=0;i<pList->len-1;i++)
	{
		p = p->next;
	}
	free(p->next);

	pList->tail = p;

	return OK;
}

Status InsBefore(pLinkList pList,pListNode p,pListNode s)
{
	pListNode q;

	if(!pList->head || !pList->len)
		return FALSE;

	if(!p)
		return FALSE;

	if(!s)
		return OK;

	q = pList->head;
	while(q && q->next != p)
	{
		q = q->next;
	}

	if(!q)
		return FALSE;
	q->next = s;
	s->next = p;
	pList->len++;

	return OK;
}

Status InsAfter(pLinkList pList,pListNode p,pListNode s)
{
	if(!pList->head || !pList->len)
		return FALSE;
	if(!p)
		return FALSE;
	if(!s)
		return OK;

	s->next = p->next;
	p->next = s;
	if(!s->next)
		pList->tail = s;
	pList->len++;

	return OK;
}

Status SetCurElem(pListNode p,int e)
{
	if(!p)
		return FALSE;

	p->data = e;

	return OK;
}

int GetCurElem(pListNode p)
{
	if(!p)
		exit(ERROR);

	return p->data;
}

Status ListEmpty(pLinkList pList)
{
	if(!pList->head)
		exit(ERROR);

	if(!pList->len)
		return 1;
	else
		return 0;
}

Position GetHead(pLinkList pList)
{
	return pList->head;
}

Position GetLast(pLinkList pList)
{
	return pList->tail;
}

Position PriorPos(pLinkList pList,pListNode p)
{
	pListNode q;

	if(!pList->head)
		return NULL;

	if(!p)
		return NULL;
	q = pList->head;
	while(q && q->next != p)
	{
		q = q->next;
	}

	if(!q)
		return FALSE;
	return q;
}

Position NextPos(pLinkList pList,pListNode p)
{
	if(!pList->head)
		return NULL;
	if(!p)
		return NULL;
	return p->next;
}

Status LocatePos(pLinkList pList,int i,pListNode *ppNode)
{
	if(!pList->head)
	{
		(*ppNode) = NULL;
		return FALSE;
	}
	if(i<1 || i>pList->len)
	{
		(*ppNode) = NULL;
		return FALSE;
	}

	(*ppNode) = pList->head;
	for(int j=0;j<i;j++)
	{
		(*ppNode) = (*ppNode)->next;
	}

	return OK;
}

Position LocateElem(pLinkList pList,int e)
{
	pListNode p;

	if(!pList->head || !pList->len)
		return NULL;

	p = pList->head->next;
	while(p && p->data != e)
	{
		p = p->next;
	}

	return p;
}

Status InsertElem(pLinkList pList,int i,int e)
{
	pListNode p,q;

	if(!LocatePos(pList,i-1,&p))
		return FALSE;
	if(!MakeNode(&q,e))
		return FALSE;
	InsAfter(pList,p,q);

	return OK;
}

void CreatUList(pLinkList pList,int num,int array[])
{
	InitList(pList);

	for(int i=0;i<num;i++)
		InsertElem(pList,i+1,array[i]);
}

void PrintUList(LinkList List)
{
	pListNode p;

	printf("List.head:%#x\n",List.head);
	printf("List.tail:%#x\n",List.tail);
	printf("List.len:%d\n",List.len);
	printf("the element of List is:");

	if(!List.head)
	{
		printf("NULL\n");
		return;
	}

	if(!List.len)
	{
		printf("Empty\n");
		return;
	}

	p = List.head->next;
	while(p)
	{
		printf(" %d",p->data);
		p = p->next;
	}
	putchar('\n');
}

/**************/
Status AscendUList(pLinkList pList)
{
	int i,j;
	pListNode p,q;

	if(!pList->head)
		return FALSE;
	if(!pList->len)
		return OK;

	for(i=1;i<=pList->len-1;i++)
	{
		for(j=1;j<=pList->len-1-i;j++)
		{
			if(!LocatePos(pList,j,&p))
				return FALSE;
			q = p->next;
			if(p->data > q->data)
				if(!ChangeOrd(pList,p,q))
					return FALSE;
		}
	}

	return OK;
}

Status ChangeOrd(pLinkList pList,pListNode p,pListNode q)
{
	pListNode bp;

	if(!p || !q)
		return FALSE;
	if(p->next != q)
		return FALSE;

	bp = PriorPos(pList,p);

	bp->next = p->next;
	p->next = q->next;
	q->next = p;

	return OK;
}
