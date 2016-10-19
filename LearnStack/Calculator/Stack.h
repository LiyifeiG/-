#pragma once
#include <cstdlib>
#include <memory>

template<class T> class Stack
{
private:
	typedef struct node
	{
		T data;
		struct node *next;
	}s_node_;
private:
	s_node_ *base;
public:
	Stack()
	{
		base = new s_node_[1];
		base->next = nullptr;
	}
	void Push(T data)
	{
		s_node_ *t_node = new s_node_[1];
		t_node->data = data;
		t_node->next = base->next;
		base->next = t_node;
	}
	void Pop()
	{
		if (Empty()) return;
		base->next = base->next->next;
	}

	bool Empty()
	{
		if (!base->next)	return true;
		return false;
	}

	T Top()
	{
		if (Empty()) return false;
		return base->next->data;
	}

};
