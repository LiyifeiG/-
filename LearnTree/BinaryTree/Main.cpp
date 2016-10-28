#define CRTDBG_MAP_ALLOC
#include "BinaryTree.hpp"
#include <iostream>
//²âÊÔ´úÂë
int main(int argc, char* argv[])
{
	// ReSharper disable once CppNonReclaimedResourceAcquisition
	auto bt = std::make_shared<BinaryTree<char>>("abcdefhjkflsassadfeec");
	auto bt2 = std::make_shared<BinaryTree<char>>("abcdefhjkflsassadfeec");
	std::cout << bt->Like(bt2)<<std::endl;
	std::cout << bt->GetAllTreeNode(bt->Preorder) << std::endl;
	std::cout << bt->GetAllTreeNode(bt->Inorder) << std::endl;
	std::cout << bt->GetAllTreeNode(bt->Aftorder) << std::endl;
	std::cout << bt->NumberOfNode()<<std::endl;
	std::cout << bt->NumberOfLeaf()<<std::endl;
	std::cout << bt->Depth()<<std::endl;
	bt->PrintTree();
	bt->Clear();
	*bt = BinaryTree<char>("Hello");
	std::cout << bt->NumberOfNode() << std::endl;
	std::cout << bt->NumberOfLeaf() << std::endl;
	std::cout << bt->Depth() << std::endl;
	bt->PrintTree();
	bt.reset();
	bt2.reset();
	_CrtDumpMemoryLeaks();   //¼ì²âÄÚ´æĞ¹Â©
	system("Pause");
	return 0;
}
