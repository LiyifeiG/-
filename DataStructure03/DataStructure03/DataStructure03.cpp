//
// DataStructure03.cpp : �������̨Ӧ�ó������ڵ㡣
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
PLNode *GetOutNumber(PLNode *headNode, int m, PLNode *curPos);  //��ó��е�ֵ
void ShowNumber(PLNode *headNode, int n, int m , int arr[]);
void ShowList(PLNode *HeadNode);



PLNode *InitList()   //��ʼ������
{
	PLNode *headNode = (PLNode *)malloc(sizeof(PLNode));
	headNode->next = headNode;
	return headNode;
}

PLNode *InitList(int n)  //��ʼ������
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

void SetList(PLNode *HeadNode , int n , int arr[])   //���ݳ�ʼ������
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

PLNode *GetOutNumber(PLNode *headNode , int m , PLNode *curPos)  //��ó��нڵ�
{
	while(--m > 0)    //�ҵ�m��������Ӧ�Ľڵ�
	{
		curPos = curPos->next;
		if (curPos->next == headNode)                   //���m���ֶ�Ӧ����ͷ�ڵ�  ������һ��
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
		curPos = GetOutNumber(headNode, m, curPos);  //���ݵ�ǰ��������ֵ�����һ�γ��еĽڵ�   ���ѵ�ǰ����ƶ����˽ڵ�
		m = curPos->next->number;                    //��ó�Ա���
		printf("%d ",  curPos->next->index);               //�����Ա���
		curPos->next = curPos->next->next;           //ѡ���ĳ�Ա����                   
		if (curPos->next == headNode)                //�����һ����ͷ�ڵ�  ������ǰһ��
		{
			curPos = curPos->next;
		}
	}                                 //����
}

void ShowList(PLNode *HeadNode)    //�������
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

