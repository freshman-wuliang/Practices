#include<stdio.h>
#include"Network.h"

#define VEXS_N 6
#define ARCS_N 10

int main(void)
{
	Network n;
	VexsType vexs[VEXS_N] = {'a','b','c','d','e','f'};
	ArcsType arcs[ARCS_N] = {{'a','b',6},{'a','c',1},{'a','d',5},
	                         {'b','e',3},{'e','f',6},{'d','f',2},
							 {'b','c',5},{'d','c',5},{'e','c',6},{'c','f',4}};
	//
	initNetwork(&n);
	createNetwork(&n,vexs,VEXS_N,arcs,ARCS_N);
	displayNetwork(n);
	destroyNetwork(&n);
	
	return 0;
}