#include<stdio.h>
#include"HashTable.h"

int main(void)
{
	HashTable ht;
	int array[12] = {60,17,29,38,45,16,48,74,62,25,49,77};
	
	initHashTable(&ht);
	
	for(int i=1;i<=12;i++)
	{
		insertElem(&ht,array[i-1]);
	}
	displayHashTable(ht);
	printf("index:%d\n",searchElem(ht,38));
	deleteElem(&ht,38);
	displayHashTable(ht);
	printf("index:%d\n",searchElem(ht,38));
	destroyHashTable(&ht);
	
	return 0;
}