#include"Graph.h"

void initGraph(Graph *pg)
{
	pg->vexs_num = 0;
	
	for(int i=1;i<=MAX_VERTEX_NUM;i++)
	{
		pg->visit_flag[i-1] = 0;
	}
	
	for(int i=1;i<= MAX_VERTEX_NUM;i++)
	{
		for(int j=1;j<= MAX_VERTEX_NUM;j++)
		{
			pg->matrix[i-1][j-1] = disconnect;
		}
	}
	
	pg->arcs_num = 0;
}

void destroyGraph(Graph *pg)
{
	pg->vexs_num = -1;
	pg->arcs_num = -1;
}

void createGraph(Graph *pg,VexsType vexs[],int vexs_num,ArcsType arcs[],int arcs_num)
{
	if(vexs_num > MAX_VERTEX_NUM)
	{
		printf("vexs is too much\n");
		return;
	}
	
	pg->vexs_num = vexs_num;
	pg->arcs_num = arcs_num;
	
	for(int i=1;i<=vexs_num;i++)
	{
		pg->vexs[i-1] = vexs[i-1];
	}
	
	for(int i=1;i<=arcs_num;i++)
	{
		int index_r,index_c;
		index_r = findVexIndex(*pg,arcs[i-1].vex1);
		index_c = findVexIndex(*pg,arcs[i-1].vex2);
		pg->matrix[index_r-1][index_c-1] = connect;
		pg->matrix[index_c-1][index_r-1] = connect;
	}
	
}

void displayGraph(Graph g)
{
	if(g.vexs_num == -1 && g.arcs_num == -1)
	{
		printf("destroyed graph\n");
		return;
	}
	
	if(g.vexs_num == 0 && g.arcs_num == 0)
	{
		printf("empty graph\n");
		return;
	}
	
	printf("   ");
	for(int i=1;i<=g.vexs_num;i++)
	{
		printf("%d ",g.vexs[i-1]);
	}
	putchar('\n');
	for(int i=1;i<=g.vexs_num;i++)
	{
		
		printf("%d:",g.vexs[i-1]);
		putchar('|');
		for(int j=1;j<=g.vexs_num-1;j++)
		{
			printf("%d ",g.matrix[i-1][j-1]);
		}
		printf("%d|",g.matrix[i-1][g.vexs_num-1]);
		putchar('\n');
	}
}

int getVexIndex(Graph g,VexsType elem)
{
	int index = 0;
	
	for(int i=1;i<=g.vexs_num;i++)
	{
		if(elem == g.vexs[i-1])
		{
			index = i;
			break;
		}
	}
	
	return index;
}

void assignVexValue(Graph *pg,int index,VexsType elem)
{
	if(index == 0)
		return;
	
	pg->vexs[index-1] = elem;
}

VexsType findAdjVex(Graph g,VexsType vex)
{
	int index;
	
	index = findVexIndex(g,vex);
	if(!index)
		return 0;
	
	for(int i=1;i<=g.vexs_num;i++)
	{
		if(g.matrix[index-1][i-1] == connect)
		{
			return g.vexs[i-1];
		}
	}
	
	return 0;
}

VexsType nextAdjVex(Graph g,VexsType vex1,VexsType vex2)
{
	if(!findVexIndex(g,vex1) || !findAdjVex(g,vex2))
		return 0;
	
	int index1,index2;
	index1 = findVexIndex(g,vex1);
	index2 = findVexIndex(g,vex2);
	
	int left_count = 0;
	int right_count = 0;
	int i,j;
	
	for(i=index2 - 1;i>=1;i--)
	{
		left_count++;
		if(g.matrix[index1-1][i-1] == connect)
			break;
	}
	
	for(j=index2 + 1;j<=g.vexs_num;j++)
	{
		right_count++;
		if(g.matrix[index1-1][j-1] == connect)
			break;
	}
	
	if(i >= 1 && left_count <= right_count)
	{
		return g.vexs[i-1];
	}
	else if(j <= g.vexs_num && right_count < left_count)
	{
		return g.vexs[j-1];
	}
	else
	{
		return 0;
	}
}

void insertVex(Graph *pg,VexsType vex)
{
	if(pg->vexs_num + 1 > MAX_VERTEX_NUM)
	{
		printf("vexs is too much\n");
		exit(1);
	}
	
	pg->vexs[pg->vexs_num++] = vex;
}

void deleteVex(Graph *pg,VexsType vex)
{
	if(!findVexIndex(*pg,vex))
		return;
	
	int index = findVexIndex(*pg,vex);
	int arcs_count = 0;
	
	for(int i=1;i<=pg->vexs_num;i++)
	{
		if(pg->matrix[index-1][i-1] == connect)
			arcs_count++;
	}
	
	for(int i=index;i<=pg->vexs_num-1;i++)
	{
		for(int j=1;j<=pg->vexs_num;j++)
		{
			pg->matrix[i-1][j-1] = pg->matrix[i][j-1];
		}
	}
	
	for(int i=1;i<=pg->vexs_num;i++)
	{
		pg->matrix[pg->vexs_num-1][i-1] = disconnect;
	}
	
	for(int i=index;i<=pg->vexs_num-1;i++)
	{
		for(int j=1;j<=pg->vexs_num;j++)
		{
			pg->matrix[j-1][i-1] = pg->matrix[j-1][i];
		}
	}
	
	for(int i=1;i<=pg->vexs_num;i++)
	{
		pg->matrix[i-1][pg->vexs_num-1] = disconnect;
	}
	
	for(int i=index;i<=pg->vexs_num - 1;i++)
	{
		pg->vexs[i-1] = pg->vexs[i];
	}
	pg->vexs_num--;
	pg->arcs_num -= arcs_count;
	
}

void insertArc(Graph *pg,VexsType vex1,VexsType vex2)
{
	if(!findVexIndex(*pg,vex1) || !findVexIndex(*pg,vex2))
		return;
	
	int index1,index2;
	index1 = findVexIndex(*pg,vex1);
	index2 = findVexIndex(*pg,vex2);
	
	pg->matrix[index1-1][index2-1] = connect;
	pg->matrix[index2-1][index1-1] = connect;
	pg->arcs_num++;
}

void deleteArc(Graph *pg,VexsType vex1,VexsType vex2)
{
	int index1,index2;
	index1 = findVexIndex(*pg,vex1);
	index2 = findVexIndex(*pg,vex2);
	
	if(!index1 || !index2)
		return;
	
	pg->matrix[index1-1][index2-1] = disconnect;
	pg->matrix[index2-1][index1-1] = disconnect;
	pg->arcs_num--;
}

void BFS(Graph *pg,VexsType vex)
{
	if(!findVexIndex(*pg,vex))
		return;
	//printf("BFS call\n");
	Queue q;
	
	initQueue(&q);
	
	enQueue(&q,vex);
	
	while(!emptyQueue(q))
	{
		//printf("BFS call\n");
		int tmp;
		int index;
		
		tmp = deQueue(&q);
		index = findVexIndex(*pg,tmp);
		pg->visit_flag[index-1] = 1;
		printf("%d ",pg->vexs[index-1]);
		
		for(int i=1;i<=pg->vexs_num;i++)
		{
			if(pg->matrix[index-1][i-1] == connect && pg->visit_flag[i-1] == 0)
			{
				enQueue(&q,pg->vexs[i-1]);
			}
		}
	}
	
	destroyQueue(&q);
}

void BFSearch(Graph *pg,VexsType vex)
{
	int index = findVexIndex(*pg,vex);
	
	if(!index)
		return;
	
	BFS(pg,vex);
	for(int i=1;i<=pg->vexs_num;i++)
	{
		if(pg->visit_flag[i-1] == 0)
			BFS(pg,pg->vexs[i-1]);
	}
	
	for(int i=1;i<=pg->vexs_num;i++)
	{
		pg->visit_flag[i-1] = 0;
	}
}

void DFSearch(Graph *pg,VexsType vex)
{
	int index = findVexIndex(*pg,vex);
	if(!index)
		return;
	
	DFS(pg,vex);
	for(int i=1;i<=pg->vexs_num;i++)
	{
		if(pg->visit_flag[i-1] == 0)
		{
			DFS(pg,pg->vexs[i-1]);
		}
	}
	
	for(int i=1;i<=pg->vexs_num;i++)
	{
		pg->visit_flag[i-1] = 0;
	}
}

void DFS(Graph *pg,VexsType vex)
{
	int index = findVexIndex(*pg,vex);
	if(!index)
		return;
	
	if(pg->visit_flag[index-1] == 1)
		return;
	
	printf("%d ",vex);
	pg->visit_flag[index-1] = 1;
	
	for(int i=index+1;i<=pg->vexs_num;i++)
	{
		if(pg->matrix[index-1][i-1] == 1 && pg->visit_flag[i-1] == 0)
		{
			DFS(pg,pg->vexs[i-1]);
		}
	}
	
	for(int i=1;i<=index-1;i++)
	{
		if(pg->matrix[index-1][i-1] == 1 && pg->visit_flag[i-1] == 0)
		{
			DFS(pg,pg->vexs[i-1]);
		}
	}
}

/*int connectGraph(Graph g)
{
	VexsType vex;
	int m;
	
	for(m=1;m<=g.vexs_num;m++)
	{
		if(g.vexs[m-1] != 0)
		{
			vex = g.vexs[m-1];
			break;
		}
	}
	if(m > g.vexs_num)
		return 0;
	
	Queue q;
	
	initQueue(&q);
	
	enQueue(&q,vex);
	
	while(!emptyQueue(q))
	{
		int tmp;
		int index;
		
		tmp = deQueue(&q);
		index = findVexIndex(g,tmp);
		g.visit_flag[index-1] = 1;
		
		for(int i=1;i<=g.vexs_num;i++)
		{
			if(g.matrix[index-1][i-1] == connect && g.visit_flag[i-1] == 0)
			{
				enQueue(&q,g.vexs[i-1]);
			}
		}
	}
	
	destroyQueue(&q);
	
	int flag = 1;
	for(int i=1;i<=g.vexs_num;i++)
	{
		if(g.visit_flag[i-1] == 0)
		{
			flag = 1;
			break;
		}
	}
	
	return flag;
}*/

//assist function
int findVexIndex(Graph g,VexsType vex)
{
	int index = 0;
	
	for(int i=1;i<=g.vexs_num;i++)
	{
		if(vex == g.vexs[i-1])
		{
			index = i;
			break;
		}
	}
	
	return index;
}