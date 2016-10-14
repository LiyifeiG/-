//
// DataStructure03.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct PeopleListNode
{
	int number;
	int index;
	struct PeopleListNode *next;
}PLNode;


PLNode *InitList();
void SetList(PLNode *HeadNode, int n , int arr[]);
PLNode *GetOutNumber(PLNode *headNode, int m, PLNode *curPos);  //获得出列的值
void ShowNumber(PLNode *headNode, int n, int m , int arr[]);
void ShowList(PLNode *HeadNode);



PLNode *InitList()   //初始化链表
{
	PLNode *headNode = (PLNode *)malloc(sizeof(PLNode));
	headNode->next = headNode;
	return headNode;
}

PLNode *InitList(int n)  //初始化链表
{
	PLNode *headNode = (PLNode *)malloc(sizeof(PLNode));
	headNode->next = headNode;
	while (n > 0)
	{
		PLNode *newNode = (PLNode *)malloc(sizeof(PLNode));
		newNode->number = n;
		newNode->index = 0;
		newNode->next = headNode->next;
		headNode->next = newNode;
		n--;
	}
	return headNode;
}

void SetList(PLNode *HeadNode , int n , int arr[])   //根据初始化链表
{
	while (n > 0)
	{
		PLNode *tempNode = (PLNode *)malloc(sizeof(PLNode));
		tempNode->index = n;
		tempNode->number = arr[n-1];
		n--;
		tempNode->next = HeadNode->next;
		HeadNode->next = tempNode;
	}
}

PLNode *GetOutNumber(PLNode *headNode , int m , PLNode *curPos)  //获得出列节点
{
	while(--m > 0)    //找到m数字所对应的节点
	{
		curPos = curPos->next;
		if (curPos->next == headNode)                   //如果m数字对应的是头节点  则往下一个
		{
			curPos = curPos->next;
		}
	}
	//printf("%d   ", curPos->next->number);
	return curPos;
}

void ShowNumber(PLNode *headList , int m)
{
	PLNode *curNode = GetOutNumber(headList, m, headList->next);
	while (headList->next != headList)
	{
		printf("%d", curNode->next->number);
		curNode->next = curNode->next->next;
		curNode = GetOutNumber(headList, m, curNode);
	}
}

void ShowNumber(PLNode *headNode, int n, int m , int arr[])
{
	SetList(headNode, n , arr);
	PLNode *curPos = headNode;
	int count = 0;
	while (headNode->next != headNode)
	{
		curPos = GetOutNumber(headNode, m, curPos);  //根据当前结点和密码值获得下一次出列的节点   并把当前结点移动到此节点
		m = curPos->next->number;                    //获得成员编号
		printf("%d ",  curPos->next->index);               //输出成员编号
		curPos->next = curPos->next->next;           //选定的成员出列                   
		if (curPos->next == headNode)                //如果下一个是头节点  则再往前一个
		{
			curPos = curPos->next;
		}
	}                                 //换行
}

void ShowList(PLNode *HeadNode)    //输出链表
{
	PLNode *temp = HeadNode->next;
	while (temp != HeadNode)
	{
		printf("%d ", temp->number);
		temp = temp->next;
	}
	printf("\n");
}



int main()
{
	PLNode *listHeadNode = InitList();
	int N, M;
	scanf("%d%d",&N,&M);
	ShowNumber(listHeadNode,M);
    return 0;
}

