// DataStructure02.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>


typedef struct ListNode
{
	int data;
	struct ListNode *next;
}LNode;


LNode *InitList()  //初始化一个空链表
{
	LNode *listHead = (LNode *)malloc(sizeof(LNode));
	listHead->next = NULL;
	return listHead;
}


void AddListNode(LNode *listHeadNode,int newNodeData)    //链表添加节点函数
{
	LNode *newNode = (LNode *)malloc(sizeof(LNode));
	newNode->data = newNodeData;
	newNode->next = listHeadNode->next;
	listHeadNode->next = newNode;
}

void AddListNode(LNode *listHeadNode, int newNodeData[],int length)  //重载链表添加函数
{
	for (int index = 0 ; index < length ; index++)
	{
		LNode *newNode = (LNode *)malloc(sizeof(LNode));
		newNode->data = newNodeData[index];
		newNode->next = listHeadNode->next;
		listHeadNode->next = newNode;
	}
	
}

void ShowList(LNode *listHeadNode)    //输出链表内容
{
	LNode *tempNode = listHeadNode->next;
	while (tempNode)
	{
		printf("%d ", tempNode->data);
		tempNode = tempNode->next;
	}
	printf("\n");

}


void ListSplit(LNode *listHeadNode)   //链表拆分
{
	LNode *tempNode = listHeadNode->next , *temp = tempNode ;
	while (temp->next)
	{
		if (temp->next->data < tempNode->data)
		{
			AddListNode(listHeadNode, temp->next->data);
			temp->next = temp->next->next;
		}
		else
		{
			temp = temp->next;
		}
	}
}

//数组模拟顺序表逆置
template <typename T> void RetrogradeSeqList(T arr[] , int length)
{
	for (int index1 = 1 , index2 = length ; index1 < index2 ; index1++ , index2--)
	{
		T temp = arr[index1];
		arr[index1] = arr[index2];
		arr[index2] = temp;
	}
	for (int i = 1 ; i <= length ; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n\n");
}

//数组模拟删除线性表中值为X的元素
template <typename T> void DeleteElemByX(T arr[] , int length , T X)
{
	for (int index = 1 ; index <= length ; index++)
	{
		if (arr[index] == X)
		{
			for (int index1 = index ; index1 < length ; index1++)
			{
				arr[index1] = arr[index1+1];
			}
			--length;
		}
	}
	for (int index = 1; index <= length; index++)
	{
		printf("%d ", arr[index]);
	}
}

//链表逆置
void RetrogradeList(LNode *listHeadNode)
{
	LNode *temp_node = listHeadNode->next;
	listHeadNode->next = NULL;
	while (temp_node)
	{
		LNode *temp = temp_node;
		temp_node = temp_node->next;
		temp->next = listHeadNode->next;
		listHeadNode->next = temp;
	}
}

//链表合并
LNode *CombinedList(LNode *list1, int list1Length, LNode *list2 , int list2Length)
{
	LNode *temp1 = list1->next, *temp2 = list2->next, *newTemp1, *newTemp2, *endTemp = list1 ;
	int index = list1Length <= list2Length ? list1Length : list2Length;
	while (index > 0)
	{
		--index;
		newTemp1 = temp1;
		newTemp2 = temp2;
		temp1 = temp1->next;
		temp2 = temp2->next;
		printf("第%d次连接 :%d  %d\n", 5-index, (list1Length <= list2Length ? newTemp1 : newTemp2)->data,
			(list1Length > list2Length ? newTemp1 : newTemp2)->data);
		endTemp->next = (list1Length <= list2Length ? newTemp1 : newTemp2);
		(list1Length <= list2Length ? newTemp1 : newTemp2)->next = (list1Length > list2Length ? newTemp1 : newTemp2);
		endTemp = (list1Length > list2Length ? newTemp1 : newTemp2);
	}
	endTemp = list1Length <= list2Length ? temp2 : temp1;
	return list1;
}

int main()  //主函数
{
	LNode *list1 = InitList();
	LNode *list2 = InitList();
	int arr2[] = { 9,7,5,3,1};
	int arr1[] = { 16,14,12,10,8,6,4,2 };
	AddListNode(list1, arr1, 8);
	AddListNode(list2, arr2, 5);
	ShowList(list1);
	ShowList(list2);
	ShowList(CombinedList(list1, 8, list2, 5));
	//AddListNode(listHeadNode,arr,13);  //给链表添加13个节点
	//AddListNode(listHeadNode,4);       //单独添加
	//AddListNode(listHeadNode,7);      //单独添加
	//ShowList(listHeadNode);           //输出拆分前的链表
	////ListSplit(listHeadNode);          //拆分链表
	////ShowList(listHeadNode);           //输出拆分后的链表
	//RetrogradeList(listHeadNode);
	//ShowList(listHeadNode);
	//RetrogradeSeqList(arr, 12);
	//DeleteElemByX(arr, 12, 3);
	system("Pause");
    return 0; 
}

