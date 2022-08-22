#include <iostream>
#include "ElementType.h"
#include "listFunction.h"

using namespace std;

int main()
{
	ElementType Array[] = {
		{ 1, "提莫" },
		{ 2, "蛮王" },
		{ 3, "盲僧" },
		{ 4, "德玛西亚" },
		{ 5, "德莱文" }
	};

	List *list = new List{ nullptr, 0 };

	int len = sizeof(Array) / sizeof(Array[0]);
	for (int i = 0; i < len; i++)
		if (insert(list, Array[i], i + 1) == 0)
			cout << "插入失败！" << endl;
	
	insert(list, { 8, "TEST" }, 2);

	cout << "输出链表内容(使用后缀指针):" << endl;
	show(list);

	cout << "\n输出链表内容(next指针递归):" << endl;
	show_recursion(list->next);

	cout << "\n反向输出链表内容:(使用前缀指针)" << endl;
	show_reverse(list);

	cout << "\n反向输出链表内容:(next指针递归)" << endl;
	show_reverse_recursion(list->next);

	return 0;
}

