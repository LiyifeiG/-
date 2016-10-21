#include "BinaryTree.h"
#include <iostream>
#include <sstream>
#include <memory>

///创建节点
bool BinaryTree::CreatNode(shared_ptr<t_node_> node , string buffer_data , int buf_index)
{
	node->data = buffer_data[buf_index - 1];
	node->lChild = nullptr;
	node->rChild = nullptr;
	if ((2 * buf_index) <= buffer_data.length())
	{
		node->lChild = std::make_shared<t_node_>();;
		CreatNode(node->lChild , buffer_data , 2 * buf_index);
	}

	if ((2 * buf_index + 1) <= buffer_data.length())
	{
		node->rChild = std::make_shared<t_node_>();;
		CreatNode(node->rChild , buffer_data , 2 * buf_index + 1);
	}
	return true;
}

BinaryTree::BinaryTree()
{
	root_node_ = std::make_shared<t_node_>();
	root_node_->data = ' ';
}

BinaryTree::~BinaryTree()
{
	root_node_.reset();
}

///根据枚举参数获得树字符串
string BinaryTree::GetTreeString(Order order) const
{
	// ReSharper disable once CppNonReclaimedResourceAcquisition
	shared_ptr<stringstream> ss(new stringstream);
	switch (order)
	{
		case Preorder:GetTreeByPre(root_node_ , *ss);break;
		case Inorder: GetTreeByMid(root_node_ , *ss);break;
		case Aftorder:GetTreeByAft(root_node_ , *ss);break;
		default: break;
	}
	return ss->str();
}

// ReSharper disable once CppMemberFunctionMayBeStatic
///打印节点数据
void BinaryTree::PrintNode(shared_ptr<t_node_> node)
{
	if (node.get() == nullptr) return;
	std::cout << node->data;
}

///得到前序节点字符串
void BinaryTree::GetTreeByPre(shared_ptr<t_node_> root , stringstream &ss) const
{
	if (!root.get() || !root->data) return;
	ss << root->data;
	GetTreeByPre(root->lChild ,ss);
	GetTreeByPre(root->rChild ,ss);
}

///得到中序节点字符串
void BinaryTree::GetTreeByMid(shared_ptr<t_node_> root , stringstream &ss) const
{
	if (!root.get() || !root->data) return;
	GetTreeByMid(root->lChild ,ss);
	ss << root->data;
	GetTreeByMid(root->rChild ,ss);
}

///得到后序节点字符串
void BinaryTree::GetTreeByAft(shared_ptr<t_node_> root , stringstream &ss) const
{
	if (!root.get() || !root->data) return;
	GetTreeByAft(root->lChild , ss);
	GetTreeByAft(root->rChild , ss);
	ss << root->data;
}

///使用字符串初始化树  *注意：此处的字符串与前序字符串不同
BinaryTree::BinaryTree(string buf)
{
	root_node_ = std::make_shared<t_node_>();
	root_node_->lChild = nullptr;
	root_node_->rChild = nullptr;
	CreatNode(root_node_ , buf , 1);
}

