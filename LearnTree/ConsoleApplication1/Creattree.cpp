#include <stdio.h>
#include <stdlib.h>
typedef char DataType;
typedef struct Node				//二叉树的存储结构体类型
{
	DataType data;
	struct Node *Lchild;		//左孩子
	struct Node *Rchild;		//右孩子
}BiTNode, *BiTree;
BiTree CreateBiTree()
{
	DataType ch;
	BiTNode *s;
	ch = getchar();
	if (ch=='#')
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
BiTree ExchangeLR(BiTree root)
{
	if (root)
	{
		BiTree a;
		a = root->Lchild;
		root->Lchild = root->Rchild;
		root->Rchild = a;
		ExchangeLR(root->Lchild);
		ExchangeLR(root->Rchild);
	}
	return root;
}
void PreOrder(BiTree root)
{
	if (root)
	{
		printf("%c", root->data);
		PreOrder(root->Lchild);
		PreOrder(root->Rchild);
	}
}
void PreOrder2(BiTree root, int i)
{
	if (root)
	{
		printf("（%c，%d)", root->data, i);
		PreOrder2(root->Lchild, i + 1);
		PreOrder2(root->Rchild, i + 1);
	}
}
void InOrder(BiTree root)
{
	if (root)
	{
		InOrder(root->Lchild);
		printf("%c", root->data);
		InOrder(root->Rchild);
	}
}
void PostOrder(BiTree root)
{
	if (root)
	{
		PostOrder(root->Lchild);
		PostOrder(root->Rchild);
		printf("%c", root->data);
	}
}
int main()
{
	BiTree root;
	int i = 1;
	root = CreateBiTree();
	root = ExchangeLR(root);
	printf("先续打印\n");
	PreOrder(root);
	printf("\n中续打印\n");
	InOrder(root);
	printf("\n后续打印\n");
	PostOrder(root);
	system("Pause");
	return 0;
}
