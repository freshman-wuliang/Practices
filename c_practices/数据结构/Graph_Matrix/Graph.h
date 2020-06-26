#ifndef GRAPH_H
#define GRAPH_H

#include<stdio.h>
#include<stdlib.h>
#include"Queue.h"
#include"Stack.h"

#define MAX_VERTEX_NUM 20

typedef enum
{
	disconnect,
	connect
}NodeStatus;   //连接状态

typedef int VexsType;    //顶点类型

typedef struct
{
	VexsType vex1;
	VexsType vex2;
}ArcsType;

typedef struct
{
	VexsType vexs[MAX_VERTEX_NUM];
	int visit_flag[MAX_VERTEX_NUM];
	int vexs_num;
	NodeStatus matrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
	int arcs_num;
}Graph,*PGraph;

void initGraph(Graph *pg);

void destroyGraph(Graph *pg);

void createGraph(Graph *pg,VexsType vexs[],int vexs_num,ArcsType arcs[],int arcs_num);

void displayGraph(Graph g);

int getVexIndex(Graph g,VexsType elem);

void assignVexValue(Graph *pg,int index,VexsType elem);

VexsType findAdjVex(Graph g,VexsType vex);

VexsType nextAdjVex(Graph g,VexsType vex1,VexsType vex2);

void insertVex(Graph *pg,VexsType vex);

void deleteVex(Graph *pg,VexsType vex);

void insertArc(Graph *pg,VexsType vex1,VexsType vex2);

void deleteArc(Graph *pg,VexsType vex1,VexsType vex2);

void BFS(Graph *pg,VexsType vex);

void BFSearch(Graph *pg,VexsType vex);

void DFSearch(Graph *pg,VexsType vex);

void DFS(Graph *pg,VexsType vex);

//int connectGraph(Graph g);

//assist function
int findVexIndex(Graph g,VexsType vex);

#endif