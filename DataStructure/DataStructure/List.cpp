#include "stdafx.h"
#include "List.h"

template<typename T>
List<T>::List()
{
	ListHeadNode = new struct ListNode;
	ListEndNode = ListHeadNode;
}

template<typename T>
List<T>::~List()
{
	delete this->ListHeadNode;
	delete this->ListEndNode;
}

template<typename T>
void List<T>::insert(T data)
{
	struct ListNode *NewNode = new struct ListNode;
	NewNode->data = data;
	this->ListEndNode->ListNextNode = NewNode;
}

template<typename T>
void List<T>::append(T data)
{
}

template<typename T>
void List<T>::clear()
{
}

template<typename T>
T List<T>::remove(T data)
{
	return false;
}

template<typename T>
T List<T>::indexof(T data)
{
	return T();
}

template<typename T>
T List<T>::operator[](int index)
{
	return this->indexof(index);
}