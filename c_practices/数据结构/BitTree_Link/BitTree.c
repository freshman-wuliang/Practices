#include"BitTree.h"

void initBitTree(BitTree *pt)
{
	*pt = NULL;
}

void destroyBitTree(BitTree *pt)
{
	if(*pt == NULL)
		return;
	
	destroyBitTree(&(*pt)->lchild);
	destroyBitTree(&(*pt)->rchild);
	//printf("destroy:%d\n",(*pt)->data);
	free(*pt);
	(*pt) = NULL;
}

void createBitTree(BitTree *pt,TreeNode *pparent,TreeElemType define[],int upline,int index)
{
	if(define[index-1] == EMPTY || index > upline)
		return;
	
	(*pt) = (TreeNode *)malloc(sizeof(TreeNode));
	if(!(*pt))
	{
		printf("memory full\n");
		exit(1);
	}
	
	(*pt)->data = define[index-1];
	(*pt)->parent = pparent;
	(*pt)->lchild = NULL;
	(*pt)->rchild = NULL;
	
	createBitTree(&((*pt)->lchild),*pt,define,upline,index * 2);
	createBitTree(&((*pt)->rchild),*pt,define,upline,index * 2 + 1);
}

int emptyBitTree(BitTree t)
{
	if(!t)
		return 1;
	else
		return 0;
}

int BitTreeDepth(BitTree t)
{
	int depth;
	
	if(!t)
		return 0;
	
	return max(BitTreeDepth(t->lchild),BitTreeDepth(t->rchild)) + 1;
}

TreeElemType getRootValue(BitTree t)
{
	if(!t)
		exit(1);
	
	return t->data;
}

TreeNode *getElemPos(BitTree t,TreeElemType elem)
{	
	if(!t)
		return NULL;
	
	TreeNode *p = NULL;
	if(t->data == elem)
	{
		p = t;
		return p;
	}
	else
	{
		TreeNode *pl = getElemPos(t->lchild,elem);
		TreeNode *pr = getElemPos(t->rchild,elem);
		if(pl)
			p = pl;
		if(pr)
			p = pr;
	}
	
	return p;
}

TreeElemType getPosValue(BitTree t,TreeNode *pos)
{
	if(!pos)
		exit(1);
	
	return pos->data;
}

void assignElemPos(TreeNode *pos,TreeElemType elem)
{
	if(!pos)
		return;
	
	pos->data = elem;
}

void preOrderTrav(BitTree t)
{
	if(!t)
		return;
	
	printf("%d ",t->data);
	preOrderTrav(t->lchild);
	preOrderTrav(t->rchild);
}

void inOrderTrav(BitTree t)
{
	if(!t)
		return;
	
	inOrderTrav(t->lchild);
	printf("%d ",t->data);
	inOrderTrav(t->rchild);
}

void postOrderTrav(BitTree t)
{
	if(!t)
		return;
	
	postOrderTrav(t->lchild);
	postOrderTrav(t->rchild);
	printf("%d ",t->data);
}

void levelOrderTrav(BitTree t)
{
	if(!t)
		return;
	
	Queue q;
	TreeNode *tmp;
	
	initQueue(&q);
	enQueue(&q,t);
	while(!emptyQueue(q))
	{
		tmp = deQueue(&q);
		
		if(tmp)
		{
			printf("%d ",tmp->data);
			enQueue(&q,tmp->lchild);
			enQueue(&q,tmp->rchild);
		}
	}
	destroyQueue(&q);
	
	putchar('\n');
}

//assist function
int max(int a,int b)
{
	return a > b? a : b;
}