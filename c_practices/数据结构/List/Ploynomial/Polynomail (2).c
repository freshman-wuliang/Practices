#include"Polynomail.h"

void InitPolyn(Polynomail *pp)
{
	(*pp) = (Polynomail)malloc(sizeof(ListNode));
	if(!(*pp))
		exit(ERROR);

	(*pp)->next = NULL;
}

void CreatPolyn(Polynomail p,int num,int array[][2])
{
	pListNode q,r;

	if(!p)
		return ;
	r = p;

	for(int i=0;i<num;i++)
	{
		q = (Polynomail)malloc(sizeof(ListNode));
		q->da.coef = array[i][0];
		q->da.expn = array[i][1];
		q->next = NULL;
		r->next = q;
		r = r->next;
	}
}

void PrintPolyn(Polynomail p)
{
	pListNode q;

	if(!p)
	{
		printf("NULL\n");
		return;
	}

	if(!p->next)
	{
		printf("Empty\n");
		return;
	}

	q = p->next;
	while(q->next)
	{
		printf("%-4.2fX^%2d+",q->da.coef,q->da.expn);
		q = q->next;
	}
	printf("%-4.2fX^%2d\n",q->da.coef,q->da.expn);
}

void DestroyPolyn(Polynomail *pp)
{
	pListNode p,q;

	if(!(*pp))
		return;
	if(!(*pp)->next)
	{
		free(*pp);
		(*pp) = NULL;
		return;
	}

	q = (*pp)->next;
	while(q)
	{
		p = q->next;
		free(q);
		q = p;
	}
	free(*pp);
	(*pp) = NULL;
}

void ConvertPolyn(Polynomail p)
{
	pListNode q;

	if(!p)
		return;

	q = p->next;
	while(q)
	{
		q->da.coef = -q->da.coef;
		q = q->next;
	}
}

int PolynLength(Polynomail p)
{
	int count = 0;
	pListNode q;

	if(!p)
		exit(ERROR);

	q = p->next;
	while(q)
	{
		count++;
		q = q->next;
	}

	return count;
}

void AddPolyn(Polynomail *ppa,Polynomail *ppb)     //分支结构要写好
{
	Polynomail p,q,r,s;

	if(!*ppa || !*ppb)
		return;

	r = *ppa;
	p = (*ppa)->next;
	q = (*ppb)->next;
	free(*ppb);
	(*ppb) = NULL;

	//printf("1\n");
	while(p && q)
	{
		if(p->da.expn < q->da.expn)
		{
			r->next = p;
			p = p->next;
			r = r->next;
			//printf("1\n");
		}
		else if(p->da.expn == q->da.expn)
		{
			p->da.coef += q->da.coef;
			r->next = p;
			s = q->next;
			free(q);
			q = s;
			r = r->next;
			p = p->next;
			/*printf("2\n");
			printf("p = %d\n",p);
			printf("q = %d\n",q);
			printf("r = %d\n",r);
			printf("p && q = %d\n",q&&p);*/
		}
		else if(p->da.expn > q->da.expn)
		{
			r->next = q;
			q = q->next;
			r = r->next;
			//printf("3\n");
		}
	}

	//printf("4\n");

	if(p)
		r->next = p;
	if(q)
		r->next = q;

}

void SubPolyn(Polynomail *ppa,Polynomail *ppb)
{
	ConvertPolyn(*ppb);
	AddPolyn(ppa,ppb);
}
