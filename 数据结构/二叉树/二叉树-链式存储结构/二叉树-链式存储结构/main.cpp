#include <iostream>
#include "BiTreeElemType.h"
#include "function.h"
using namespace std;

int main()
{
	BiTree* tree = nullptr;

	cout << "请输入根节点:";
	cinTree(tree);

	cout << "树的存在情况:";
	isEmpty(tree);

	cout << "根节点:" << getRoot(tree) << endl;
	cout << "深度:" << getDepth(tree) << endl;
	cout << "存储个数:" << getNumber(tree) << endl;

	cout << "\n遍历二叉树：";
	if (!isEmpty(tree))
	{
		cout << "前序遍历:";
		preorderTrav(tree);
		cout << "\n前序遍历-非递归:";
		preorderTrav_stack(tree);
		cout << endl;

		cout << "\n中序遍历:";
		inorderTrav(tree);
		cout << "\n中序遍历-非递归:";
		inorderTrav_stack(tree);
		cout << endl;

		cout << "\n后序遍历:";
		postorderTrav(tree);
		cout << "\n后序遍历-非递归:";
		postorderTrav_stack(tree);
		cout << endl;

		cout << "\n层序遍历：" << endl;
		levelorderTrav(tree);
	}

	cout << "\n销毁树" << endl;
	deleTree(tree);
	cout << "树的存在情况:";
	isEmpty(tree);

	system("pause");
	return 0;
}