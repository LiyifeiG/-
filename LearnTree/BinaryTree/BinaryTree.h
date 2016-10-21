#pragma once
#include <string>
#include <memory>
using namespace std;
class BinaryTree
{
private:
	typedef struct node
	{
		char data;
		shared_ptr<struct node> lChild;
		shared_ptr<struct node> rChild;
	}t_node_;
private:
	shared_ptr<t_node_> root_node_;
	static bool CreatNode(shared_ptr<t_node_> node , string buffer_data , int buf_index);
	static void PrintNode(shared_ptr<t_node_> node);
	void GetTreeByPre(shared_ptr<t_node_> root , stringstream &ss) const;
	void GetTreeByMid(shared_ptr<t_node_> root , stringstream &ss) const;
	void GetTreeByAft(shared_ptr<t_node_> root , stringstream &ss) const;
public:
	// ReSharper disable once CppDeclarationSpecifierWithoutDeclarators
	const enum Order {                   
		Preorder = 1 ,
		Inorder = 2 ,
		Aftorder = 3
	};
	explicit BinaryTree();
	explicit BinaryTree(string buf);   
	~BinaryTree();
public:
	string GetTreeString(Order order) const;     
};



