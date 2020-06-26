#include"SLinkList.h"

void InitSList(SLinkList SL)
{
	for(int i=2;i<=MAXSIZE-2;i++)
		SL[i-1].cur = i;
	SL[0].cur = 0;
	SL[MAXSIZE-2].cur = 0;
	SL[MAXSIZE-1].cur = 1;
}

void DestroySList(SLinkList SL)
{
	SL[0].cur = 0;
	SL[MAXSIZE-1].cur = 0;
}

int Malloc(SLinkList SL)
{
	int point;

	if(SL[MAXSIZE-1].cur)
	{
		point = SL[MAXSIZE-1].cur;
		SL[MAXSIZE-1].cur = SL[point].cur;
	}
	else
		point = 0;
	return point;
}

void Free(SLinkList SL,int cur)
{
	SL[cur].cur = SL[MAXSIZE-1].cur;
	SL[MAXSIZE-1].cur = cur;
}

Status ClearSList(SLinkList SL)
{
	int p,q;

	if(!SL[0].cur && !SL[MAXSIZE-1].cur)
		return FALSE;

	p = SL[0].cur;
	while(p)
	{
		q = SL[p].cur;
		Free(SL,p);
		p = q;
	}

	SL[0].cur = 0;

	return OK;
}

Status SListEmpty(SLinkList SL)
{
	if(!SL[0].cur && !SL[MAXSIZE-1].cur)
		exit(ERROR);

	if(!SL[0].cur)
		return 1;
	else
		return 0;
}

Status SListLength(SLinkList SL)
{
	int count = 0;
	int p;

	if(!SL[0].cur && !SL[MAXSIZE-1].cur)
		exit(ERROR);
	p = SL[0].cur;
	
	while(p)
	{
		count++;
		p = SL[p].cur;
	}

	return count;
}

Status GetElem(SLinkList SL,int i,int *e)
{
	int p;
	int j;

	if(!SL[0].cur && !SL[MAXSIZE-1].cur)
		return FALSE;
	if(!SL[0].cur)
		return FALSE;
	p = SL[0].cur;
	j = 0;
	while(p && j<i-1)
	{
		p = SL[p].cur;
		j++;
	}

	if(!p)
		return FALSE;

	*e = SL[p].data;
	return OK;
}

Status InsertElem(SLinkList SL,int i,int e)
{
	int p,q;
	int j;

	if(!SL[0].cur && !SL[MAXSIZE-1].cur)
		return FALSE;
	if(!SL[MAXSIZE-1].cur)
		return FALSE;
	if(i < 1)
		return FALSE;

	if(i == 1)
	{
		p = 0;
		q = Malloc(SL);
		SL[q].cur = SL[p].cur;
		SL[q].data = e;
		SL[p].cur = q;
		return OK;
	}
	else
	{
		p = SL[0].cur;
		for(j=0;j<i-2;j++)
		{
			if(!p)
				break;
			p = SL[p].cur;
		}
		if(!p)
			return FALSE;
		q = Malloc(SL);
		SL[q].cur = SL[p].cur;
		SL[q].data = e;
		SL[p].cur = q;
		return OK;
	}
}

Status DeleteElem(SLinkList SL,int i,int *e)
{
	int p,q;
	int j;

	if(!SL[0].cur && !SL[MAXSIZE-1].cur)
		return FALSE;
	if(!SL[0].cur)
		return FALSE;
	if(i < 1)
		return FALSE;
	if(i == 1)
	{
		p = 0;
		q = SL[p].cur;
		SL[p].cur = SL[q].cur;
		*e = SL[q].data;
		Free(SL,q);
		return OK;
	}
	else
	{
		p = SL[0].cur;
		for(j=0;j<i-2;j++)
		{
			if(!p)
				break;
			p = SL[p].cur;
		}
	}
	if(!p || !SL[p].cur)
		return FALSE;
	q = SL[p].cur;
	*e = SL[q].cur;
	SL[p].cur = SL[q].cur;
	Free(SL,q);
	return OK;
}

Status CreatSList(SLinkList SL,int num,int array[])
{
	if(!SL[0].cur && !SL[MAXSIZE-1].cur)
		return FALSE;
	if(!SL[MAXSIZE-1].cur)
		return FALSE;
	for(int i=0;i<num;i++)
	{
		if(!InsertElem(SL,i+1,array[i]))
			return FALSE;
	}
	return OK;
}

void PrintSList(SLinkList SL)
{
	int p;

	if(!SL[0].cur && !SL[MAXSIZE-1].cur)
	{
		printf("ERROR\n");
		return;
	}
	if(!SL[0].cur)
	{
		printf("Empty\n");
		return;
	}
	
	p = SL[0].cur;
	while(p)
	{
		printf(" %d",SL[p].data);
		p = SL[p].cur;
	}
	putchar('\n');
}
