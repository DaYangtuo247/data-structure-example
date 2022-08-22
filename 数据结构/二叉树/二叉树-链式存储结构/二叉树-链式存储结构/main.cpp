#include <iostream>
#include "BiTreeElemType.h"
#include "function.h"
using namespace std;

int main()
{
	BiTree* tree = nullptr;

	cout << "��������ڵ�:";
	cinTree(tree);

	cout << "���Ĵ������:";
	isEmpty(tree);

	cout << "���ڵ�:" << getRoot(tree) << endl;
	cout << "���:" << getDepth(tree) << endl;
	cout << "�洢����:" << getNumber(tree) << endl;

	cout << "\n������������";
	if (!isEmpty(tree))
	{
		cout << "ǰ�����:";
		preorderTrav(tree);
		cout << "\nǰ�����-�ǵݹ�:";
		preorderTrav_stack(tree);
		cout << endl;

		cout << "\n�������:";
		inorderTrav(tree);
		cout << "\n�������-�ǵݹ�:";
		inorderTrav_stack(tree);
		cout << endl;

		cout << "\n�������:";
		postorderTrav(tree);
		cout << "\n�������-�ǵݹ�:";
		postorderTrav_stack(tree);
		cout << endl;

		cout << "\n���������" << endl;
		levelorderTrav(tree);
	}

	cout << "\n������" << endl;
	deleTree(tree);
	cout << "���Ĵ������:";
	isEmpty(tree);

	system("pause");
	return 0;
}