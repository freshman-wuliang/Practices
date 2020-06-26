#ifndef BITTREE_H
#define BITTREE_H

#include<stdlib.h>
#include<stdio.h>
#include<math.h>

typedef int ElemType;
#define EMPTY 0
#define END -1
#define LEFT 0
#define RIGHT 1

typedef struct
{
	ElemType value;
	int index;
}Node,*PNode;

typedef struct
{
	PNode array;
	int node_num;
}BitTree;

void initBitTree(BitTree *ptree);

void destroyBitTree(BitTree *ptree);

void createBitTree(BitTree *ptree,ElemType define[],int num);

int BitTreeDepth(BitTree tree);

void displayBitTree(BitTree tree);

void clearBitTree(BitTree *ptree);

int BitTreeEmpty(BitTree tree);

ElemType BitTreeRoot(BitTree tree);

ElemType nodeValue(BitTree tree,int pos);

void assignValue(BitTree tree,int pos,ElemType value);

ElemType parentNode(BitTree tree,ElemType elem);

ElemType leftChild(BitTree tree,ElemType elem);

ElemType rightChild(BitTree tree,ElemType elem);

ElemType leftBrother(BitTree tree,ElemType elem);

ElemType rightBrother(BitTree tree,ElemType elem);

void InsertNode(BitTree *ptree,ElemType elem,int flag,BitTree t);

void DeleteNode(BitTree *ptree,ElemType elem,int flag);

void PreOrdTrav(BitTree tree,ElemType root);

void InOrdTrav(BitTree tree,ElemType root);

void PostOrdTrav(BitTree tree,ElemType root);

//assist function
int elemIsExit(BitTree tree,ElemType elem);

PNode getValuePos(BitTree tree,ElemType elem);

int exp_2(int n);

void displayAll(BitTree tree);

#endif