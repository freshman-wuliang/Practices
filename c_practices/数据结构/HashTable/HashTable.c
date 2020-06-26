#include"HashTable.h"

int Hash(ElemType elem,int table_size)
{
	return elem % findPrime(table_size);
}

int findPrime(int n)
{
	for(int i=n;i>=2;i--)
	{
		if(isPrime(i))
		{
			return i;
		}
	}
}

int isPrime(int n)
{
	int flag = 1;
	
	for(int i=2;i<=n-1;i++)
	{
		if(n % i == 0)
		{
			flag = 0;
			break;
		}
	}
	
	return flag;
}

void initHashTable(HashTable *pht)
{
	pht->pelem = (TableNode*)malloc(DEF_TAB_SIZE * sizeof(TableNode));
	if(!pht->pelem)
	{
		printf("memory full\n");
		exit(1);
	}
	
	for(int i=1;i<=DEF_TAB_SIZE;i++)
	{
		pht->pelem[i-1].elem = 0;
		pht->pelem[i-1].flag = 0;
	}
	pht->elem_count = 0;
	pht->table_size = DEF_TAB_SIZE;
	pht->load_factor = (float)pht->elem_count / (float)pht->table_size;
}

void destroyHashTable(HashTable *pht)
{
	if(!pht->pelem)
		return;
	
	free(pht->pelem);
	pht->pelem = NULL;
	pht->elem_count = -1;
	pht->table_size = -1;
	pht->load_factor = -1.0;
}

void displayHashTable(HashTable ht)
{
	if(!ht.pelem && ht.elem_count == -1)
	{
		printf("table destroyed\n");
		return;
	}
	
	if(ht.elem_count == 0)
	{
		printf("table empty\n");
		return;
	}
	
	printf("%-6s","index:");
	for(int i=1;i<=ht.table_size;i++)
	{
		printf("%-2d ",i);
	}
	putchar('\n');
	
	printf("%-6s","elem:");
	for(int i=1;i<=ht.table_size;i++)
	{
		printf("%-2d ",ht.pelem[i-1].elem);
	}
	putchar('\n');
	
	printf("%-6s","flag:");
	for(int i=1;i<=ht.table_size;i++)
	{
		printf("%-2d ",ht.pelem[i-1].flag);
	}
	putchar('\n');
	
	printf("table_size:%d\telem_count:%d\tload_factor:%.2f\n",ht.table_size,ht.elem_count,ht.load_factor);
}

void insertElem(HashTable *pht,ElemType elem)   //开放定址法+线性探测
{
	if(pht->pelem == NULL)
		return;
	
	pht->load_factor = (float)(pht->elem_count + 1.0) / (float)pht->table_size;
	if(pht->load_factor > DEF_LOAD_FACTOR)
	{
		addTableSize(pht);
	}
	
	int index;
	index = Hash(elem,pht->table_size) + 1;
	while(pht->pelem[index-1].flag == 1 && pht->pelem[index-1].elem != 0)
		index++;
	pht->pelem[index-1].elem = elem;
	pht->pelem[index-1].flag = 1;
	pht->elem_count++;
	pht->load_factor = (float)pht->elem_count / (float)pht->table_size;
}

void addTableSize(HashTable *pht)   //增加表的容量
{
	TableNode *tmp;
	tmp = (TableNode*)malloc((pht->table_size + TAB_SIZE_ADD) * sizeof(TableNode));
	if(!tmp)
	{
		printf("memory full\n");
		exit(1);
	}
	
	int *pindex;
	int pindex_count = 0;
	pindex = (int *)malloc(pht->elem_count * sizeof(int));
	if(!pindex)
	{
		printf("memory full\n");
		exit(1);
	}
	
	for(int i=1;i<=pht->table_size + TAB_SIZE_ADD;i++)
	{
		tmp[i-1].elem = 0;
		tmp[i-1].flag = 0;
	}
	
	for(int i=1;i<=pht->table_size;i++)
	{
		if(pht->pelem[i-1].flag == 1)
		{
			pindex[pindex_count++] = i;
		}
	}
	
	int tmp_index;
	for(int i=1;i<=pindex_count;i++)
	{
		tmp_index = Hash(pht->pelem[pindex[i-1]-1].elem,(pht->table_size) + TAB_SIZE_ADD) + 1;
		tmp[tmp_index-1].elem = pht->pelem[pindex[i-1]-1].elem;
		tmp[tmp_index-1].flag = 1;
	}
	free(pindex);

	free(pht->pelem);
	pht->pelem = tmp;
	pht->table_size += TAB_SIZE_ADD;
	pht->load_factor = (float)pht->elem_count / (float)pht->table_size;
}

int searchElem(HashTable ht,ElemType elem)
{
	int index;
	int tmp;
	int search_count = 0;
	
	if(ht.pelem == NULL)
		return -1;
	
	if(ht.elem_count == 0)
		return 0;
	
	index = Hash(elem,ht.table_size) + 1;
	tmp = index;
	while(ht.pelem[index-1].flag ==0 || ht.pelem[index-1].elem != elem)
	{
		search_count++;
		index++;
		if(index > ht.table_size)
		{
			index = index % ht.table_size;
		}
		
		if(index == tmp)
		{
			index = 0;
			break;
		}
	}
	
	//printf("search_count:%d\n",search_count);
	return index;
}

void deleteElem(HashTable *pht,ElemType elem)
{
	int index;
	
	index = searchElem(*pht,elem);
	if(index == -1 || index == 0)
		return;
	
	pht->pelem[index-1].elem = 0;
	pht->elem_count--;
	pht->load_factor = (float)pht->elem_count / (float)pht->table_size;
}