#include <stdio.h>
#include <stdlib.h>
typedef char DataType;
typedef struct Node				//二叉树的存储结构体类型
{
	DataType data;
	struct Node *Lchild;		//左孩子
	struct Node *Rchild;		//右孩子
}BiTNode, *BiTree;
int count=0;
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

void PreOrder(BiTree root)
 {
 	if (root)
 	{
 		count++;
 		PreOrder(root->Lchild);
		PreOrder(root->Rchild);
 	}
 }
int leaf(BiTree root)
{
	int nl, nr;
	if (root==NULL)
	{
		return 0;
	}
	if ((root->Lchild==NULL)&&(root->Rchild==NULL))
	{
		return 1;
	}
	nl = leaf(root->Lchild);
	nr = leaf(root->Rchild);
	return (nr + nl);
}
int onedu(BiTree root)
{
	int nl, nr;
	if (root == NULL)
	{
		return 0;
	}
	nl = onedu(root->Lchild);
	nr = onedu(root->Rchild);
	if (((root->Lchild == NULL) && (root->Rchild != NULL)) || 
		((root->Lchild != NULL) && (root->Rchild == NULL)))
	{
		return nr+nl+1;
	}
	return (nr + nl);

}
int twodu(BiTree root)
{
	int nl, nr;
	if (root == NULL)
	{
		return 0;
	}
	nl = twodu(root->Lchild);
	nr = twodu(root->Rchild);
	if ((root->Lchild != NULL) && (root->Rchild != NULL))
	{
		return nr+nl+1;
	}
	return (nr + nl);
}
void InOrder(BiTree root)
{
	if (root)
	{
		InOrder(root->Lchild);
		if (root->Lchild==NULL&&root->Rchild==NULL)
		{
			printf("%c",root->data);
		}
		InOrder(root->Rchild);
	}
}
int main()
{
	BiTree root;
	root = CreateBiTree();
	PreOrder(root);
	printf("%d\n", count);
	int a = leaf(root);
	int b = onedu(root);
	int c = twodu(root);
	printf("%d %d %d\n", a, b, c);
	InOrder(root);
	system("Pause");
	return 0;

}