#include <iostream>
#include "ElementType.h"
#include "ListFunction.h"

using namespace std;
int main()
{
	ElementType Array[] = {
		{1, "��Ī"},
		{ 2, "����" },
		{ 3, "äɮ" },
		{ 4, "��������" },
		{ 5, "������" }
	};

	Linklist *head = nullptr;

	showlist(head);
	InitLinkList(head, Array, sizeof(Array) / sizeof(Array[0]));
	showlist(head);

	cout << "\n������ķ������(�ݹ鷨)��" << endl;
	show_recursion(head->next);
	return 0;
}