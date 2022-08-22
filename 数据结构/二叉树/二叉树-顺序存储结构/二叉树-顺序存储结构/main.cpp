#include <iostream>
#include "function.h"

using namespace std;

int main()
{
	BiTree *tree = nullptr;
	createTree(tree);
	cout << "本二叉树最大允许存储10层满二叉树\n请输入根节点:";
	cinTree(tree);

	cout << "\n物理存储结构：" << endl;
	linkShowTree(tree);
	cout << "\n二叉树可视化:" << endl;

	cout << "\n深度：" << getDepth(tree) << endl;
	cout << "存储个数：" << getNumber(tree) << endl;
	cout << "根节点：" << getRoot(tree) << endl;
	cout << "前序遍历:";
	preorderTrav(tree);

	cout << "\n中序遍历:";
	inorderTrav(tree);

	cout << "\n后序遍历:";
	postorderTrav(tree);

	cout << endl;
	return 0;
}