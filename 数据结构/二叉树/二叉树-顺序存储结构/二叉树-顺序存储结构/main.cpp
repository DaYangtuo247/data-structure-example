#include <iostream>
#include "function.h"

using namespace std;

int main()
{
	BiTree *tree = nullptr;
	createTree(tree);
	cout << "���������������洢10����������\n��������ڵ�:";
	cinTree(tree);

	cout << "\n����洢�ṹ��" << endl;
	linkShowTree(tree);
	cout << "\n���������ӻ�:" << endl;

	cout << "\n��ȣ�" << getDepth(tree) << endl;
	cout << "�洢������" << getNumber(tree) << endl;
	cout << "���ڵ㣺" << getRoot(tree) << endl;
	cout << "ǰ�����:";
	preorderTrav(tree);

	cout << "\n�������:";
	inorderTrav(tree);

	cout << "\n�������:";
	postorderTrav(tree);

	cout << endl;
	return 0;
}