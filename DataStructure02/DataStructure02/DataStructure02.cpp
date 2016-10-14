// DataStructure02.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>


typedef struct ListNode
{
	int data;
	struct ListNode *next;
}LNode;


LNode *InitList()  //��ʼ��һ��������
{
	LNode *listHead = (LNode *)malloc(sizeof(LNode));
	listHead->next = NULL;
	return listHead;
}


void AddListNode(LNode *listHeadNode,int newNodeData)    //������ӽڵ㺯��
{
	LNode *newNode = (LNode *)malloc(sizeof(LNode));
	newNode->data = newNodeData;
	newNode->next = listHeadNode->next;
	listHeadNode->next = newNode;
}

void AddListNode(LNode *listHeadNode, int newNodeData[],int length)  //����������Ӻ���
{
	for (int index = 0 ; index < length ; index++)
	{
		LNode *newNode = (LNode *)malloc(sizeof(LNode));
		newNode->data = newNodeData[index];
		newNode->next = listHeadNode->next;
		listHeadNode->next = newNode;
	}
	
}

void ShowList(LNode *listHeadNode)    //�����������
{
	LNode *tempNode = listHeadNode->next;
	while (tempNode)
	{
		printf("%d ", tempNode->data);
		tempNode = tempNode->next;
	}
	printf("\n");

}


void ListSplit(LNode *listHeadNode)   //������
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

//����ģ��˳�������
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

//����ģ��ɾ�����Ա���ֵΪX��Ԫ��
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

//��������
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

//����ϲ�
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
		printf("��%d������ :%d  %d\n", 5-index, (list1Length <= list2Length ? newTemp1 : newTemp2)->data,
			(list1Length > list2Length ? newTemp1 : newTemp2)->data);
		endTemp->next = (list1Length <= list2Length ? newTemp1 : newTemp2);
		(list1Length <= list2Length ? newTemp1 : newTemp2)->next = (list1Length > list2Length ? newTemp1 : newTemp2);
		endTemp = (list1Length > list2Length ? newTemp1 : newTemp2);
	}
	endTemp = list1Length <= list2Length ? temp2 : temp1;
	return list1;
}

int main()  //������
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
	//AddListNode(listHeadNode,arr,13);  //���������13���ڵ�
	//AddListNode(listHeadNode,4);       //�������
	//AddListNode(listHeadNode,7);      //�������
	//ShowList(listHeadNode);           //������ǰ������
	////ListSplit(listHeadNode);          //�������
	////ShowList(listHeadNode);           //�����ֺ������
	//RetrogradeList(listHeadNode);
	//ShowList(listHeadNode);
	//RetrogradeSeqList(arr, 12);
	//DeleteElemByX(arr, 12, 3);
	system("Pause");
    return 0; 
}

