#ifndef CONFIG_H
#define CONFIG_H

//二叉树声明
typedef int TreeElemType;
#define EMPTY 0
#define END -1

typedef struct TreeNode
{
	TreeElemType data;
	struct TreeNode *parent;
	struct TreeNode *lchild;
	struct TreeNode *rchild;
}TreeNode,*PTreeNode;

typedef PTreeNode BitTree;
//二叉树声明结束

//栈声明
#define DEFAULT_SIZE 25
#define ADD_SIZE 10

typedef PTreeNode StackElemType;

typedef struct
{
	StackElemType *top;
	StackElemType *base;
	int ava_size;
	int add_count;
}Stack,*PStack;
//栈声明结束

//队列声明
typedef TreeNode* QueueElemType;

typedef struct QueueNode
{
	QueueElemType data;
	struct QueueNode *next;
}QueueNode,*PQueueNode;

typedef struct
{
	QueueNode *front;
	QueueNode *rear;
}Queue,*PQueue;
//队列声明结束

#endif