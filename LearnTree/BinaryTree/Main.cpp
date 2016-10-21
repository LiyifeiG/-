#define CRTDBG_MAP_ALLOC
#include "BinaryTree.h"
#include <iostream>

int main(int argc, char* argv[])
{
	// ReSharper disable once CppNonReclaimedResourceAcquisition
	auto bt = std::make_shared<BinaryTree>("ABCDEFGHJTN");
	std::cout << bt->GetTreeString(bt->Preorder) << std::endl;
	std::cout << bt->GetTreeString(bt->Aftorder) << std::endl;
	std::cout << bt->GetTreeString(bt->Inorder) << std::endl;
	bt.reset();
	_CrtDumpMemoryLeaks();
	system("Pause");
	return 0;
}
