#pragma once
#include <cstdlib>
#include <memory>

template<typename T> class Stack
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
		base = new s_node_;
		base->next = nullptr;
	}
	void push(T data)
	{
		s_node_ *t_node = new s_node_;
		t_node->data = data;
		t_node->next = base->next;
		base->next = t_node;
	}
	void pop()
	{
		if (empty()) return;
		s_node_ *t = base->next;
		base->next = base->next->next;
		delete t;
	}

	bool empty()
	{
		if (!base->next)	return true;
		return false;
	}

	T top()
	{
		if (empty()) return false;
		return base->next->data;
	}

};