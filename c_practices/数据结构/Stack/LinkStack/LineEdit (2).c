#include<stdio.h>
#include"LinkStack.h"

int main(void)
{
	Stack S;
	int ch;

	InitStack(&S);
	ch = getchar();

	while(ch != EOF)
	{
		while(ch != EOF && ch != '\n')
		{
			switch(ch)
			{
				case '#' : Pop(&S,&ch);break;
				case '@' : ClearStack(&S);break;
				default  : Push(&S,ch);
			}
			ch = getchar();
		}
		PrintStack(S);
		ClearStack(&S);
		if(ch != EOF)
			ch = getchar();
	}
	DestroyStack(&S);
}
