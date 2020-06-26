#include<stdio.h>
#include"Stack.h"

#define N 10

int main(void)
{
	Stack s;
	StackElemType define[N] = {1,2,3,4,5,6,7,8,9,10};
	StackElemType elem;
	
	initStack(&s);
	createStack(&s,define,N);
	displayStack(s,ALL);
	//clearStack(&s);
	//displayStack(s,ALL);
	//printf("topElem:%d\n",getTop(s));
	pushStack(&s,11);
	displayStack(s,ALL);
	pushStack(&s,12);
	displayStack(s,ALL);
	pushStack(&s,13);
	displayStack(s,ALL);
	elem = popStack(&s);
	printf("elem:%d\n",elem);
	elem = popStack(&s);
	printf("elem:%d\n",elem);
	elem = popStack(&s);
	printf("elem:%d\n",elem);
	displayStack(s,ALL);
	
	destroyStack(&s);
	//printf("empty:%d\n",StackSize(s));
	//displayStack(s,PART);
	
	return 0;
}