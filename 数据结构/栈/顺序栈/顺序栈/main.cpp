#include <iostream>
#include "ElementType.h"
#include "stackFunction.h"

using namespace std;

int main()
{
	ElementType Array[] = {
		{1, "提莫"},
		{ 2, "德玛" },
		{ 3, "皇子" },
		{ 4, "剑圣" },
		{5, "提莫"},
		{ 6, "德玛" },
		{ 7, "皇子" },
		{ 8, "剑圣" },
		{9, "提莫"},
		{ 10, "德玛" }
	};

	
	SeqStack *stack = nullptr;
	init(stack);

	int len = sizeof(Array) / sizeof(Array[0]);
	//入栈
	for (int i = 0; i < len; i++)
		if (!push(stack, Array[i]))
			cout << "入栈失败!" << endl;

	cout << "输出栈：" << endl;
	show(stack);

	if (!pop(stack))
		cout << "弹出失败!" << endl;

	cout << "\n出栈一个后输出栈：" << endl;
	show(stack);

	cout << "\n返回栈顶元素：\nid:" << top(stack).id << "\tname:" << top(stack).name << endl;

	//销毁栈
	cout << "\n销毁栈输出栈：" << endl;
	clear(stack);
	show(stack);



	return 0;
}