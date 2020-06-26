#include<stdio.h>
#include"BitTree.h"

#define N 11

int main(void)
{
	BitTree t;
	int define[N] = {1,2,3,4,5,0,0,0,0,6,7};
	
	initBitTree(&t);
	createBitTree(&t,NULL,define,N,1);
	//printf("empty:%d\n",emptyBitTree(t));
	//printf("depth:%d\n",BitTreeDepth(t));
	//printf("root:0x%p\n",t);
	//printf("elem:0x%p\n",getElemPos(t,8));
	//printf("root:%d\n",getRootValue(t));
	//assignElemPos(t,8);
	//printf("root:%d\n",getRootValue(t));
	/*preOrderTrav(t);
	putchar('\n');
	inOrderTrav(t);
	putchar('\n');
	postOrderTrav(t);
	putchar('\n');*/
	levelOrderTrav(t);
	destroyBitTree(&t);
	
	return 0;
}