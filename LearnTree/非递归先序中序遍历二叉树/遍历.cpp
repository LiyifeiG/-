#include <stdio.h>
#include <stdlib.h>
typedef char DataType;
typedef struct Node				//二叉树的存储结构体类型
{
	DataType data;
	struct Node *Lchild;		//左孩子
	struct Node *Rchild;		//右孩子
}BiTNode, *BiTree;
typedef BiTree stackDataType;
typedef struct 
{
	stackDataType data[20];
	int top;
}SeqStack;
SeqStack *InitSeqStack()
{
	SeqStack *s;
	s = (SeqStack*)malloc(sizeof(SeqStack));
	s->top = -1;
	return s;
}
int EmptySeqStack(SeqStack *s)
{
	if (s->top==-1)
	{
		return -1;
	}
	else
	{
		return 0;
	}
}
int Push(SeqStack *s, stackDataType x)
{
	if (s->top==19)
	{
		return 0;
	}
	else{
		s->top++;
		s->data[s->top] = x;
		return 1;
	}
}
int Pop(SeqStack *s, stackDataType *x)
{
	if (EmptySeqStack(s))
	{
		return 0;
	}
	else
	{
		*x = s->data[s->top];
		s->top--;
		return 1;
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
stackDataType Top(SeqStack *s)
{
	if (EmptySeqStack(s))
	{
		return 0;
	}
	else
	{
		return (s->data[s->top]);
	}
}
void PreOrder(BiTree root)
{
	SeqStack *s = InitSeqStack();
	BiTree p;

	p = root;
	while (p!=NULL|| !EmptySeqStack(s))
	{
		while (p!=NULL)
		{
			printf("%c", p->data);
			Push(s, p); //栈里边应该是节点
			p = p->Lchild;
			
		}
		if (!EmptySeqStack(s)) //应该在第二个while外边
		{
			Pop(s, &p);               //如果要给p复制    应该函数里边传进去地址而不是值
			p = p->Rchild;
		}

	}
}
void InOrder(BiTree root)
{
	SeqStack *s=InitSeqStack();
	BiTree p;
	p = root;
	while (p!=NULL||!EmptySeqStack(s))
	{
		while (p!=NULL)
			{
				Push(s, p);
				p = p->Lchild;
			}
			if (!EmptySeqStack(s))
			{
				Pop(s, &p);
				printf("%c", p->data);
				p = p->Rchild;
			}
	}
}
void PostOrder(BiTree root)
{
	SeqStack *s = InitSeqStack();
	BiTree p, q;
	p = root;
	q = NULL;
	while (p!=NULL||!EmptySeqStack(s))
	{
		while (p!=NULL)
		{
			Push(s, p);
			p = p->Lchild;
		}
		if (!EmptySeqStack(s))
		{
			p=Top(s);
			if ((p->Rchild == NULL) || (p->Rchild == q))
			{
				Pop(s, &p);
				printf("%c", p->data);
				q = p;
				p = NULL;
			}
			else
				p = p->Rchild;
		}
	}
}
int main()
{
	BiTree root;
	root = CreateBiTree();
	PreOrder(root);
	printf("\n");
	InOrder(root);
	printf("\n");
	PostOrder(root);
	system("Pause");
	return 0;
}

