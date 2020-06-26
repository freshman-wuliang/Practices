#ifndef HASHTABLE_H
#define HASHTABLE_H

#include<stdio.h>
#include<stdlib.h>

#define DEF_LOAD_FACTOR 0.7
#define DEF_TAB_SIZE 20
#define TAB_SIZE_ADD 10

typedef int ElemType;

typedef struct
{
	ElemType elem;
	int flag;
}TableNode;

typedef struct
{
	TableNode *pelem;
	int elem_count;
	int table_size;
	float load_factor;
}HashTable,*PHashTable;

int Hash(ElemType elem,int table_size);   //除留余数法

int findPrime(int n);

int isPrime(int n);

void initHashTable(HashTable *pht);

void destroyHashTable(HashTable *pht);

void displayHashTable(HashTable ht);

void insertElem(HashTable *pht,ElemType elem);   //开放定址法+线性探测

void addTableSize(HashTable *pht);

int searchElem(HashTable ht,ElemType elem);

void deleteElem(HashTable *pht,ElemType elem);

#endif