#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef char DataType;
typedef struct Node				//�������Ĵ洢�ṹ������
{
	DataType data;
	struct Node *Lchild;		//����
	struct Node *Rchild;		//�Һ���
}BiTNode, *BiTree;

BiTNode *CreatByPl(char *pre, char *in, int n)			//�������򴴽�������
{
	BiTNode *s;
	int pos;
	char *p;
	if (n<=0)
	{
		return NULL;
	}
	s = (BiTNode *)malloc(sizeof(BiTNode));
	s->data = *pre;
	for (p = in; p < in + n;p++)
	{
		if (*p==*pre)
		{
			break;
		}
	}
	pos = p - in;
	s->Lchild = CreatByPl(pre + 1, in, pos);
	s->Rchild = CreatByPl(pre + pos + 1, p + 1, n - pos - 1);
	return s;
}
BiTNode* CreatBylP(char *in, char *post, int n)//������򴴽�������
{
	BiTNode *s;
	int pos; 
	char *p;
	if (n<=0)
	{
		return NULL;
	}
	s = (BiTNode *)malloc(sizeof(BiTNode));
	s->data = *(post + n - 1);
	for (p = in; p < in + n;p++)
	{
		if (*p == *(post + n - 1))
		{
			break;
		}
	}
	pos = p - in;
	s->Lchild = CreatBylP(in, post, pos);
	s->Rchild = CreatBylP(p + 1, post + pos, n - pos - 1);
	return s;


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
void PreOrder(BiTree root)
{
	if (root)
	{
		printf("%c", root->data);
		PreOrder(root->Lchild);
		PreOrder(root->Rchild);
	}
}

int main()
{
	BiTree root;
	char arr1[51];
	char arr2[51];
	scanf("%s%s", arr1 , arr2);
	//char *p = arr1;
	//char*q = arr2;
	root = CreatBylP(arr1, arr2, strlen(arr1));
	//root=CreatByPl(arr1, arr2, strlen(arr1));
	//PostOrder(root);
	PreOrder(root);
	system("Pause");

}