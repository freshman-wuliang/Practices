#include"SeqList.h"

/*initSeqList*/
void initSeqList(SeqList *ptlist)
{
	ptlist->ptelem = NULL;
	ptlist->length = 0;
}

/*destroySeqList*/
void destroySeqList(SeqList *ptlist)
{
	if(ptlist->ptelem && ptlist->length > 0)
	{
		free(ptlist->ptelem);
		ptlist->length = -1;
		ptlist->ptelem = NULL;
	}
	else
	{
		ptlist->length = -1;
	}
}

/*clearSeqList*/
void clearSeqList(SeqList *ptlist)
{
	if(ptlist->ptelem && ptlist->length > 0)
	{
		free(ptlist->ptelem);
		ptlist->length = 0;
		ptlist->ptelem = NULL;
	}
	else
	{
		ptlist->length = 0;
	}
}

/*creatSeqList*/
void creatSeqList(SeqList *ptlist,SListType elem[],int list_len)
{
	ptlist->ptelem = (SListType*)malloc(list_len*sizeof(SListType));
	if(!ptlist->ptelem)
	{
		printf("memory full!\n");
		exit(1);
	}
	ptlist->length = list_len;
	
	for(int i=1;i<=list_len;i++)
	{
		ptlist->ptelem[i-1] = elem[i-1];
	}
}

/*printSeqList*/
void printSeqList(SeqList list)
{
	int i;
	
	//list empty
	if(list.length == 0)
	{
		printf("SeqList empty\n");
		return;
	}
	
	//list has been destroyed
	if(list.length == -1)
	{
		printf("SeqList has been destroyed\n");
		return;
	}
	
	if(list.length && list.ptelem)
	{
		printf("SeqList:");
		for(i=1;i<=list.length-1;i++)
		{
			printf("%d ",list.ptelem[i-1]);
		}
		printf("%d\n",list.ptelem[i-1]);
	}
}

/*seqListLength*/
int seqListLength(SeqList list)
{
	return list.length;
}

/*seqListEmpty*/
int seqListEmpty(SeqList list)
{
	if(list.length == 0)
		return true;
	else if(list.length == -1)
		return -1;
	else
		return false;
}

/*insertSeqList*/
void insertSeqList(SeqList *ptlist,int index,SListType elem)
{
	SListType *tmp;
	
	if(ptlist->length == -1)
		return;
	
	if(index <= 1 && index > ptlist->length + 1)
		return;
	
	tmp = (SListType*)realloc(ptlist->ptelem,ptlist->length+1);
	if(!tmp)
	{
		exit(1);
	}
	
	ptlist->ptelem = tmp;
	for(int i = ptlist->length;i >= index;i--)
	{
		ptlist->ptelem[i] = ptlist->ptelem[i-1];
	}
	ptlist->ptelem[index-1] = elem;
	ptlist->length++;
}

/*deleteSeqList*/
SListType deleteSeqList(SeqList *ptlist,int index)
{
	SListType del;
	
	if(ptlist->length == -1 || ptlist->length == 0)
		return del;
	
	if(index < 1 || index > ptlist->length)
		return del;
	
	del = ptlist->ptelem[index-1];
	for(int i = index;i <= ptlist->length - 1;i++)
	{
		ptlist->ptelem[i-1] = ptlist->ptelem[i];
	}
	
	ptlist->length--;
	
	return del;
}
//seqlist end