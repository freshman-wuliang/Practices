#ifndef NETWORK_H
#define NETWORK_H

#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

#define MAX_VERTEX_NUM 20
#define MAX_ARC_NUM 400
#define INFINITY INT_MAX
#define NO_VALUE '%'

typedef char VexsType;    //顶点类型

typedef struct
{
	VexsType vex1;
	VexsType vex2;
	int weight;
}ArcsType;

typedef struct
{
	VexsType vexs[MAX_VERTEX_NUM];
	int visit_flag[MAX_VERTEX_NUM];
	int vexs_num;
	int matrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
	int arcs_num;
}Network,*PNetwork;

void initNetwork(Network *pn);

void destroyNetwork(Network *pn);

void createNetwork(Network *pn,VexsType vexs[],int vexs_num,ArcsType arcs[],int arcs_num);

void displayNetwork(Network n);

int getVexIndex(Network n,VexsType elem);

void channeVexValue(Network *pn,VexsType vex,VexsType elem);

VexsType findAdjVex(Network n,VexsType vex);

VexsType nextAdjVex(Network n,VexsType vex1,VexsType vex2);

void insertVex(Network *pn,VexsType vex);

void deleteVex(Network *pn,VexsType vex);

void insertArc(Network *pn,VexsType vex1,VexsType vex2,int weinht);

void deleteArc(Network *pn,VexsType vex1,VexsType vex2);

int connectNetwork(Network n);

void DFS(Network *pn,VexsType vex);

void MST_Prim(Network n,Network *pmin);

void MST_Kruskal(Network n,Network *pmin);

void generateArcs(Network n,ArcsType arcs[],int *parc_num);

int arcIsExist(VexsType vex1,VexsType vex2,ArcsType arcs[],int arcs_num);

void joinArc(VexsType vex1,VexsType vex2,int weight,ArcsType arcs[],int *parcs_num);

void sortArcs(ArcsType arcs[],int arcs_num);

int haveLoop(Network n);

void updateDegree(Network n,VexsType vex,int degree[],int *pn);

int vexDegree(Network n,VexsType vex);

void findMinWeight(Network n,VexsType vex1[],int *pvex1_n,VexsType vex2[],int *pvex2_n,VexsType *pvex1,VexsType *pvex2);

VexsType findMinAdj(Network n,VexsType vex,VexsType vex2[],int vex2_n);

int getVexWeight(Network n,VexsType vex1,VexsType vex2);

int getArrayIndex(VexsType vexs[],int n,VexsType vex);

void Dijkstra(Network n,VexsType source,VexsType path[][MAX_VERTEX_NUM],int *ppath_num,int path_len[],int dist[],int *pdist_num);

int findMinDist(int dist[],int dist_num,int vex_flag[],int vex_num);

void updateVexFlag(int vex_flag[],int vex_flag_num,int index);

void updateVexs(Network n,VexsType vexs[],int *pvexs_num,int index);

void updateDistAndPath(Network n,int dist[],int dist_num,VexsType path[][MAX_VERTEX_NUM],int *ppath_num,int path_len[],int vex_flag[],int vex_flag_num,int index);

#endif