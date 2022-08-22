#include <iostream>
#include "ElementType.h"
#include "QueFunction.h"

int main()
{
	using namespace std;

	ElementType Array[] = {
		{ 1, "提莫" },
		{ 2, "德玛" },
		{ 3, "皇子" },
		{ 4, "德莱文" },
		{ 5, "光辉" },
		{ 6, "诺手" },
		{ 7, "狗头" },
		{ 8, "瞎子" },
		{ 9, "诺克" }
	};
	SeqQueue *queue = nullptr;
	init(queue);

	//全部入队
	int len = sizeof(Array) / sizeof(Array[0]);
	for (int i = 0; i < len; i++)
		push(queue, Array[i]);

	cout << "输出队列：" << endl;
	show(queue);

	cout << "\n出队三个并入队三个:" << endl;
	pop(queue); pop(queue); pop(queue);
	push(queue, { 10, "诺克" }); push(queue, { 11, "诺克" }); push(queue, { 12, "诺克" });
	show(queue);

	cout << "\n在物理地址上的存储位置：" << endl;
	for (int i = 0; i < MAX_SIZE; i++)
		printf("id:%d\tname:%s\n", queue->data[i].id, queue->data[i].name);

	cout << "\n返回队头元素：id:" << front(queue).id << "\tname:" << front(queue).name << endl;
	cout << "返回队尾元素：id:" << rear(queue).id << "\tname:" << rear(queue).name << endl;

	clear(queue);
	show(queue);

	return 0;
}