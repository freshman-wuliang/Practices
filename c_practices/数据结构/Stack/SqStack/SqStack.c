#include"SqStack.h"

Status InitStack(pSqStack pS)
{
	pS->base = (int*)malloc(STACK_INIT_SIZE*sizeof(int));
	if(!pS->base)
		exit(OVERFLOW);
	pS->top = pS->base;
	pS->StackSize = STACK_INIT_SIZE;
	pS->flag = 0;
	return OK;
}

Status DestroyStack(pSqStack pS)
{
	if(!pS->base || !pS->top)
		return FALSE;

	free(pS->base);
	pS->base = NULL;
	pS->top = NULL;

	return OK;
}

Status ClearStack(pSqStack pS)
{
	if(!pS->top || !pS->base)
		return FALSE;
	pS->top = pS->base;
	pS->StackSize = STACK_INIT_SIZE + (pS->flag * STACK_INCREMENT);

	return OK;
}

Status StackEmpty(SqStack S)
{
	if(!S.top || !S.base)
		exit(ERROR);
	if(S.top == S.base)
		return 1;
	else
		return 0;
}

int StackLength(SqStack S)
{
	int len;

	if(!S.top || !S.base)
		exit(ERROR);

	len = (S.top - S.base);

	return len;
}

Status GetTop(SqStack S,int *e)
{
	if(!S.top || !S.base)
		return FALSE;
	if(S.top == S.base)
		return FALSE;

	*e = *(S.top - 1);

	return OK;
}

Status Push(pSqStack pS,int e)
{
	int len;

	if(!pS->top || !pS->base)
		return FALSE;

	len = pS->top - pS->base;
	if(pS->StackSize == 1)
	{
		pS->base = (int*)realloc(pS->base,((STACK_INIT_SIZE+pS->flag*STACK_INCREMENT)+STACK_INCREMENT)*sizeof(int));
		if(!pS->base)
			exit(OVERFLOW);
		pS->flag++;
		pS->StackSize = STACK_INCREMENT+1;
		pS->top = pS->base+len;
	}

	*pS->top = e;
	pS->top++;
	pS->StackSize--;

	return OK;
}

Status Pop(pSqStack pS,int *e)
{
	if(!pS->top || !pS->base)
		return FALSE;
	if(pS->top == pS->base)
		return FALSE;

	*e = *(pS->top - 1);
	pS->top--;
	pS->StackSize++;

	return OK;
}

void CreatStack(pSqStack pS,int num,int array[])
{
	InitStack(pS);

	for(int i=0;i<num;i++)
		Push(pS,array[i]);
}

void PrintStack(SqStack S)
{
	int *p;

	if(!S.base || !S.top)
	{
		printf("NULL\n");
		return;
	}
	if(S.base == S.top)
	{
		printf("Empty\n");
		printf("剩余容量为:%d\n",S.StackSize);
		return;
	}

	p = S.base + 1;
	printf("剩余容量为:%d\n",S.StackSize);
	printf("|%d",*S.base);
	while(p != S.top)
	{
		printf(" %d",*p);
		p++;
	}
	putchar('\n');
}
