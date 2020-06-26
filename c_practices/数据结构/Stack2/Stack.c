#include"Stack.h"

void initStack(Stack *ps)
{
	ps->base = (StackElemType *)malloc(DEFAULT_SIZE * sizeof(StackElemType));
	if(!ps->base)
	{
		printf("memory full\n");
		exit(1);
	}
	
	ps->top = ps->base;
	ps->ava_size = DEFAULT_SIZE;
	ps->add_count = 0;
}

void destroyStack(Stack *ps)
{
	free(ps->base);
	ps->base = NULL;
	ps->top = NULL;
	ps->ava_size = -1;
	ps->add_count = -1;
}

void clearStack(Stack *ps)
{
	if(!ps->base && !ps->top)
		return;
	
	ps->top = ps->base;
	ps->ava_size = (ps->add_count + 1) * DEFAULT_SIZE;
}

int emptyStack(Stack s)
{
	if(!s.base && !s.top)
	{
		return -1;
	}
	
	if(s.top == s.base)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int StackSize(Stack s)
{
	if(!s.base && !s.top)
		return -1;
	
	return s.top - s.base;
}

StackElemType getTop(Stack s)
{
	if(!s.base && !s.top)
		exit(1);
	
	if(s.top == s.base)
		return *(s.base);
	
	return *(s.top - 1);
}

void pushStack(Stack *ps,StackElemType elem)
{
	int tmp;
	StackElemType *ptmp;
	
	if(!ps->base && !ps->top)
		return;
	
	if(ps->ava_size <= 0)
	{
		tmp = ps->top - ps->base;
		ptmp = (StackElemType *)realloc(ps->base,((ps->add_count + 1) * DEFAULT_SIZE + ADD_SIZE) * sizeof(StackElemType));
		if(!ptmp)
		{
			printf("memory full\n");
			exit(1);
		}
		
		ps->base = ptmp;
		ps->top = ps->base + tmp;
		ps->ava_size = ADD_SIZE;
		ps->add_count++;
	}
	
	*(ps->top) = elem;
	ps->top++;
	ps->ava_size--;
}

StackElemType popStack(Stack *ps)
{
	StackElemType tmp;
	
	if(!ps->base && !ps->top)
		exit(1);
	
	if(ps->top == ps->base)
		return *(ps->base);
	
	tmp = *(ps->top - 1);
	ps->top--;
	ps->ava_size++;
	
	return tmp;
}

//assist function
void createStack(Stack *ps,StackElemType array[],int n)
{
	if(emptyStack(*ps) == -1)
		return;
	
	for(int i=1;i<=n;i++)
	{
		pushStack(ps,array[i-1]);
	}
}

void displayStack(Stack s,int flag)
{
	printf("stack:");
	if(emptyStack(s) == -1)
	{
		printf("destroyed\n");
	}
	else if(emptyStack(s) == 1)
	{
		printf("empty\n");
	}
	else
	{
		printf("|");
		for(StackElemType *p = s.base;p <= s.top - 1;p++)
		{
			printf("%d ",*p);
		}
		printf("|\n");
		
	}
	
	if(flag == ALL)
	{
		printf("stack.base:0x%p\n",s.base);
		printf("stack.top:0x%p\n",s.top);
		printf("stack.ava_size:%d\n",s.ava_size);
		printf("stack.add_count:%d\n",s.add_count);
	}
}