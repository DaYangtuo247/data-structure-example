#include <iostream>
#include "ElementType.h"
#include "QueFunction.h"

int main()
{
	using namespace std;

	ElementType Array[] = {
		{ 1, "��Ī" },
		{ 2, "����" },
		{ 3, "����" },
		{ 4, "������" },
		{ 5, "���" },
		{ 6, "ŵ��" },
		{ 7, "��ͷ" },
		{ 8, "Ϲ��" },
		{ 9, "ŵ��" }
	};
	SeqQueue *queue = nullptr;
	init(queue);

	//ȫ�����
	int len = sizeof(Array) / sizeof(Array[0]);
	for (int i = 0; i < len; i++)
		push(queue, Array[i]);

	cout << "������У�" << endl;
	show(queue);

	cout << "\n�����������������:" << endl;
	pop(queue); pop(queue); pop(queue);
	push(queue, { 10, "ŵ��" }); push(queue, { 11, "ŵ��" }); push(queue, { 12, "ŵ��" });
	show(queue);

	cout << "\n�������ַ�ϵĴ洢λ�ã�" << endl;
	for (int i = 0; i < MAX_SIZE; i++)
		printf("id:%d\tname:%s\n", queue->data[i].id, queue->data[i].name);

	cout << "\n���ض�ͷԪ�أ�id:" << front(queue).id << "\tname:" << front(queue).name << endl;
	cout << "���ض�βԪ�أ�id:" << rear(queue).id << "\tname:" << rear(queue).name << endl;

	clear(queue);
	show(queue);

	return 0;
}