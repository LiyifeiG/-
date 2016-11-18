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
int Klevel(BiTree root, int k){
	if (root == NULL || k <= 0)
		return 0;
	if (root != NULL && k == 1){
		if (root->Lchild== NULL && root->Rchild== NULL)
			return 1;
		else
			return 0;
	}
	return (Klevel(root->Lchild, k - 1) + Klevel(root->Rchild, k - 1));
}
int main()
{
	BiTree root;
	int n;
	root = CreateBiTree();
	scanf("%d", &n);
	int m= Klevel(root, n);
	printf("%d", m);
	system("Pause");
	return 0;
}
