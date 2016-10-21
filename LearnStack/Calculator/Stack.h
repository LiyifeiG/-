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
	explicit Stack();
	~Stack();
	void push(T data);
	void pop();
	bool empty();
	T top();
};

template <typename T>
Stack<T>::Stack()
{
	base = new s_node_;
	base->next = nullptr;
}

template <typename T>
Stack<T>::~Stack()
{
	delete base;
}

template <typename T>
void Stack<T>::push(T data)
{
	s_node_ *t_node = new s_node_;
	t_node->data = data;
	t_node->next = base->next;
	base->next = t_node;
}

template <typename T>
void Stack<T>::pop()
{
	if (empty()) return;
	s_node_ *t = base->next;
	base->next = base->next->next;
	delete t;
}

template <typename T>
bool Stack<T>::empty()
{
	if (!base->next)	return true;
	return false;
}

template <typename T>
T Stack<T>::top()
{
	if (empty()) return false;
	return base->next->data;
}
