#include <iostream>
#include "ElementType.h"
#include "ListFunction.h"

using namespace std;
int main()
{
	ElementType Array[] = {
		{1, "提莫"},
		{ 2, "蛮王" },
		{ 3, "盲僧" },
		{ 4, "德玛西亚" },
		{ 5, "德莱文" }
	};

	Linklist *head = nullptr;

	showlist(head);
	InitLinkList(head, Array, sizeof(Array) / sizeof(Array[0]));
	showlist(head);

	cout << "\n单链表的反向输出(递归法)：" << endl;
	show_recursion(head->next);
	return 0;
}