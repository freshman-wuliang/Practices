#ifndef BITTREE_H
#define BITTREE_H

#include"Config.h"
#include"Stack.h"
#include"Queue.h"
#include<stdlib.h>
#include<stdio.h>

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

void levelOrderTrav(BitTree t);

//assist function
int max(int a,int b);

#endif