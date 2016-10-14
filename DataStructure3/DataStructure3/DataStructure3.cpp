// DataStructure3.cpp : 定义控制台应用程序的入口点。
//


//循环队列
#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>

//定义节点数据结构体
typedef struct Node
{
	int data;
	struct Node *next;
}QNode;

//定义循环队列
typedef struct
{
	QNode *front;
	QNode *rear;
}LQueue;


//函数声明
LQueue *InitLQueue();
bool InLQueue(LQueue *q, int data);
bool IsEmpty(LQueue *q);
bool IsFull(LQueue *q);
bool OutQueue(LQueue *q , int *data);

//初始化空队列
LQueue *InitLQueue()
{
	LQueue *q = (LQueue *)malloc(sizeof(LQueue));  //创建队列头尾点
	QNode *p = (QNode *)malloc(sizeof(QNode));     //创建节点
	p->next = NULL;                                //节点下一个置空
	q->front = q->rear = p;                        //头尾的节点均为p
	return q;                                      //返回头尾
}

bool InLQueue(LQueue *q, int data)
{
	if (IsFull(q))
	{
		printf("队列已满，无法入队!\n");
		return false;
	}
	QNode *newNode = (QNode*)malloc(sizeof(QNode));     //创建新节点
	newNode->data = data;                               //为新节点赋值
	newNode->next = NULL;
	q->rear->next = newNode;                            //将新节点安插在队尾
	q->rear = newNode;        //队尾移动  跟踪指针移动
	return true;
}

//判断队空
bool IsEmpty(LQueue *q)
{
	if (q->rear == q->front)
	{
		return true;
	}
	return false;
}

//判断队满
bool IsFull(LQueue *q)
{
	if (q->rear->next == q->front)
	{
		return true;
	}
	return false;
}

//出队
bool OutQueue(LQueue *q , int *data)
{
	if (IsEmpty(q))
	{
		printf("队列为空，无法出队");
		return false;
	}
	QNode *t = q->front->next;  //获取队首
	*data = t->data;              //获取之前队首的信息赋值给data
	q->front->next = q->front->next->next;  //将头节点连至之前第二个节点作为新的队首
	t->next = NULL;
	free(t);
	if (q->front->next == NULL)
	{
		q->front = q->rear;
	}
	return true;
}



int main()
{
	LQueue *queue = InitLQueue();
	InLQueue(queue, 3);
	InLQueue(queue, 7);
	int data;
	if (OutQueue(queue,&data))
	{
		printf("%d\n", data);
	}
	InLQueue(queue, 8);
	if (OutQueue(queue, &data))
	{
		printf("%d\n", data);
	}
	system("Pause");
    return 0;
}

