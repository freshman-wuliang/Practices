#ifndef BITTREE_H
#define BITTREE_H

#include<stdlib.h>
#include<stdio.h>

#define EMPTY 0
#define END -1

typedef int TreeElemType;

typedef struct TreeNode
{
	TreeElemType data;
	struct TreeNode *parent;
	struct TreeNode *lchild;
	struct TreeNode *rchild;
}TreeNode,*PTreeNode;

typedef PTreeNode BitTree;

void initBitTree(BitTree *pt);

void createBitTree(BitTree *pt,TreeNode *pparent,TreeElemType define[],int upline,int index);

int emptyBitTree(BitTree t);

int BitTreeDepth(BitTree t);

void destroyBitTree(BitTree *pt);

TreeElemType getRootValue(BitTree t);

TreeNode *getElemPos(BitTree t,TreeElemType elem);

TreeElemType getPosValue(BitTree t,TreeNode *pos);

void assignElemPos(TreeNode *pos,TreeElemType elem);

void preOrderTrav(BitTree t);

void inOrderTrav(BitTree t);

void postOrderTrav(BitTree t);

//assist function
int max(int a,int b);

#endif