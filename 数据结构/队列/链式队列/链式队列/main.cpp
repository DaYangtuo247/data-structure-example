#include <iostream>
#include "ElementType.h"
#include "QueFunction.h"

int main()
{
	using namespace std;

	ElementType Array[] = {
		{ 1,"��Ī"},
		{ 2,"����" },
		{ 3,"����" },
		{ 4,"������" },
		{ 5,"����" }	
	};

	LinkQueue *queue = nullptr;
	init(queue);

	//ȫ�����
	int len = sizeof(Array) / sizeof(Array[0]);
	for (int i = 0; i < len; i++)
		push(queue, Array[i]);

	cout << "������У�" << endl;
	show(queue);

	cout << "\n����һ����������У�" << endl;
	pop(queue);
	show(queue);

	cout << "\n���ض�ͷԪ�أ�id:" << front(queue).id << "\tname:" << front(queue).name << endl;
	cout << "���ض�βԪ�أ�id:" << rear(queue).id << "\tname:" << rear(queue).name << endl;

	clear(queue);
	show(queue);

	return 0;
}