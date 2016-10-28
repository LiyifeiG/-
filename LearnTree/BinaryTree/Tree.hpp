#pragma once
#include <memory>
#include <string>


//�����ֵܽڵ㷨��
template<typename T>
class Tree
{
private:
	struct t_node_
	{
		T _data;
		std::shared_ptr<t_node_> _first_child_;        //�˽ڵ�ĵ�һ�����ӽڵ�
		std::shared_ptr<t_node_> _next__sibling_;      //�˽ڵ����һ���ֵܽڵ�
	};
private:
	std::shared_ptr<t_node_> _root_node_;
public:
	Tree();
	void Clear();
	bool Empty() const;
	int Depth() const;
	int NumberOfNode() const;
	int NumberOfLeaf() const;
	T* GetAllNodeByPre() const;
	T* GetAllNodeByAft() const;
};

//��ʼ������
template<typename T>
inline Tree<T>::Tree()
{
	_root_node_ = std::make_shared<t_node_>();
}

template<typename T>
inline void Tree<T>::Clear()
{
}

template<typename T>
inline bool Tree<T>::Empty() const
{
	return false;
}

template<typename T>
inline int Tree<T>::Depth() const
{
	return 0;
}

template<typename T>
inline int Tree<T>::NumberOfNode() const
{
	return 0;
}

template<typename T>
inline int Tree<T>::NumberOfLeaf() const
{
	return 0;
}

template<typename T>
inline T * Tree<T>::GetAllNodeByPre() const
{
	return NULL;
}

template<typename T>
inline T * Tree<T>::GetAllNodeByAft() const
{
	return NULL;
}
