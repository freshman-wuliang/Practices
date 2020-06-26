#include"datastr.h"

/*[1].linear list*/

/****************list begin****************/

/*[1.1].sequential list*/

//seqlist begin

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

//SLinkList begin

//sngSLinkList

/*initSLinkList*/
void initSLinkList(SLinkList *ptlist)
{
	(*ptlist) = (PLinkNode)malloc(sizeof(LinkNode));
	if(!(*ptlist))
	{
		exit(1);
	}
	
	(*ptlist)->next = NULL;
}

/*destroySLinkList*/
void destroySLinkList(SLinkList *ptlist)
{
	PLinkNode p,q;
	
	if(!(*ptlist))
		return;
	
	p = *ptlist;
	q = p->next;
	while(q)
	{
		free(p);
		p = q;
		q = p->next;
	}
	free(p);
	*ptlist = NULL;
}

/*creatSLinkList*/
void creatSLinkList(SLinkList list,int list_len,SLListType elem[])
{
	PLinkNode p,q;
	
	if(!list)
		return;
	
	if(list->next)
		return;
	
	p = list;
	for(int i=1;i<=list_len;i++)
	{
		q = (PLinkNode)malloc(sizeof(LinkNode));
		if(!q)
		{
			exit(1);
		}
		
		q->elem = elem[i-1];
		q->next = NULL;
		
		p->next = q;
		p = q;
	}
}

/*printSLinkList*/
void printSLinkList(SLinkList list)
{
	PLinkNode p;
	
	if(list == NULL)
	{
		printf("Single LinkList is destroyed\n");
		return;
	}
	
	if(list->next == NULL)
	{
		printf("Single LinkList is empty\n");
		return;
	}
	
	p = list->next;
	printf("SLinkList:");
	while(p)
	{
		printf("%d ",p->elem);
		p = p->next;
	}
	printf("\n");
}

/*clearSLinkList*/
void clearSLinkList(SLinkList list)
{
	PLinkNode p,q;
	
	if(!list)
		return;
	
	p = list->next;
	while(p)
	{
		q = p->next;
		free(p);
		p = q;
	}
	
	list->next = NULL;
}

/*SLinkListLength*/
int SLinkListLength(SLinkList list)
{
	
}

//sngSLinkList

//SLinkList end

/****************list end*****************/