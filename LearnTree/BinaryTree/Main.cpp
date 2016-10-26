#define CRTDBG_MAP_ALLOC
#include "BinaryTree.h"
#include <iostream>
//²âÊÔ´úÂë
int main(int argc, char* argv[])
{
	// ReSharper disable once CppNonReclaimedResourceAcquisition
	auto bt = std::make_shared<BinaryTree<char>>('*');
	std::cout << bt->GetTreeString(bt->Preorder) << std::endl;
	std::cout << bt->GetTreeString(bt->Inorder) << std::endl;
	std::cout << bt->GetTreeString(bt->Aftorder) << std::endl;
	std::cout << bt->NumberOfNode()<<std::endl;
	std::cout << bt->NumberOfLeaf()<<std::endl;
	std::cout << bt->Depth()<<std::endl;
	bt->PrintTree();
	bt.reset();
	_CrtDumpMemoryLeaks();   //¼ì²âÄÚ´æĞ¹Â©
	system("Pause");
	return 0;
}
