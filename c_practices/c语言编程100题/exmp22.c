/*
N名学生的成绩已在主函数中放入一个带头节点的链表结构中，h指向链表的头节点。
请编写函数fun，它的功能是：找出学生的最高分，由函数值返回。
*/

#include<stdio.h>
#include<stdlib.h>

#define LIST_LEN 10

/*链表声明*/
typedef float elem_type;

typedef struct node
{
	elem_type score;
	struct node *next;
}link_node,*p_link_node;   //链表节点

typedef p_link_node link_list;

void initLinklist(link_list *plist);

void createLinklist(link_list list,elem_type array[],int n);

void destroyLinklist(link_list *plist);

void printLinklist(link_list list);
/*end*/

elem_type function(link_list list);

int main(void)
{
	link_list list;
	elem_type array[10] = {75,80,65,90,88,84,96,91,76,82};
	elem_type max;
	
	initLinklist(&list);
	createLinklist(list,array,10);
	printf("list:");
	printLinklist(list);
	printf("max:%.2f\n",function(list));
	destroyLinklist(&list);
	//printLinklist(list);
	
	return 0;
}

/*链表实现*/
void initLinklist(link_list *plist)
{
	(*plist) = (p_link_node)malloc(sizeof(link_node));
	if(!(*plist))
	{
		printf("memory full!\n");
		exit(1);
	}
	
	(*plist)->next = NULL;
}

void createLinklist(link_list list,elem_type array[],int n)
{
	p_link_node p,q;
	
	p = list;
	for(int i=1;i<=n;i++)
	{
		q = (p_link_node)malloc(sizeof(link_node));
		if(!q)
		{
			printf("memory full\n");
			exit(1);
		}
		
		q->next = NULL;
		q->score = array[i-1];
		p->next = q;
		p = q;
	}
}

void printLinklist(link_list list)
{
	p_link_node p = list;
	
	if(!list)
	{
		printf("list have been destroyed!\n");
		return;
	}
	
	if(!p->next)
	{
		printf("empty!\n");
		return;
	}
	
	p = list->next;
	while(p)
	{
		printf("%.2f ",p->score);
		p = p->next;
	}
	printf("\n");
}

void destroyLinklist(link_list *plist)
{
	p_link_node p,q;
	
	if(!(*plist))
	{
		return;
	}
	
	if(!(*plist)->next)
	{
		free((*plist));
		(*plist) = NULL;
		return;
	}
	
	p = (*plist);
	q = p->next;
	while(q)
	{
		free(p);
		p = q;
		q = p->next;
	}
	(*plist) = NULL;
}
/*end*/

elem_type function(link_list list)
{
	p_link_node p;
	elem_type max_score;
	
	p = list->next;
	max_score = p->score;
	while(p)
	{
		if(p->score > max_score)
		{
			max_score = p->score;
		}
		p = p->next;
	}
	
	return max_score;
}