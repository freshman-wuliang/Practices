#include"Network.h"

void initNetwork(Network *pn)
{
	pn->vexs_num = 0;
	
	for(int i=1;i<=MAX_VERTEX_NUM;i++)
	{
		pn->visit_flag[i-1] = 0;
	}
	
	for(int i=1;i<= MAX_VERTEX_NUM;i++)
	{
		for(int j=1;j<= MAX_VERTEX_NUM;j++)
		{
			pn->matrix[i-1][j-1] = INFINITY;
		}
	}
	
	pn->arcs_num = 0;
}

void destroyNetwork(Network *pn)
{
	pn->vexs_num = -1;
	pn->arcs_num = -1;
}

void createNetwork(Network *pn,VexsType vexs[],int vexs_num,ArcsType arcs[],int arcs_num)
{
	if(vexs_num > MAX_VERTEX_NUM)
	{
		printf("vexs is too much\n");
		return;
	}
	
	pn->vexs_num = vexs_num;
	pn->arcs_num = arcs_num;
	
	for(int i=1;i<=vexs_num;i++)
	{
		pn->vexs[i-1] = vexs[i-1];
	}
	
	for(int i=1;i<=arcs_num;i++)
	{
		int index_r,index_c;
		index_r = getVexIndex(*pn,arcs[i-1].vex1);
		index_c = getVexIndex(*pn,arcs[i-1].vex2);
		pn->matrix[index_r-1][index_c-1] = arcs[i-1].weight;
		pn->matrix[index_c-1][index_r-1] = arcs[i-1].weight;
	}
	
}

void displayNetwork(Network n)
{
	if(n.vexs_num == -1 && n.arcs_num == -1)
	{
		printf("destroyed Network\n");
		return;
	}
	
	if(n.vexs_num == 0 && n.arcs_num == 0)
	{
		printf("empty Network\n");
		return;
	}
	
	printf("%4c",' ');
	for(int i=1;i<=n.vexs_num;i++)
	{
		printf("%2c ",n.vexs[i-1]);
	}
	putchar('\n');
	for(int i=1;i<=n.vexs_num;i++)
	{
		
		printf("%2c:",n.vexs[i-1]);
		putchar('|');
		for(int j=1;j<=n.vexs_num-1;j++)
		{
			if(n.matrix[i-1][j-1] == INFINITY)
			{
				printf("%2c ",'*');
			}
			else
			{
				printf("%2d ",n.matrix[i-1][j-1]);
			}
		}
		if(n.matrix[i-1][n.vexs_num-1] == INFINITY)
		{
			printf("%2c|",'*');
		}
		else
		{
			printf("%2d|",n.matrix[i-1][n.vexs_num-1]);
		}
		putchar('\n');
	}
}

int getVexIndex(Network g,VexsType elem)
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

void changeVexValue(Network *pn,VexsType vex,VexsType elem)
{
	int index = getVexIndex(*pn,vex);
	
	if(!index)
		return;
	
	pn->vexs[index-1] = elem;
}

VexsType findAdjVex(Network n,VexsType vex)
{
	int index;
	
	index = getVexIndex(n,vex);
	if(!index)
		return NO_VALUE;
	
	for(int i=1;i<=n.vexs_num;i++)
	{
		if(n.matrix[index-1][i-1] != INFINITY)
		{
			return n.vexs[i-1];
		}
	}
	
	return NO_VALUE;
}

VexsType nextAdjVex(Network n,VexsType vex1,VexsType vex2)
{
	if(!getVexIndex(n,vex1) || !getVexIndex(n,vex2))
		return 0;
	
	int index1,index2;
	index1 = getVexIndex(n,vex1);
	index2 = getVexIndex(n,vex2);
	
	int left_count = 0;
	int right_count = 0;
	int i,j;
	
	for(i=index2 - 1;i>=1;i--)
	{
		left_count++;
		if(n.matrix[index1-1][i-1] != INFINITY)
			break;
	}
	
	for(j=index2 + 1;j<=n.vexs_num;j++)
	{
		right_count++;
		if(n.matrix[index1-1][j-1] != INFINITY)
			break;
	}
	
	if(i >= 1 && left_count <= right_count)
	{
		return n.vexs[i-1];
	}
	else if(j <= n.vexs_num && right_count <= left_count)
	{
		return n.vexs[j-1];
	}
	else
	{
		return NO_VALUE;
	}
}

void insertVex(Network *pn,VexsType vex)
{
	if(pn->vexs_num + 1 > MAX_VERTEX_NUM)
	{
		printf("vexs is too much\n");
		exit(1);
	}
	
	pn->vexs[pn->vexs_num++] = vex;
}

void deleteVex(Network *pn,VexsType vex)
{
	if(!getVexIndex(*pn,vex))
		return;
	
	int index = getVexIndex(*pn,vex);
	int arcs_count = 0;
	
	for(int i=1;i<=pn->vexs_num;i++)
	{
		if(pn->matrix[index-1][i-1] != INFINITY)
			arcs_count++;
	}
	
	for(int i=index;i<=pn->vexs_num-1;i++)
	{
		for(int j=1;j<=pn->vexs_num;j++)
		{
			pn->matrix[i-1][j-1] = pn->matrix[i][j-1];
		}
	}
	
	for(int i=1;i<=pn->vexs_num;i++)
	{
		pn->matrix[pn->vexs_num-1][i-1] = INFINITY;
	}
	
	for(int i=index;i<=pn->vexs_num-1;i++)
	{
		for(int j=1;j<=pn->vexs_num;j++)
		{
			pn->matrix[j-1][i-1] = pn->matrix[j-1][i];
		}
	}
	
	for(int i=1;i<=pn->vexs_num;i++)
	{
		pn->matrix[i-1][pn->vexs_num-1] = INFINITY;
	}
	
	for(int i=index;i<=pn->vexs_num - 1;i++)
	{
		pn->vexs[i-1] = pn->vexs[i];
	}
	pn->vexs_num--;
	pn->arcs_num -= arcs_count;
	
}

void insertArc(Network *pn,VexsType vex1,VexsType vex2,int weight)
{
	if(!getVexIndex(*pn,vex1) || !getVexIndex(*pn,vex2))
		return;
	
	int index1,index2;
	index1 = getVexIndex(*pn,vex1);
	index2 = getVexIndex(*pn,vex2);
	
	pn->matrix[index1-1][index2-1] = weight;
	pn->matrix[index2-1][index1-1] = weight;
	pn->arcs_num++;
}

void deleteArc(Network *pn,VexsType vex1,VexsType vex2)
{
	int index1,index2;
	index1 = getVexIndex(*pn,vex1);
	index2 = getVexIndex(*pn,vex2);
	
	if(!index1 || !index2)
		return;
	
	pn->matrix[index1-1][index2-1] = INFINITY;
	pn->matrix[index2-1][index1-1] = INFINITY;
	pn->arcs_num--;
}

int connectNetwork(Network n)
{
	if(n.vexs_num <= 0)
		return 0;
	
	VexsType tmp_vex;
	tmp_vex = n.vexs[0];
	
	DFS(&n,tmp_vex);

	int flag = 1;
	for(int i=1;i<=n.vexs_num;i++)
	{
		if(n.visit_flag[i-1] == 0)
		{
			flag = 0;
			break;
		}
	}
	
	return flag;
}

void DFS(Network *pn,VexsType vex)
{
	if(!getVexIndex(*pn,vex))
		return;
	
	int index;
	index = getVexIndex(*pn,vex);
	
	if(pn->visit_flag[index-1] == 1)
		return;
	
	pn->visit_flag[index-1] = 1;
	
	for(int i=1;i<=pn->vexs_num;i++)
	{
		if(pn->matrix[index-1][i-1] != INFINITY && pn->visit_flag[i-1] == 0)
		{
			DFS(pn,pn->vexs[i-1]);
		}
	}
}

void MST_Prim(Network n,Network *pmin)
{
	if(n.vexs_num <= 0)
		return;
	
	if(!connectNetwork(n))
		return;
	
	VexsType vex1[MAX_VERTEX_NUM];   //顶点数组1
	VexsType vex2[MAX_VERTEX_NUM];   //顶点数组2
	VexsType vex1_tmp;
	VexsType vex2_tmp;
	int vex1_num = 0;
	int vex2_num = 0;
	ArcsType atmp[MAX_ARC_NUM];   //边数组
	int arc_num = 0;   //边数
	
	vex1[0] = n.vexs[0];
	vex1_num++;
	for(int i=2;i<=n.vexs_num;i++)
	{
		vex2[vex2_num++] = n.vexs[i-1];
	}
	
	for(int i=1;i<=n.vexs_num-1;i++)
	{
		findMinWeight(n,vex1,&vex1_num,vex2,&vex2_num,&vex1_tmp,&vex2_tmp);
		atmp[arc_num].vex1 = vex1_tmp;
		atmp[arc_num].vex2 = vex2_tmp;
		atmp[arc_num].weight = getVexWeight(n,vex1_tmp,vex2_tmp);
		arc_num++;
	}
	
	createNetwork(pmin,n.vexs,n.vexs_num,atmp,arc_num);
}

void findMinWeight(Network n,VexsType vex1[],int *pvex1_n,VexsType vex2[],int *pvex2_n,VexsType *pvex1,VexsType *pvex2)
{
	
	int min_weight;
	int min_index;
	VexsType min_vex;
	int vex1_index;
	
	if(*pvex1_n <=0 || *pvex1_n <= 0)
		return;
	
	min_vex = findMinAdj(n,vex1[0],vex2,*pvex2_n);
	min_index = getArrayIndex(vex2,*pvex2_n,min_vex);
	min_weight = getVexWeight(n,vex1[0],min_vex);
	vex1_index = 1;
	
	for(int i=2;i<=*pvex1_n;i++)
	{
		VexsType tmp;
		
		tmp = findMinAdj(n,vex1[i-1],vex2,*pvex2_n);
		if(getVexWeight(n,vex1[i-1],tmp) < min_weight)
		{
			min_weight = getVexWeight(n,vex1[i-1],tmp);
			min_index = getArrayIndex(vex2,*pvex2_n,tmp);
			vex1_index = i;
		}
	}
	
	*pvex1 = vex1[vex1_index-1];
	*pvex2 = vex2[min_index-1];
	
	vex1[(*pvex1_n)] = vex2[min_index-1];
	(*pvex1_n)++;
	
	for(int i=min_index;i<=(*pvex2_n)-1;i++)
	{
		vex2[i-1] = vex2[i];
	}

	(*pvex2_n)--;
}

VexsType findMinAdj(Network n,VexsType vex,VexsType vex2[],int vex2_n)
{
	VexsType vex_tmp;
	int vex2_index;
	int vex_index;
	int min_weight;
	int min_index;
	
	vex_index = getVexIndex(n,vex);
	
	min_weight = getVexWeight(n,vex,vex2[0]);
	min_index = 1;
	
	for(int i=2;i<=vex2_n;i++)
	{
		if(n.matrix[vex_index-1][getVexIndex(n,vex2[i-1]) - 1] != INFINITY)
		{
			if(n.matrix[vex_index-1][getVexIndex(n,vex2[i-1]) - 1] < min_weight)
			{
				min_weight = n.matrix[vex_index-1][getVexIndex(n,vex2[i-1]) - 1];
				min_index = i;
			}
		}
	}
	
	return vex2[min_index-1];
}

int getVexWeight(Network n,VexsType vex1,VexsType vex2)
{
	int index1,index2;
	
	index1 = getVexIndex(n,vex1);
	index2 = getVexIndex(n,vex2);
	
	return n.matrix[index1-1][index2-1];
}

int getArrayIndex(VexsType vexs[],int n,VexsType vex)
{
	int index = 0;
	
	for(int i=1;i<=n;i++)
	{
		if(vexs[i-1] == vex)
		{
			index = i;
			break;
		}
	}
	
	return index;
}

void generateArcs(Network n,ArcsType arcs[],int *parc_num)
{
	for(int i=1;i<=n.vexs_num;i++)
	{
		for(int j=1;j<=n.vexs_num;j++)
		{
			if(n.matrix[i-1][j-1] != INFINITY)
			{
				if(!arcIsExist(n.vexs[i-1],n.vexs[j-1],arcs,*parc_num))
				{
					joinArc(n.vexs[i-1],n.vexs[j-1],n.matrix[i-1][j-1],arcs,parc_num);
				}
			}
		}
	}
}

int arcIsExist(VexsType vex1,VexsType vex2,ArcsType arcs[],int arcs_num)
{
	int flag = 0;
	
	for(int i=1;i<=arcs_num;i++)
	{
		if(arcs[i-1].vex1 == vex1 && arcs[i-1].vex2 == vex2)
		{
			flag = 1;
			break;
		}
		
		if(arcs[i-1].vex1 == vex2 && arcs[i-1].vex2 == vex1)
		{
			flag = 1;
			break;
		}
	}
	
	return flag;
}

void joinArc(VexsType vex1,VexsType vex2,int weight,ArcsType arcs[],int *parcs_num)
{
	arcs[(*parcs_num)].vex1 = vex1;
	arcs[(*parcs_num)].vex2 = vex2;
	arcs[(*parcs_num)].weight = weight;
	(*parcs_num)++;
}

void sortArcs(ArcsType arcs[],int arcs_num)
{
	ArcsType tmp;
	
	for(int i=1;i<=arcs_num-1;i++)
	{
		for(int j=1;j<=arcs_num - i;j++)
		{
			if(arcs[j-1].weight > arcs[j].weight)
			{
				tmp.vex1 = arcs[j-1].vex1;
				tmp.vex2 = arcs[j-1].vex2;
				tmp.weight = arcs[j-1].weight;
				
				arcs[j-1].vex1 = arcs[j].vex1;
				arcs[j-1].vex2 = arcs[j].vex2;
				arcs[j-1].weight = arcs[j].weight;
				
				arcs[j].vex1 = tmp.vex1;
				arcs[j].vex2 = tmp.vex2;
				arcs[j].weight = tmp.weight;
			}
		}
	}
}

int haveLoop(Network n)
{
	if(n.vexs_num <= 0)
		return 0;
	
	int degree_tmp[MAX_VERTEX_NUM];
	int vexs_num = 0;
	int num = n.vexs_num;
	
	for(int i=1;i<=n.vexs_num;i++)
	{
		degree_tmp[vexs_num++] = vexDegree(n,n.vexs[i-1]);
	}
	
	for(int m=1;m<=num;m++)
	{
		for(int i=1;i<=n.vexs_num;i++)
		{
			if(vexDegree(n,n.vexs[i-1]) <= 1)
			{
				updateDegree(n,n.vexs[i-1],degree_tmp,&vexs_num);
				deleteVex(&n,n.vexs[i-1]);
			}
		}
	}

	if(n.vexs_num <= 0)
		return 0;
	else
		return 1;
}

void updateDegree(Network n,VexsType vex,int degree[],int *pn)
{
	int up_index;
	int vex_index;
	
	vex_index = getVexIndex(n,vex);
	
	for(int i=1;i<=n.vexs_num;i++)
	{
		if(n.matrix[vex_index-1][i-1] != INFINITY)
		{
			up_index = i;
			degree[up_index-1]--;
		}
	}
	
	for(int i=vex_index;i<=(*pn)-1;i++)
	{
		degree[i-1] = degree[i];
	}
	(*pn)--;
}

int vexDegree(Network n,VexsType vex)
{
	if(!getVexIndex(n,vex))
		return -1;
	
	int degree = 0;
	int index = getVexIndex(n,vex);
	
	for(int i=1;i<=n.vexs_num;i++)
	{
		if(n.matrix[index-1][i-1] != INFINITY)
		{
			degree++;
		}
	}
	
	return degree;
}

void MST_Kruskal(Network n,Network *pmin)
{
	ArcsType arcs[MAX_ARC_NUM];
	int arc_num = 0;
	
	Network net_tmp;
	ArcsType arc_tmp[MAX_ARC_NUM];
	int arc_tmp_num = 0;
	
	initNetwork(&net_tmp);
	for(int i=1;i<=n.vexs_num;i++)
	{
		insertVex(&net_tmp,n.vexs[i-1]);
	}
	
	generateArcs(n,arc_tmp,&arc_tmp_num);
	sortArcs(arc_tmp,arc_tmp_num);
	for(int i=1;i<=arc_tmp_num;i++)
	{
		insertArc(&net_tmp,arc_tmp[i-1].vex1,arc_tmp[i-1].vex2,arc_tmp[i-1].weight);
		if(haveLoop(net_tmp))
		{
			deleteArc(&net_tmp,arc_tmp[i-1].vex1,arc_tmp[i-1].vex2);
		}
		else
		{
			arcs[arc_num].vex1 = arc_tmp[i-1].vex1;
			arcs[arc_num].vex2 = arc_tmp[i-1].vex2;
			arcs[arc_num].weight = arc_tmp[i-1].weight;
			arc_num++;
		}
	}
	
	createNetwork(pmin,n.vexs,n.vexs_num,arcs,arc_num);
	
	destroyNetwork(&net_tmp);
}

void Dijkstra(Network n,VexsType source,VexsType path[][MAX_VERTEX_NUM],int *ppath_num,int path_len[],int dist[],int *pdist_num)
{
	if(!connectNetwork(n))
		return;
	
	int source_index = getVexIndex(n,source);   //源点下标
	if(!source_index)
		return;
	
	VexsType vexs[MAX_VERTEX_NUM];   //顶点集合
	int vexs_num = 0;   //顶点集合数
	int vex_flag[MAX_VERTEX_NUM];   //顶点访问标志
	int vex_flag_num = n.vexs_num;
	*ppath_num = n.vexs_num;
	for(int i=1;i<=n.vexs_num;i++)
	{
		path_len[i-1] = 0;
	}
	*pdist_num = 0;
	
	vexs[vexs_num++] = source;
	
	for(int i=1;i<=vex_flag_num;i++)
	{
		vex_flag[i-1] = 0;
	}
	vex_flag[source_index-1] = 1;
	
	for(int i=1;i<=n.vexs_num;i++)
	{
		dist[(*pdist_num)++] = n.matrix[source_index-1][i-1];
	}
	
	for(int i=1;i<=n.vexs_num;i++)
	{
		if(i != source_index)
		{
			path[i-1][path_len[i-1]] = source;
			path_len[i-1]++;
		}
		else
		{
			path[i-1][path_len[i-1]] = NO_VALUE;
		}
		
	}
	
	for(int i=1;i<=1;i++)
	{
		int vex_tmp_index = findMinDist(dist,*pdist_num,vex_flag,vex_flag_num);
		updateVexFlag(vex_flag,vex_flag_num,vex_tmp_index);
		updateVexs(n,vexs,&vexs_num,vex_tmp_index);
		updateDistAndPath(n,dist,*pdist_num,path,ppath_num,path_len,vex_flag,vex_flag_num,vex_tmp_index);
	}
	
	printf("dist:");
	for(int i=1;i<=*pdist_num;i++)
	{
		printf("%d ",dist[i-1]);
	}
	putchar('\n');
	printf("path:\n");
	for(int i=1;i<=*ppath_num;i++)
	{
		printf("[%c]: ",n.vexs[i-1]);
		for(int j=1;j<=path_len[i-1];j++)
		{
			printf("%c ",path[i-1][j-1]);
		}
		putchar('\n');
	}
}

int findMinDist(int dist[],int dist_num,int vex_flag[],int vex_num)
{
	int index = 0;
	int min_dist = dist[0];
	
	for(int i=1;i<=dist_num;i++)
	{
		if(dist[i-1] < min_dist && vex_flag[i-1] == 0)
		{
			index = i;
			min_dist = dist[i-1];
		}
	}
	
	return index;
}

void updateVexFlag(int vex_flag[],int vex_flag_num,int index)
{
	if(index < 0 || index > vex_flag_num)
		return;
	
	vex_flag[index-1] = 1;
}

void updateVexs(Network n,VexsType vexs[],int *pvexs_num,int index)
{
	if(index <= 0)
		return;
	
	vexs[(*pvexs_num)++] = n.vexs[index-1];
}

void updateDistAndPath(Network n,int dist[],int dist_num,VexsType path[][MAX_VERTEX_NUM],int *ppath_num,int path_len[],int vex_flag[],int vex_flag_num,int index)
{
	if(index <= 0 || index > dist_num)
		return;
	
	for(int i=1;i<=dist_num;i++)
	{
		if(vex_flag[i-1] == 0)
		{
			if(getVexWeight(n,n.vexs[index-1],n.vexs[i-1]) != INFINITY)
			{
				if(dist[i-1] > dist[index-1] + getVexWeight(n,n.vexs[index-1],n.vexs[i-1]))
				{
					dist[i-1] = dist[index-1] + getVexWeight(n,n.vexs[index-1],n.vexs[i-1]);
					path[i-1][path_len[i-1]] = n.vexs[index-1];
					path_len[i-1]++;
				}
			}
		}
	}
}