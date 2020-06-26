#include"CLMatrix.h"

Status CreateCLMatrix(pCLMatrix pM,int row,int col,int num,int array[][3])
{
	//判断参数合法性
	if(row <= 0 || col <=0 || num < 0)
		return ERROR;
	//基本参数初始化
	pM->row = row;
	pM->col = col;
	pM->num = num;
	//分配存储指针的内存
	pM->rhead = (pM_Node *)malloc(row * sizeof(pM_Node));   //pM->rhead是指向pM_Node(指针)的指针，即pM_Node*类型
	pM->chead = (pM_Node *)malloc(col * sizeof(pM_Node));
	if(!pM->rhead || !pM->chead)
		exit(ERROR);
	//初始化为空指针
	for(int i=0;i<row;i++)
	{
		pM->rhead[i] = NULL;
	}
	for(int i=0;i<col;i++)
	{
		pM->chead[i] = NULL;
	}
	//插入非零元
	printf("num=%d\n",num);
	for(int i=0;i<num;i++)   //扫描数组
	{
		pM_Node p;
		int r,c;
		r = array[i][0];
		c = array[i][1];

		if(r > row || c > col)
			return ERROR;
	
		//分配节点的存储空间
		p = (pM_Node)malloc(sizeof(M_Node));
		if(!p)
			exit(ERROR);
		p->r = r;
		p->c = c;
		p->v = array[i][2];
		printf("i=%d\n",i);
		printf("%d,%d,%d\n",p->r,p->c,p->v);

		if(NULL == pM->rhead[r-1] || pM->rhead[r-1]->c > c)   //第一个元素的列号大于插入元素的列号大，或头指针为空时
		{
			p->right = pM->rhead[r-1];
			pM->rhead[r-1] = p;   //易出错写为pM->rhead[r-1]->right = p;
		}                               //在前面插入元素
		else
		{
			pM_Node q;
			q = pM->rhead[r-1];
			while(q->right && q->c <= c-1)   //推指针找到合适的插入位置
			{
				q = q->right;
			}
			p->right = q->right;
			q->right = p;
		}

		if(NULL == pM->chead[c-1] || pM->chead[c-1]->r > r)   //第一个元素的行号大于插入的元素，或列头指针为空时
		{
			p->down = pM->chead[c-1];   //易写为pM->chead[c-1]->down;
			pM->chead[c-1] = p;         //易写为pM->chead[c-1]->down = p;
		}
		else
		{
			pM_Node q;
			q = pM->chead[c-1];
			while(q->right && q->r <= r-1)   //易写成||运算
			{
				q = q->down;
			}
			p->down = q->down;
			q->down = p;
		}
	}
	
	return OK;
}

void PrintCLMatrix(CLMatrix M)
{
	pM_Node p;
	
	for(int i=0;i<M.row;i++)   //扫描行
	{
		p = M.rhead[i];
		int count = 1;
		while(p)
		{
			if(p->c == count)
			{
				printf(" %d",p->v);
				p = p->right;
				count++;
			}
			else
			{
				printf(" %d",0);
				count++;
			}
		}
		while(count <=M.col)
		{
			printf(" %d",0);
			count++;
		}
		putchar('\n');
	}
}

