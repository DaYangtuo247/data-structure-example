#include <iostream>
#include "ElementType.h"
#include "QueFunction.h"

int main()
{
	using namespace std;

	ElementType Array[] = {
		{ 1,"提莫"},
		{ 2,"德玛" },
		{ 3,"皇子" },
		{ 4,"德莱文" },
		{ 5,"锐雯" }	
	};

	LinkQueue *queue = nullptr;
	init(queue);

	//全部入队
	int len = sizeof(Array) / sizeof(Array[0]);
	for (int i = 0; i < len; i++)
		push(queue, Array[i]);

	cout << "输出队列：" << endl;
	show(queue);

	cout << "\n出队一个后输出队列：" << endl;
	pop(queue);
	show(queue);

	cout << "\n返回队头元素：id:" << front(queue).id << "\tname:" << front(queue).name << endl;
	cout << "返回队尾元素：id:" << rear(queue).id << "\tname:" << rear(queue).name << endl;

	clear(queue);
	show(queue);

	return 0;
}