#include"SqList.h"

Status InitSqList(pSqList pL)
{
	pL->elem = (int *)malloc(LIST_INIT_SIZE * sizeof(int));
	if(!pL->elem)
		exit(ERROR);
	pL->length = 0;
	pL->listsize = LIST_INIT_SIZE;
	return OK;
}

Status DestroySqList(pSqList pL)
{
	if(!pL->elem)
		exit(ERROR);
	free(pL->elem);
	pL->elem = NULL;
	printf("SqList has been destroy!\n");
	return OK;
}

Status ClearSqList(pSqList pL)
{
	if(!pL->elem)
		exit(ERROR);
	pL->length = 0;
	return OK;
}

Status SqListEmpty(SqList L)
{
	if(!L.elem)
		exit(ERROR);
	if(L.length == 0)
		return 1;
	else
		return 0;
}

Status SqListLength(SqList L)
{
	if(!L.elem)
		exit(ERROR);
	return L.length;
}

Status GetElem(SqList L,int i,int *e)
{
	if(!L.elem)
		exit(ERROR);
	if(i<1 || i>L.length)
		return FALSE;

	*e = L.elem[i-1];   //*e = L.elem + (i - 1)*sizeof(int);
	return OK;
}

Status LocateElem(SqList L,int e)
{
	int num = 0;

	if(!L.elem)
		exit(ERROR);
	for(int i=0;i<L.length;i++)
	{
		if(e == L.elem[i])
		{
			num = i + 1;
			break;
		}
	}

	return num;
}

Status PriorElem(SqList L,int e,int *pre_e)
{
	int num;

	if(!L.elem)
		exit(ERROR);
	num = LocateElem(L,e);
	if(num == 0 || num == 1)   //如果e不存在或e在第一个
		return FALSE;
	else
		*pre_e = L.elem[num - 2];   //num-1为实际物理地址，num-2为前驱的实际地址
	return OK;
}

Status NextElem(SqList L,int e,int *next_e)
{
	int num;

	if(!L.elem)
		exit(ERROR);
	num = LocateElem(L,e);
	if(num == 0 || num == L.length)
		return FALSE;
	else
		*next_e = L.elem[num];
	return OK;
}

Status InsertElem(pSqList pL,int i,int e)
{
	int *newbase;

	if(!pL->elem)
		exit(ERROR);
	if(i<1 || i>(pL->length + 1))
		return FALSE;
	if(pL->length >= pL->listsize)   //存储空间已满
	{
		newbase = (int *)realloc(pL->elem,(pL->listsize + LISTINCREMENT)*sizeof(int));
		if(!newbase)
			exit(OVERFLOW);
		pL->elem = newbase;
		pL->listsize += LISTINCREMENT;
	}

	for(int j=pL->length;j>=i;j--)   //数据后移
		pL->elem[j] = pL->elem[j-1];
	pL->elem[i-1] = e;
	pL->length++;
	return OK;
}

Status DeleteElem(pSqList pL,int i,int *e)
{
	if(!pL->elem)
		exit(ERROR);
	if(i<1 || i>pL->length)
		return  FALSE;

	*e = pL->elem[i-1];
	for(int j=i-1;j<=(pL->length-2);j++)   //-1是实际的物理地址，-2是倒数第二个的实际物理地址
		pL->elem[j] = pL->elem[j+1];
	pL->length--;
	return OK;
}

Status CreatSqList(pSqList pL,int length,int array[])
{
	if(!pL->elem)
		exit(ERROR);
	if(length<0)
		return FALSE;
	for(int i=0;i<length;i++)
	{
		if(!InsertElem(pL,i+1,array[i]))
			return FALSE;
	}
	return OK;
}

void PrintSqList(SqList L)
{
	if(!L.elem)
		exit(ERROR);
	if(!L.length)
	{
		printf("SqList is Empty!\nSqList's listsize is %d\n",L.listsize);
		return;
	}
	printf("SqList is : ");
	for(int i=0;i<L.length;i++)
		printf("%d ",L.elem[i]);
	putchar('\n');
	printf("SqList'listsize is %d\n",L.listsize);
}

void UnionSqList(pSqList pL1,SqList L2)
{
	if(!pL1->elem || !L2.elem)
		exit(ERROR);
	for(int i=1;i<=L2.length;i++)   //遍历L2
	{
		if(!LocateElem(*pL1,L2.elem[i-1]))
		{
			InsertElem(pL1,pL1->length+1,L2.elem[i-1]);
		}
	}
}

void MergeSqList(SqList L1,SqList L2,pSqList pL3)
{
	if(!L1.elem || !L2.elem || !pL3->elem)
		exit(ERROR);

	int i = 1;   //指示L1位置的指针
	int j = 1;   //指示L2位置的指针
	int k = 0;   //指示L3位置的指针

	while(i<=L1.length && j<=L2.length)
	{
		if(L1.elem[i-1] <= L2.elem[j-1])
		{
			InsertElem(pL3,++k,L1.elem[i-1]);
			i++;   //后推
		}
		else
		{
			InsertElem(pL3,++k,L2.elem[j-1]);
			j++;
		}
	}

	while(i<=L1.length)
	{
		InsertElem(pL3,++k,L1.elem[i-1]);
		i++;
	}

	while(j<=L2.length)
	{
		InsertElem(pL3,++k,L2.elem[j-1]);
		j++;
	}
}
