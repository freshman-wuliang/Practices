#ifndef HUFFMANTREE_H
#define HUFFMANTREE_H

#include"BitTree.h"
#include"SeqList.h"

#define EMPTY 0

typedef int HFTreeNodeType;
typedef BitTree HFMTree;

typedef struct
{
	TreeNode value;
	int weight;
}HFMNode;

//void createDefineArray(HFMNode define[],);
//void mergeHFMNode();

//void createHFMTree(HFMTree ht,define[],int n);

#endif