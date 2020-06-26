#include"Triplet.h"

Status InitTriplet(pTriplet pt,int v1,int v2,int v3)
{
	pt->v1 = v1;
	pt->v2 = v2;
	pt->v3 = v3;

	return OK;
}

Status Get(Triplet t,int i,int *e)
{
	if(i<1 || i>3)
	{
		return ERROR;
	}

	switch(i)
	{
		case 1 : *e = t.v1;break;
		case 2 : *e = t.v2;break;
		default : *e = t.v3;
	}

	return OK;
}

Status Put(pTriplet pt,int i,int e)
{
	if(i<1 || i>3)
	{
		return ERROR;
	}

	switch(i)
	{
		case 1 : pt->v1 = e;
		case 2 : pt->v2 = e;
		default : pt->v3;
	}

	return OK;
}

Status IsAscending(Triplet t)
{
	if(t.v1<=t.v2 && t.v2<=t.v3)
	{
		return 1;
	}
	else
		return 0;
}

Status IsDescending(Triplet t)
{
	if(t.v1>=t.v2 && t.v2>t.v3)
	{
		return 1;
	}
	else
		return 0;
}

Status Max(Triplet t,int *e)
{
	*e = t.v1;
	if(*e < t.v2)
	{
		*e = t.v2;
	}
	if(*e <t.v3)
	{
		*e = t.v3;
	}

	return OK;
}

Status Min(Triplet t,int *e)
{
	*e = t.v1;
	if(*e > t.v2)
	{
		*e = t.v2;
	}
	if(*e > t.v3)
	{
		*e = t.v3;
	}
	return OK;
}

void PrintTriplet(Triplet t)
{
	printf("Triplet is (%d,%d,%d)\n",t.v1,t.v2,t.v3);
}
