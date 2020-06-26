#include<stdio.h>
#include"Triplet.h"

int main(void)
{
	Triplet t;
	int e;

	InitTriplet(&t,1,2,3);
	PrintTriplet(t);
	Get(t,2,&e);
	printf("Triplet's secend value is %d\n",e);
	printf("change Triplet's secend value to 0:\n");
	Put(&t,2,0);
	PrintTriplet(t);
	printf("InitTriplet with 1 2 3\n");
	InitTriplet(&t,1,2,3);
	PrintTriplet(t);
	if(IsAscending(t))
	{
		printf("Triplet is Ascending\n");
	}
	else
	{
		printf("Triplet is not Ascending\n");
	}
	if(IsDescending(t))
	{
		printf("Triplet is Descending\n");
	}
	else
	{
		printf("Triplet is not Descending\n");
	}
	Max(t,&e);
	printf("Triplet's max value is %d\n",e);
	Min(t,&e);
	printf("Triplet's min value is %d\n",e);


	return 0;
}
