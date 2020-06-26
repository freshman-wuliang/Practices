#include<stdio.h>
#include"Polynomail.h"

int main(void)
{
	int a1[4][2] = {{1,0},{1,2},{2,3},{3,4}};
	int a2[6][2] = {{1,1},{1,2},{3,3},{2,4},{3,6},{6,7}};
	Polynomail p1,p2,p3;

	InitPolyn(&p1);
	InitPolyn(&p2);
	CreatPolyn(p1,4,a1);
	CreatPolyn(p2,6,a2);
	PrintPolyn(p1);
	PrintPolyn(p2);
	printf("ADD\n");
	//printf("%d\n%d",p1->next,p2->next);
	AddPolyn(&p1,&p2);
	PrintPolyn(p1);
	ConvertPolyn(p1);
	//PrintPolyn(p1);
	DestroyPolyn(&p1);
	DestroyPolyn(&p2);
	InitPolyn(&p1);
	InitPolyn(&p2);
	CreatPolyn(p1,4,a1);
	CreatPolyn(p2,6,a2);
	printf("\n\n");
	PrintPolyn(p1);
	PrintPolyn(p2);
	printf("SUBSTRACT\n");
	SubPolyn(&p1,&p2);
	PrintPolyn(p1);

	return 0;
}
