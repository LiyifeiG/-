#include <stdio.h>
#include <stdlib.h>
typedef char DataType;
typedef struct Node				//�������Ĵ洢�ṹ������
{
	DataType data;
	struct Node *Lchild;		//����
	struct Node *Rchild;		//�Һ���
}BiTNode, *BiTree;
typedef BiTree queueDataType;
typedef struct 
{
	queueDataType data[20];
	int front;
	int rear;
}CSeQueue;
CSeQueue *InitSeQueue()
{
	CSeQueue *q;
	q=(CSeQueue*)malloc(sizeof(CSeQueue));
	q->front = q->rear = 19;
	return q;
}
int InSeQueue(CSeQueue *q,queueDataType x)
{
	if ((q->rear+1)%20==q->front)
	{
		printf("����");
		return false;
	}
	else
	{
		q->rear =(q->rear + 1) % 20;
		q->data[q->rear] = x;
		return true;
	}
}
int OutSeQueue(CSeQueue *q, queueDataType *x)
{
	if (q->front==q->rear)
	{
		printf("�ӿ�");
		return false;
	}
	else
	{
		q->front = (q->front + 1) % 20;
		*x = q->data[q->front];
		return true;
	}
}
int EmptySeQueue(CSeQueue *q)
{
	if (q->front==q->rear)
	{
		return true;
	}
	else
	{
		return false;
	}
}
void LevelOrder(BiTree root)
{
	 CSeQueue *q=InitSeQueue();
	 BiTree p;
	 InSeQueue(q, root);
	 while (!EmptySeQueue(q))
	 {
		 OutSeQueue(q, &p);
		 printf("%c", p->data);
		 if (p->Lchild!=NULL)
		 {
			 InSeQueue(q, p->Lchild);
		 }
		 if (p->Rchild!=NULL)
		 {
			 InSeQueue(q, p->Rchild);
		 }
	 }
}
BiTree CreateBiTree()
{
	DataType ch;
	BiTNode *s;
	ch = getchar();
	if (ch == '#')
	{
		return NULL;
	}
	else
	{
		s = (BiTNode*)malloc(sizeof(BiTNode));
		s->data = ch;
		s->Lchild = CreateBiTree();
		s->Rchild = CreateBiTree();
		return s;
	}
}
int main()
{
	BiTree root;
	root = CreateBiTree();
	LevelOrder(root);
	system("Pause");
	return 0;
}
