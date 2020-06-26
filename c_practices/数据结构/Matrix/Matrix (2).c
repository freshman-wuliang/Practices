#include"Matrix.h"

Status CreateSMatrix(pSMatrix pM,int row,int col,int num,int array[][3])
{
	int i;

	if(row <= 0 || col <= 0)
		return ERROR;
	if(num > MAXSIZE || num < 0)
		return ERROR;

	pM->row = row;
	pM->col = col;
	pM->num = num;

	for(i=0;i<num;i++)
	{
		pM->data[i].m = array[i][0];
		pM->data[i].n = array[i][1];
		pM->data[i].e = array[i][2];
	}
	pM->data[MAXSIZE].e = 0;

	return OK;
}

void PrintSMatrix(SMatrix M)
{
	int i,j,k,r;

	for(i = 1;i<=M.row;i++)
	{
		for(j=1;j<=M.col;j++)
		{
			for(k=0;k<M.num;k++)
			{
				if(i == M.data[k].m && j == M.data[k].n)
				{
					r = M.data[k].e;
					break;
				}
				else
					r = M.data[MAXSIZE].e;
			}

			printf(" %d",r);
		}
		putchar('\n');
	}
}

void CopySMatrix(SMatrix M,pSMatrix pT)
{
	for(int i=0;i<M.num;i++)
	{
		pT->data[i].m = M.data[i].m;
		pT->data[i].n = M.data[i].n;
		pT->data[i].e = M.data[i].e;
	}

	pT->data[MAXSIZE].e = M.data[MAXSIZE].e;
	pT->num = M.num;
	pT->row = M.row;
	pT->col = M.col;
}

Status AddSMatrix(SMatrix A,SMatrix B,pSMatrix pC)
{
	int i = 0;
	int j = 0;
	int count = 0;

	if(A.row != B.row || A.col != B.col)   //A和B的行数和列数不相等
		return ERROR;

	while(i<A.num && j<B.num)   //处理A和B中的每一个元素
	{
		if(A.data[i].m == B.data[j].m)   //i和j的行数相等
		{
			if(A.data[i].n == B.data[j].n)   //i和j的列数也相等
			{
				if(A.data[i].e + B.data[j].e)   //如果A和B的元的值相加不为0，则添加A与B的值的和
				{
					pC->data[count].m = A.data[i].m;
					pC->data[count].n = A.data[i].n;
					pC->data[count].e = A.data[i].e + B.data[j].e;
					count++;
				}
				j++;   //不管值为不为0，i和j都要后移
				i++;
			}
			else if(A.data[i].n < B.data[j].n)   //A的列数比B的小，将A加入
			{
				pC->data[count].m = A.data[i].m;
				pC->data[count].n = A.data[i].n;
				pC->data[count].e = A.data[i].e;
				count++;
				i++;
			}
			else   //A的列数比B的大，将B加入
			{
				pC->data[count].m = B.data[j].m;
				pC->data[count].n = B.data[j].n;
				pC->data[count].e = B.data[j].e;
				count++;
				j++;
			}
		}
		else if(A.data[i].m < B.data[j].m)   //A的行数比B的小，将A加入
		{
			pC->data[count].m = A.data[i].m;
			pC->data[count].n = A.data[i].n;
			pC->data[count].e = A.data[i].e;
			count++;
			i++;
		}
		else   //A的行数比B的大，将B加入
		{
			pC->data[count].m = B.data[j].m;
			pC->data[count].n = B.data[j].n;
			pC->data[count].e = B.data[j].e;
			count++;
			j++;
		}
	}

	while(i < A.num)   //A中还有元素
	{
		pC->data[count].m = A.data[i].m;
		pC->data[count].n = A.data[i].n;
		pC->data[count].e = A.data[i].e;
		count++;
		i++;
	}

	while(j < B.num)   //B中还有元素
	{
		pC->data[count].m = B.data[j].m;
		pC->data[count].n = B.data[j].n;
		pC->data[count].e = B.data[j].e;
		count++;
		j++;
	}

	pC->num = count;
	pC->row = A.row;
	pC->col = A.col;

	return OK;
}

Status SubSMatrix(SMatrix A,SMatrix B,pSMatrix pC)
{
	int i = 0;
	int j = 0;
	int count = 0;

	if(A.row != B.row || A.col != B.col)   //A和B的行数或列数不相等
		return ERROR;

	while(i < A.num && j < B.num)   //处理每个元素
	{
		if(A.data[i].m == B.data[j].m)   //A的行数等于B的行数
		{
			if(A.data[i].n == B.data[j].n)   //A的列数等于B的列数
			{
				if(A.data[i].e - B.data[j].e)   //如果A的值减B的值为0，则不添加
				{
					pC->data[count].m = A.data[i].m;
					pC->data[count].n = A.data[i].n;
					pC->data[count].e = A.data[i].e - B.data[j].e;
					count++;
				}
				j++;
				i++;
			}
			else if(A.data[i].n < B.data[j].n)   //A的列数比B的小
			{
				pC->data[count].m = A.data[count].m;
				pC->data[count].n = A.data[count].n;
				pC->data[count].e = A.data[count].e;
				count++;
				i++;
			}
			else   //A的列数比B的大
			{
				pC->data[count].m = B.data[j].m;
				pC->data[count].n = B.data[j].n;
				pC->data[count].e = -B.data[j].e;   //负的B的值
			}
		}
		else if(A.data[i].m < B.data[j].m)   //A的行数比B的小
		{
			pC->data[count].m = A.data[i].m;
			pC->data[count].n = A.data[i].n;
			pC->data[count].e = A.data[i].e;
			count++;
			i++;
		}
		else   //A的行数比B的大
		{
			pC->data[count].m = B.data[j].m;
			pC->data[count].n = B.data[j].n;
			pC->data[count].e = -B.data[j].e;   //B的值的负数
			count++;
			j++;
		}
	}

	while(i < A.num)   //A中还有元素
	{
		pC->data[count].m = A.data[i].m;
		pC->data[count].n = A.data[i].n;
		pC->data[count].e = A.data[i].e;
		count++;
		i++;
	}

	while(j < B.num)   //B中还有元素
	{
		pC->data[count].m = B.data[j].m;
		pC->data[count].n = B.data[j].n;
		pC->data[count].e = -B.data[j].e;   //B的元素的负值
		count++;
		j++;
	}

	pC->num = count;
	pC->row = A.row;
	pC->col = A.col;
	
	return OK;
}

Status TransSMatrix(SMatrix A,pSMatrix pT)
{
	int count = 0;
	pT->row = A.col;
	pT->col = A.row;
	pT->num = A.num;

	if(A.num)   //非0元不为0个
	{
		for(int i=1;i<=A.col;i++)   //以列开始扫描
		{
			for(int j=0;j<A.num;j++)   //扫描整个三元组
			{
				if(A.data[j].n == i)   //列数与i相等
				{
					pT->data[count].m = A.data[j].n;
					pT->data[count].n = A.data[j].m;
					pT->data[count].e = A.data[j].e;
					count++;
				}
			}
		}
	}

	return OK;
}

