#include <iostream>
#include "ElementType.h"
#include "stackFunction.h"

using namespace std;

int main()
{
	ElementType Array[] = {
		{1, "��Ī"},
		{ 2, "����" },
		{ 3, "����" },
		{ 4, "��ʥ" },
		{5, "��Ī"},
		{ 6, "����" },
		{ 7, "����" },
		{ 8, "��ʥ" },
		{9, "��Ī"},
		{ 10, "����" }
	};

	
	SeqStack *stack = nullptr;
	init(stack);

	int len = sizeof(Array) / sizeof(Array[0]);
	//��ջ
	for (int i = 0; i < len; i++)
		if (!push(stack, Array[i]))
			cout << "��ջʧ��!" << endl;

	cout << "���ջ��" << endl;
	show(stack);

	if (!pop(stack))
		cout << "����ʧ��!" << endl;

	cout << "\n��ջһ�������ջ��" << endl;
	show(stack);

	cout << "\n����ջ��Ԫ�أ�\nid:" << top(stack).id << "\tname:" << top(stack).name << endl;

	//����ջ
	cout << "\n����ջ���ջ��" << endl;
	clear(stack);
	show(stack);



	return 0;
}