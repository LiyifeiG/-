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
void Allpath(BiTree root, char path[], int n)
{
	int i;
	if (root)
	{
		if (root->Lchild==NULL&&root->Rchild==NULL)
		{
				printf("%c:", root->data);
				for (i = 0; i < n; i++)
				{
					printf("%c", path[i]);
				}
				printf("\n");
		}
		else
		{
			path[n] = root->data;
			Allpath(root->Lchild, path, n+1);
			Allpath(root->Rchild, path, n+1);
		}
	}
}
int main()
{
	BiTree root;
	root = CreateBiTree();
	char path[20];
	Allpath(root, path, 0);
	system("Pause");
	return 0;
}
