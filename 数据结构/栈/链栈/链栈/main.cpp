#include <iostream>
#include "ElementType.h"
#include "StackFunction.h"


int main()
{
	using namespace std;

	ElementType Array[] = {
		{ 1,"Ѹ�ݳ��" },
		{ 2,"��������" },
		{ 3,"äɮ" },
		{ 4,"��Ī" },
		{ 5,"��������" },
		{ 6,"������" }
	};

	int len = sizeof(Array) / sizeof(Array[0]);
	LinkStack* stack = nullptr;
	
	//��ʼ��
	init(stack);

	//ѹջ
	for (int i = 0; i < len; i++)
		push(stack, Array[i]);
	
	show(stack);

	//��ջһ��Ԫ��
	cout << "\n��ջһ��Ԫ��:" << endl;
	pop(stack);
	
	show(stack);

	//��ջ����Ԫ��
	cout << "\n��ջ����Ԫ��:" << endl;
	while (stack->length)
		pop(stack);
	  
	show(stack);

	cout << "\n����ջ�����ջ:" << endl;
	clear(stack);

	show(stack);
	return 0;
}