#pragma once
#include <memory>
#include <iostream>
#include <sstream>
using namespace std;
template<typename T>
class BinaryTree
{
private:
	typedef struct node
	{
		T data;
		shared_ptr<struct node> lChild;
		shared_ptr<struct node> rChild;
	}t_node_;
private:
	shared_ptr<t_node_> root_node_;
	static bool CreatNode(shared_ptr<t_node_> node , string buffer_data , int buf_index);
	static void PrintNode(shared_ptr<t_node_> node , int depth_t_);
	void GetTreeByPre(shared_ptr<t_node_> root , stringstream &ss) const;
	void GetTreeByMid(shared_ptr<t_node_> root , stringstream &ss) const;
	void GetTreeByAft(shared_ptr<t_node_> root , stringstream &ss) const;
	int GetNumOfNode(shared_ptr<t_node_> root) const;
	int GetNumOfLeaf(shared_ptr<t_node_> root) const;
	int GetDepth(shared_ptr<t_node_> root , int number) const;
	void CreateTreeByPreOrder(shared_ptr<t_node_> root , char nullCh);
public:
	// ReSharper disable once CppDeclarationSpecifierWithoutDeclarators
	const enum Order {
		Preorder = 1 ,
		Inorder = 2 ,
		Aftorder = 3
	};
	explicit BinaryTree();
	explicit BinaryTree(char nullCh);
	explicit BinaryTree(string buf);
	~BinaryTree();
public:
	string GetAllTreeNode(Order order) const;
	int Depth() const;
	int NumberOfNode() const;
	int NumberOfLeaf() const;
	void PrintTree() const;
	void Clear();
	void Destory();
	bool Like(const shared_ptr<BinaryTree> &tree);
};


//�ַ���ͨ����δ���������
template<typename T>
bool BinaryTree<T>::CreatNode(shared_ptr<t_node_> node , string buffer_data , int buf_index)
{
	node->data = buffer_data[buf_index - 1];
	node->lChild = nullptr;
	node->rChild = nullptr;
	if ((2 * buf_index) <= static_cast<int>(buffer_data.length()))
	{
		node->lChild = std::make_shared<t_node_>();;
		CreatNode(node->lChild , buffer_data , 2 * buf_index);
	}

	if ((2 * buf_index + 1) <= static_cast<int>(buffer_data.length()))
	{
		node->rChild = std::make_shared<t_node_>();;
		CreatNode(node->rChild , buffer_data , 2 * buf_index + 1);
	}
	return true;
}

//�չ��캯������������
template<typename T>
BinaryTree<T>::BinaryTree()
{
	root_node_ = std::make_shared<t_node_>();
	root_node_->data = ' ';
}
//ʹ��"��չ�����������"������������
template<typename T>
inline BinaryTree<T>::BinaryTree(char nullCh)
{
	root_node_ = std::make_shared<t_node_>();
	CreateTreeByPreOrder(root_node_ , nullCh);
}

//��������
template<typename T>
BinaryTree<T>::~BinaryTree()
{
	root_node_.reset();
}

//����ö�ٲ���������ַ���
template<typename T>
string BinaryTree<T>::GetAllTreeNode(Order order) const
{
	// ReSharper disable once CppNonReclaimedResourceAcquisition
	//shared_ptr<stringstream> ss(new stringstream);
	auto ss = make_shared<stringstream>();
	switch (order)
	{
		case Preorder:GetTreeByPre(root_node_ , *ss); break;
		case Inorder: GetTreeByMid(root_node_ , *ss); break;
		case Aftorder:GetTreeByAft(root_node_ , *ss); break;
		default: break;
	}
	return ss->str();
}

//�ó��������߶�
template<typename T>
int BinaryTree<T>::Depth() const
{
	return GetDepth(root_node_ , 0);
}
//�ó����ڵ����
template<typename T>
int BinaryTree<T>::NumberOfNode() const
{
	return GetNumOfNode(root_node_);
}
//�ó���Ҷ�ӽڵ����
template<typename T>
int BinaryTree<T>::NumberOfLeaf() const
{
	return GetNumOfLeaf(root_node_);
}
//��״��ӡ������
template<typename T>
inline void BinaryTree<T>::PrintTree() const
{
	PrintNode(root_node_ , 0);
}

template<typename T>
inline void BinaryTree<T>::Clear()
{
	root_node_.reset();
	root_node_ = make_shared<t_node_>();
}

template<typename T>
inline void BinaryTree<T>::Destory()
{
	root_node_.reset();
}

template<typename T>
inline bool BinaryTree<T>::Like(const shared_ptr<BinaryTree<T>> &tree)
{
	if (tree->GetAllTreeNode(Preorder) != this->GetAllTreeNode(Preorder) 
		|| tree->GetAllTreeNode(Inorder) != this->GetAllTreeNode(Inorder)) 
			return false;
	return true;
}


//��״��ӡ������
template<typename T>
void BinaryTree<T>::PrintNode(shared_ptr<t_node_> node , int depth_t_)
{
	if (!node.get() || !node->data) return;
	PrintNode(node->rChild , depth_t_ + 1);
	for (auto i = 0; i < depth_t_; i++)
		std::cout << "     ";
	std::cout << node->data << std::endl;
	PrintNode(node->lChild , depth_t_ + 1);
}

//�õ�ǰ��ڵ��ַ���
template<typename T>
void BinaryTree<T>::GetTreeByPre(shared_ptr<t_node_> root , stringstream &ss) const
{
	if (!root.get() || !root->data) return;
	ss << root->data;
	GetTreeByPre(root->lChild , ss);
	GetTreeByPre(root->rChild , ss);
}

//�õ�����ڵ��ַ���
template<typename T>
void BinaryTree<T>::GetTreeByMid(shared_ptr<t_node_> root , stringstream &ss) const
{
	if (!root.get() || !root->data) return;
	GetTreeByMid(root->lChild , ss);
	ss << root->data;
	GetTreeByMid(root->rChild , ss);
}

//�õ�����ڵ��ַ���
template<typename T>
void BinaryTree<T>::GetTreeByAft(shared_ptr<t_node_> root , stringstream &ss) const
{
	if (!root.get() || !root->data) return;
	GetTreeByAft(root->lChild , ss);
	GetTreeByAft(root->rChild , ss);
	ss << root->data;
}
//�ó����ڵ����
template<typename T>
int BinaryTree<T>::GetNumOfNode(shared_ptr<t_node_> root) const
{
	if (!root.get() || !root->data) return 0;
	else
	{
		int lnumber = GetNumOfNode(root->lChild);
		int rnumber = GetNumOfNode(root->rChild);
		return lnumber + rnumber + 1;
	}
}
//�ó���Ҷ�ӽڵ����
template<typename T>
int BinaryTree<T>::GetNumOfLeaf(shared_ptr<t_node_> root) const
{
	if (!root.get() || !root->data)  return 0;
	else
	{
		if (!root->lChild.get() && !root->rChild.get() || !root->lChild->data && !root->lChild->data)
		{
			return 1;
		}
		else
		{
			int lnumber = GetNumOfLeaf(root->lChild);
			int rnumber = GetNumOfLeaf(root->rChild);
			return lnumber + rnumber;
		}

	}
}

template<typename T>
inline int BinaryTree<T>::GetDepth(shared_ptr<t_node_> root , int number) const
{
	if (!root.get() || !root->data) return number;
	int lnumber = GetDepth(root->lChild , number + 1);
	int rnumber = GetDepth(root->rChild , number + 1);
	return lnumber > rnumber ? lnumber : rnumber;
}

template<typename T>
inline void BinaryTree<T>::CreateTreeByPreOrder(shared_ptr<t_node_> root , char nullCh)
{
	char elem;
	std::cin >> elem;
	if (elem == nullCh) root._Reset();
	else
	{
		root->data = elem;
		root->lChild = make_shared<t_node_>();
		CreateTreeByPreOrder(root->lChild , nullCh);
		root->rChild = make_shared<t_node_>();
		CreateTreeByPreOrder(root->rChild , nullCh);
	}
}


//ʹ���ַ�����ʼ����(��α�����ʼ��)  *ע�⣺�˴����ַ�����ǰ���ַ�����ͬ
template<typename T>
BinaryTree<T>::BinaryTree(string buf)
{
	root_node_ = std::make_shared<t_node_>();
	root_node_->lChild = nullptr;
	root_node_->rChild = nullptr;
	CreatNode(root_node_ , buf , 1);
}


