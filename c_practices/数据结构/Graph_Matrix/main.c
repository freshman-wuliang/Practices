#include<stdio.h>
#include"Graph.h"

#define VEXS_N 5
#define ARCS_N 3

int main(void)
{
	Graph g;
	VexsType vexs[VEXS_N] = {1,2,3,4,5};
	ArcsType arcs[ARCS_N] = {{1,4},{1,5},{2,3}};
	
	initGraph(&g);
	//displayGraph(g);
	createGraph(&g,vexs,VEXS_N,arcs,ARCS_N);
	printf("connect:%d\n",connectGraph(g));
	//displayGraph(g);
	//deleteVex(&g,5);
	//insertArc(&g,2,4);
	//deleteVex(&g,5);
	//printf("arcs_num:%d\n",g.arcs_num);
	//insertVex(&g,6);
	//displayGraph(g);
	//deleteArc(&g,2,4);
	//printf("adj:%d\n",nextAdjVex(g,2,3));
	/*int index;
	index = getVexIndex(g,4);
	assignVexValue(&g,index,5);*/
	/*printf("BFS:");
	BFSearch(&g,1);
	putchar('\n');*/
	//displayGraph(g
	/*printf("DFS:");
	DFSearch(&g,1);
	putchar('\n');*/
	//displayGraph(g);
	destroyGraph(&g);
	
	return 0;
}