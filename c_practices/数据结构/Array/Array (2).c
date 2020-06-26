#include"Array.h"

Status InitArray(pArray pA,int dim,...)
{
	int elemtotal;
	va_list ap;        //参数指针

	if(dim < 1 || dim > MAX_ARRAY_DIM)
		return ERROR;

	pA->dim = dim;
	pA->bounds = (int*)malloc(dim*sizeof(int));
	if(!pA->bounds)
		exit(OVERFLOW);
	
	elemtotal = 1;
	va_start(ap,dim);   //设定开始的地址
	for(int i=0;i<dim;i++)
	{
		pA->bounds[i] = va_arg(ap,int);
		if(pA->bounds[i] < 0)
			return ERROR;
		elemtotal = elemtotal * pA->bounds[i];
	}
	va_end(ap);         //参数指针结束

	pA->base = (int*)malloc(elemtotal * sizeof(int));
	if(!pA->base)
		exit(OVERFLOW);
	pA->constants = (int*)malloc(dim * sizeof(int));
	pA->constants[dim-1] = 1;

	for(int i=dim-2;i>=0;i--)
	{
		pA->constants[i] = pA->bounds[i+1]*pA->constants[i+1];
	}

	return OK;
}

Status DestroyArray(pArray pA)
{
	if(!pA->base)
	{
		free(pA->base);
		pA->base = NULL;
	}
	if(!pA->bounds)
	{
		free(pA->bounds);
		pA->bounds = NULL;
	}
	if(!pA->constants)
	{
		free(pA->constants);
		pA->bounds = NULL;
	}

	return OK;
}

static Status Locate(Array A,va_list ap,int *off)
{
	int ind;

	for(int i=0;i<A.dim;i++)
	{
		ind = va_arg(ap,int);
		if(ind<0 || ind>=A.bounds[i])
			return FALSE;
		*off += A.constants[i] * ind;
	}

	return OK;
}

Status Value(Array A,int *e,...)
{
	va_list ap;
	int off = 0;

	va_start(ap,e);

	if(Locate(A,ap,&off) != OK)
		return FALSE;
	*e = *(A.base + off);

	return OK;
}

Status Assign(Array A,int e,...)
{
	int off = 0;
	va_list ap;

	va_start(ap,e);
	if(Locate(A,ap,&off) != OK)
		return FALSE;
	*(A.base + off) = e;

	return OK;
}

void PrintArray(Array A)
{
	int sum = 1;

	if(!A.base)
	{
		printf("NULL\n");
		return;
	}

	for(int i=0;i<A.dim;i++)
	{
		sum *= A.bounds[i];
	}

	for(int i=0;i<sum;i++)
	{
		printf(" %d",*(A.base+i));
	}
	putchar('\n');
}
