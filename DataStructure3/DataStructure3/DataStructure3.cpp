// DataStructure3.cpp : �������̨Ӧ�ó������ڵ㡣
//


//ѭ������
#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>

//����ڵ����ݽṹ��
typedef struct Node
{
	int data;
	struct Node *next;
}QNode;

//����ѭ������
typedef struct
{
	QNode *front;
	QNode *rear;
}LQueue;


//��������
LQueue *InitLQueue();
bool InLQueue(LQueue *q, int data);
bool IsEmpty(LQueue *q);
bool IsFull(LQueue *q);
bool OutQueue(LQueue *q , int *data);

//��ʼ���ն���
LQueue *InitLQueue()
{
	LQueue *q = (LQueue *)malloc(sizeof(LQueue));  //��������ͷβ��
	QNode *p = (QNode *)malloc(sizeof(QNode));     //�����ڵ�
	p->next = NULL;                                //�ڵ���һ���ÿ�
	q->front = q->rear = p;                        //ͷβ�Ľڵ��Ϊp
	return q;                                      //����ͷβ
}

bool InLQueue(LQueue *q, int data)
{
	if (IsFull(q))
	{
		printf("�����������޷����!\n");
		return false;
	}
	QNode *newNode = (QNode*)malloc(sizeof(QNode));     //�����½ڵ�
	newNode->data = data;                               //Ϊ�½ڵ㸳ֵ
	newNode->next = NULL;
	q->rear->next = newNode;                            //���½ڵ㰲���ڶ�β
	q->rear = newNode;        //��β�ƶ�  ����ָ���ƶ�
	return true;
}

//�ж϶ӿ�
bool IsEmpty(LQueue *q)
{
	if (q->rear == q->front)
	{
		return true;
	}
	return false;
}

//�ж϶���
bool IsFull(LQueue *q)
{
	if (q->rear->next == q->front)
	{
		return true;
	}
	return false;
}

//����
bool OutQueue(LQueue *q , int *data)
{
	if (IsEmpty(q))
	{
		printf("����Ϊ�գ��޷�����");
		return false;
	}
	QNode *t = q->front->next;  //��ȡ����
	*data = t->data;              //��ȡ֮ǰ���׵���Ϣ��ֵ��data
	q->front->next = q->front->next->next;  //��ͷ�ڵ�����֮ǰ�ڶ����ڵ���Ϊ�µĶ���
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

