#include<stdio.h>
#include"LinkStack.h"

int Test(int a,int b);

int main(void)
{
	int c;
	int e;
	Stack S;

	InitStack(&S);

	while((c = getchar()) != '\n')
	{
		switch(c)
		{
			case '(':
		       	case '[':
			case '{':
				Push(&S,c);
				break;
			case ')':
			case ']':
			case '}':
				GetTop(S,&e);
				if(!StackEmpty(S) && Test(c,e))
				{
					Pop(&S,&e);
					break;
				}
				else
				{
					Push(&S,c);
					break;
				}
			default :
			       break;	
		}
	}
	if(StackEmpty(S))
		printf("匹配\n");
	else
		printf("不匹配\n");

	return 0;
}

int Test(int a,int b)
{
	switch(a)
	{
		case ')' : 
			if(b == '(')
				return 1;
			else
				return 0;
		case ']' :
			if(b == '[')
				return 1;
			else
				return 0;
		case '}' : 
			if(b == '{')
				return 1;
			else
				return 0;
		default :
			return 0;
	}
}
