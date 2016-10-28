#pragma once
#include <memory>
#include <string>


//孩子兄弟节点法树
template<typename T>
class Tree
{
private:
	struct t_node_
	{
		T _data;
		std::shared_ptr<t_node_> _first_child_;        //此节点的第一个孩子节点
		std::shared_ptr<t_node_> _next__sibling_;      //此节点的下一个兄弟节点
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

//初始化空树
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
