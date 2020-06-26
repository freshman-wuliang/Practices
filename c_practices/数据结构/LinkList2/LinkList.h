#ifndef LINKLIST_H
#define LINKLIST_H

typedef int SLListType;

typedef struct Node
{
	SLListType elem;
	struct Node *next;
}LinkNode,*PLinkNode;

typedef PLinkNode SLinkList;

void initSLinkList(SLinkList *ptlist);

void destroySLinkList(SLinkList *ptlist);

void creatSLinkList(SLinkList list,int list_len,SLListType elem[]);

void printSLinkList(SLinkList list);

void clearSLinkList(SLinkList list);

int SLinkListLength(SLinkList list);

#endif