#include<stdio.h>
#include<stdlib.h>
#include"config.h"

typedef int ElemType;

typedef struct ListNode
{
	ElemType data;
	struct ListNode *next;
}ListNode,*pListNode;

typedef pListNode LinkList;

Status InitList(LinkList *pL);   //初始化

int Length(LinkList L);   //求表长

int LocateElem(LinkList L,ElemType e);   //定位

ElemType GetElem(LinkList L,int n);   //取i位元素

Status DestroyList(LinkList *pL);   //销毁

void PrintList(LinkList L);   //输出表

int Empty(LinkList L);   //判空

Status CreatList(LinkList L,int n,ElemType array[]);   //创建表，尾插法

Status CreatList2(LinkList L,int n,ElemType array[]);   //头插法

Status DeleteList(LinkList L,int n,ElemType *e);   //删除元素

Status InsertList(LinkList L,int n,ElemType e);   //插入元素

int main(void)   //主函数
{
	LinkList L;
	int array[6] = {1,2,3,4,5,6};
	int n = 6;
	ElemType e;
	
	InitList(&L);
	CreatList(L,n,array);
	PrintList(L);
	e = GetElem(L,2);
	printf("%d\n",e);
	DestroyList(&L);
	
	return 0;
}

Status InitList(LinkList *pL)
{
	(*pL) = (pListNode)malloc(sizeof(ListNode));
	if(!(*pL))
		return FALSE;
	
	(*pL)->next = NULL;
	
	return OK;
}

Status DestroyList(LinkList *pL)
{
	pListNode p = NULL,q = NULL;
	
	p = (*pL)->next;
	
	while(p->next)
	{
		q = p->next;
		free(p);
		p = q;
	}
	free(p);
	free((*pL));
	(*pL) = NULL;
	
	return OK;
}

Status CreatList(LinkList L,int n,ElemType array[])
{
	pListNode p = NULL,q = NULL;
	
	if(!L || L->next)
		return FALSE;
	
	p = L;
	for(int i=1;i<=n;i++)
	{
		q = (pListNode)malloc(sizeof(ListNode));
		if(!q)
			return FALSE;
		
		q->data = array[i-1];
		q->next = NULL;
		p->next = q;
		p = q;
	}
	
	return OK;
}

Status CreatList2(LinkList L,int n,ElemType array[])
{
	pListNode p = NULL;
	
	if(!L || L->next)
		return FALSE;
	
	for(int i=1;i<=n;i++)
	{
		p = (pListNode)malloc(sizeof(ListNode));
		if(!p)
			return FALSE;
		
		p->data = array[i-1];
		p->next = L->next;
		L->next = p;
	}
	
	return OK;
}

void PrintList(LinkList L)
{
	pListNode p = NULL;
	
	if(!L)
	{
		printf("Destroyed!\n");
		return;
	}
	
	if(!L->next)
	{
		printf("EMPTY!\n");
		return;
	}
	
	p = L->next;
	while(p)
	{
		printf("%d ",p->data);
		p = p->next;
	}
	putchar('\n');
	
}

Status InsertList(LinkList L,int n,ElemType e)
{
	pListNode p = NULL,q = NULL;
	int i = 1;
	
	if(!L || n < 1)
		return FALSE;
	
	p = L;
	while(p && i <= n-1)
	{
		p = p->next;
		i++;
	}
	
	if(!p)
		return FALSE;
	q = (pListNode)malloc(sizeof(ListNode));
	if(!q)
		return FALSE;
	q->data = e;
	q->next = p->next;
	p->next = q;
	
	return OK;
}

Status DeleteList(LinkList L,int n,ElemType *e)
{
	pListNode p = NULL,q = NULL;
	int i = 1;
	
	if(!L || !L->next)
		return FALSE;
	
	if(n < 1)
		return FALSE;
	
	p = L;
	
	while(p && i <= n-1)
	{
		p = p->next;
		i++;
	}
	
	if(!p->next)
		return FALSE;
	
	q = p->next;
	(*e) = q->data;
	p->next = q->next;
	free(q);
	
	return OK;
}

int Length(LinkList L)
{
	int count = 0;
	pListNode p = NULL;
	
	if(!L)
		return -1;
	
	p = L->next;
	
	while(p)
	{
		count++;
		p = p->next;
	}
	
	return count;
}

int LocateElem(LinkList L,ElemType e)
{
	pListNode p = NULL;
	int count = 1;
	
	if(!L)
		return 0;
	
	p = L->next;
	
	while(p && p->data != e)
	{
		count++;
		p = p->next;
	}
	
	if(!p)
		return 0;
	else
		return count;
}

ElemType GetElem(LinkList L,int n)
{
	pListNode p = NULL;
	int i = 1;
	
	if(!L || !L->next)
		exit(1);
	
	p = L->next;
	
	while(p && i < n)
	{
		i++;
		p = p->next;
	}
	
	if(!p)
		return 0;
	else
		return p->data;
}
