#include<stdio.h>
#include"BitTree.h"

#define TREE_N 10
#define C_N 2

int main(void)
{
	BitTree tree;
	BitTree c;
	ElemType define[TREE_N] = {1,2,3,0,4,0,5,0,0,6};
	ElemType define_c[C_N] = {5,6};
	
	initBitTree(&tree);
	//initBitTree(&c);
	//displayBitTree(tree);
	//createBitTree(&tree,define,TREE_N);
	//displayAll(tree);
	createBitTree(&tree,define,TREE_N);
	//displayBitTree(tree);
	//InsertNode(&tree,EMPTY,LEFT,c);
	//putchar('\n');
	displayBitTree(tree);
	//displayAll(tree);
	printf("preordtrav:");
	PreOrdTrav(tree,BitTreeRoot(tree));
	putchar('\n');
	printf("inordtrav:");
	InOrdTrav(tree,BitTreeRoot(tree));
	putchar('\n');
	printf("postordtrav:");
	PostOrdTrav(tree,BitTreeRoot(tree));
	putchar('\n');
	//printf("parent:%d\n",parentNode(tree,2));
	//printf("leftchild:%d\n",leftChild(tree,2));
	//printf("rightChild:%d\n",rightChild(tree,2));
	//printf("leftbrother:%d\n",leftBrother(tree,2));
	//printf("rightbrother:%d\n",rightBrother(tree,2));
	//assignValue(tree,5,5);
	//printf("empty:%d\n",BitTreeEmpty(tree));
	//clearBitTree(&tree);
	//printf("empty:%d\n",BitTreeEmpty(tree));
	//displayBitTree(tree);
	//printf("depth:%d\n",BitTreeDepth(tree));
	destroyBitTree(&tree);
	//destroyBitTree(&c);
	//printf("empty:%d\n",BitTreeEmpty(tree));
	//displayBitTree(tree);
	
	return 0;
}