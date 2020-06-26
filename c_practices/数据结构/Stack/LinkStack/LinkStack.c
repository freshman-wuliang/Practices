#include"LinkStack.h"

Status InitStack(pStack pS)
{
	pS->base = (pSNode)malloc(sizeof(SNode));
	if(!pS->base)
		exit(OVERFLOW);

	pS->base->next = NULL;
	pS->top = pS->base;
}

Status DestroyStack(pStack pS)
{
	pSNode p;

	if(!pS->top || !pS->base)
	
		return FALSE;
	if(pS->top == pS->base)
	{
		free(pS->base);
		pS->base = NULL;
		pS->top = NULL;
		return OK;
	}

	pS->base = pS->top;
	while(pS->base)
	{
		pS->top = pS->base->next;
		free(pS->base);
		pS->base = pS->top;
	}
}

Status ClearStack(pStack pS)
{
	pSNode p,q;

	if(!pS->top || !pS->base)
		return FALSE;
	if(pS->top == pS->base)
		return OK;

	p = pS->top;
	q = p->next;
	while(q)
	{
		free(p);
		p = q;
		q = q->next;
	}
	pS->top = pS->base;

	return OK;
}

Status StackEmpty(Stack S)
{
	if(!S.top || !S.base)
		exit(ERROR);
	if(S.base == S.top)
		return 1;
	else
		return 0;
}

int StackLength(Stack S)
{
	pSNode p;
	int count = 0;

	if(!S.top || !S.base)
		exit(ERROR);

	p = S.top;
	while(p != S.base)
	{
		count++;
		p = p->next;
	}

	return count;
}

Status GetTop(Stack S,int *e)
{
	if(!S.base || !S.top)
		return FALSE;
	if(S.base == S.top)
		return FALSE;

	*e =S.top->data;
	return OK;
}

Status Push(pStack pS,int e)
{
	pSNode p;

	if(!pS->top || !pS->base)
		return FALSE;

	p = (pSNode)malloc(sizeof(SNode));
	if(!p)
		exit(OVERFLOW);

	p->data = e;
	p->next = pS->top;
	pS->top = p;

	return OK;
}

Status Pop(pStack pS,int *e)
{
	pSNode p;

	if(!pS->base || !pS->top)
		return FALSE;
	if(pS->base == pS->top)
		return FALSE;

	*e = pS->top->data;
	p = pS->top;
	pS->top = pS->top->next;
	free(p);

	return OK;
}

void CreatStack(pStack pS,int num,int array[])
{
	InitStack(pS);

	for(int i=0;i<num;i++)
		Push(pS,array[i]);
}

void PrintStack(Stack S)
{
	pSNode p;

	if(!S.base || !S.top)
	{
		printf("NULL\n");
		return;
	}
	if(S.base == S.top)
	{
		printf("Empty\n");
		return;
	}
	printf("|%d",S.top->data);
	p = S.top->next;
	while(p != S.base)
	{
		printf(" %d",p->data);
		p = p->next;
	}
	putchar('\n');
}
