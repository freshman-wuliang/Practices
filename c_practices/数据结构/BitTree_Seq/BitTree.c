#include"BitTree.h"

void initBitTree(BitTree *ptree)
{
	ptree->array = NULL;
	ptree->node_num = 0;
}

void destroyBitTree(BitTree *ptree)
{
	if(!(ptree->array))
	{
		ptree->node_num = -1;
		return;
	}
	
	free(ptree->array);
	(ptree->array) = NULL;
	ptree->node_num = -1;
}

void createBitTree(BitTree *ptree,ElemType define[],int num)
{
	(ptree->array) = (PNode)malloc((num+1) * sizeof(Node));
	if(!(ptree->array))
	{
		printf("memory full\n");
		exit(1);
	}
	
	for(int i=1;i<=num;i++)
	{
		(ptree->array)[i-1].value = define[i-1];
		(ptree->array)[i-1].index = i;
	}
	(ptree->array)[num].value = END;
	ptree->node_num = num;
}

void displayBitTree(BitTree tree)
{
	int layer;
	PNode p = tree.array;
	
	layer = BitTreeDepth(tree);
	
	if(tree.node_num == -1 && tree.array == NULL)
	{
		printf("destroyed tree\n");
		return;
	}
	
	if(tree.node_num == 0 && tree.array == NULL)
	{
		printf("empty tree\n");
		return;
	}
	
	for(int i = 1;i<=layer && p->value != END;i++)
	{
		//打印前置空格
		for(int j = 1;j<=exp_2(layer - i) - 1;j++)
		{
			putchar(' ');
		}
		
		if(i == 1)
		{
			printf("%2d",p->value);
			p++;
		}
		else
		{
			for(int k=1;k<=exp_2(i - 1) - 1;k++)
			{
				if(p->value == END)
					break;
				
				//打印值
				if(p->value == EMPTY)
				{
					putchar(' ');
					p++;
				}
				else
				{
					printf("%2d",p->value);
					p++;
				}
				
				//打印中间空格
				for(int m = 1;m <= exp_2(layer - i + 1) - 1;m++)
				{
					putchar(' ');
				}
			}
			
			if(p->value == END)
			{
				putchar('\n');
				return;
			}
			
			//打印后面的值
			if(p->value == EMPTY)
			{
				putchar(' ');
				p++;
			}
			else
			{
				printf("%2d",p->value);
				p++;
				
			}
		}
		printf("\n");
	}
}

void clearBitTree(BitTree *ptree)
{
	if(ptree->array == NULL && ptree->node_num == -1)
	{
		return;
	}
	
	if(ptree->array == NULL && ptree->node_num == 0)
	{
		return;
	}
	
	free(ptree->array);
	ptree->array = NULL;
	ptree->node_num = 0;
}

int BitTreeDepth(BitTree tree)
{
	PNode p = tree.array;
	int layer;
	
	if(tree.array == NULL && tree.node_num == 0)
	{
		return 0;
	}
	
	if(tree.array == NULL && tree.node_num == -1)
	{
		return -1;
	}
	
	while(p->value != END)
	{
		p++;
	}
	p--;
	
	layer = (int)(log(p->index) / log(2.0)) + 1;
	
	return layer;
}

int BitTreeEmpty(BitTree tree)
{
	if(tree.node_num > 0)
		return 1;
	else
		return tree.node_num;
}

ElemType BitTreeRoot(BitTree tree)
{
	if(BitTreeEmpty(tree) != 0 && BitTreeEmpty(tree) != -1)
	{
		return tree.array[0].value;
	}
	else
	{
		return END;
	}
}

ElemType nodeValue(BitTree tree,int pos)
{
	PNode p = tree.array;
	int count = 1;
	
	if(pos < 0 || pos > tree.node_num)
		return END;
	
	if(BitTreeEmpty(tree) != 0 && BitTreeEmpty(tree) != -1)
	{
		return tree.array[pos-1].value;
	}
	else
	{
		return END;
	}
}

void assignValue(BitTree tree,int pos,ElemType value)
{
	if(pos < 0 || pos > tree.node_num)
		return;
	
	if(BitTreeEmpty(tree) != 0 && BitTreeEmpty(tree) != -1)
	{
		tree.array[pos-1].value = value;
	}
}

ElemType parentNode(BitTree tree,ElemType elem)
{
	int index;
	
	if(BitTreeEmpty(tree) != 0 && BitTreeEmpty(tree) != -1)
	{
		if(elemIsExit(tree,elem))
		{
			index = getValuePos(tree,elem)->index;
			if(index / 2  >= 1)
			{
				return tree.array[index / 2 - 1].value;
			}
			else
				return END;
		}
		else
		{
			return EMPTY;
		}
	}
	else
	{
		return END;
	}
}

int elemIsExit(BitTree tree,ElemType elem)
{
	int flag = 0;
	
	for(int i=1;i<=tree.node_num;i++)
	{
		if(tree.array[i-1].value == elem)
		{
			flag = 1;
			break;
		}
	}
	
	return flag;
}

ElemType leftChild(BitTree tree,ElemType elem)
{
	int index;
	
	if(BitTreeEmpty(tree) != 0 && BitTreeEmpty(tree) != -1)
	{
		if(elemIsExit(tree,elem))
		{
			index = getValuePos(tree,elem)->index;
			
			if(index * 2 <= tree.node_num)
			{
				return tree.array[index * 2 - 1].value;
			}
			else
			{
				return EMPTY;
			}
		}
		else
		{
			return EMPTY;
		}
	}
	else
	{
		return END;
	}
}

ElemType rightChild(BitTree tree,ElemType elem)
{
	int index;
	
	if(BitTreeEmpty(tree) != 0 && BitTreeEmpty(tree) != -1)
	{
		if(elemIsExit(tree,elem))
		{
			index = getValuePos(tree,elem)->index;
			
			if(index * 2  + 1 <= tree.node_num)
			{
				return tree.array[index * 2].value;
			}
			else
			{
				return EMPTY;
			}
		}
		else
		{
			return EMPTY;
		}
	}
	else
	{
		return END;
	}
}

ElemType leftBrother(BitTree tree,ElemType elem)
{
	int index;
	
	if(BitTreeEmpty(tree) != 0 && BitTreeEmpty(tree) != -1)
	{
		if(elemIsExit(tree,elem))
		{
			index = getValuePos(tree,elem)->index;
			
			if(index % 2 != 0)
			{
				return tree.array[index - 2].value;
			}
			else
			{
				return EMPTY;
			}
		}
		else
		{
			return EMPTY;
		}
	}
	else
	{
		return END;
	}
}

void InsertNode(BitTree *ptree,ElemType elem,int flag,BitTree t)
{
	if(BitTreeEmpty(*ptree) == EMPTY && elem == EMPTY)   //tree树为空且elem为空
	{
		ptree->array = (PNode)malloc((t.node_num + 1) * sizeof(Node));
		if(!(ptree->array))
		{
			printf("memory full\n");
			exit(1);
		}
		
		ptree->node_num = t.node_num;
		for(int i=1;i<=t.node_num;i++)
		{
			ptree->array[i-1].value = t.array[i-1].value;
			ptree->array[i-1].index = t.array[i-1].index;
		}
		ptree->array[t.node_num].value = END;
	}
	
	if(BitTreeEmpty(*ptree) != EMPTY && BitTreeEmpty(*ptree) != END)   //树不为空
	{
		if(elemIsExit(*ptree,elem))   //elem存在
		{
			if(rightChild(t,BitTreeRoot(t)) == END || rightChild(t,BitTreeRoot(t)) == EMPTY)  //右子树不存在
			{
				ptree->array = (PNode)realloc(ptree->array,(ptree->node_num + t.node_num + 1) * sizeof(Node));
				if(!ptree->array)
				{
					printf("memeory full\n");
					exit(1);
				}
				ptree->node_num = ptree->node_num + t.node_num;
				for(int i=1;i<=ptree->node_num;i++)
				{
					ptree->array[i-1].index = i;
				}
				
				if(flag == LEFT)
				{
					//if()
				}
				else
				{
					
				}
			}
		}
	}
}

ElemType rightBrother(BitTree tree,ElemType elem)
{
	int index;
	
	if(BitTreeEmpty(tree) != 0 && BitTreeEmpty(tree) != -1)
	{
		if(elemIsExit(tree,elem))
		{
			index = getValuePos(tree,elem)->index;
			
			if(index % 2 == 0)
			{
				return tree.array[index].value;
			}
			else
			{
				return EMPTY;
			}
		}
		else
		{
			return EMPTY;
		}
	}
	else
	{
		return END;
	}
}

PNode getValuePos(BitTree tree,ElemType elem)
{
	PNode p = NULL;
	
	for(int i=1;i<=tree.node_num;i++)
	{
		if(tree.array[i-1].value == elem)
		{
			p = tree.array + i - 1;
			break;
		}
	}
	
	return p;
}

void PreOrdTrav(BitTree tree,ElemType root)
{
	ElemType tmp = root;
	
	if(tmp != EMPTY)
	{
		printf("%d ",tmp);
		PreOrdTrav(tree,leftChild(tree,tmp));
		PreOrdTrav(tree,rightChild(tree,tmp));
	}
}

void InOrdTrav(BitTree tree,ElemType root)
{
	ElemType tmp = root;
	
	if(tmp != EMPTY)
	{
		InOrdTrav(tree,leftChild(tree,tmp));
		printf("%d ",tmp);
		InOrdTrav(tree,rightChild(tree,tmp));
	}
}

void PostOrdTrav(BitTree tree,ElemType root)
{
	ElemType tmp = root;
	
	if(tmp != EMPTY)
	{
		PostOrdTrav(tree,leftChild(tree,tmp));
		PostOrdTrav(tree,rightChild(tree,tmp));
		printf("%d ",tmp);
	}
}

int exp_2(int n)
{
	int sum = 1;
	
	for(int i=1;i<=n;i++)
	{
		sum *= 2;
	}
	
	return sum;
}

void displayAll(BitTree tree)
{
	if(tree.node_num == -1)
	{
		printf("destroyed\n");
	}
	else if(tree.node_num == 0)
	{
		printf("empty\n");
	}
	else
	{
		printf("value:");
		for(int i=1;i<=tree.node_num + 1;i++)
		{
			printf("%d ",tree.array[i-1].value);
		}
		putchar('\n');
		printf("index:");
		for(int i=1;i<=tree.node_num;i++)
		{
			printf("%d ",tree.array[i-1].index);
		}
		printf("%c\n",'?');
	}
	
	printf("tree.array:0x%p\n",tree.array);
	printf("tree.node_num:%d\n",tree.node_num);
}