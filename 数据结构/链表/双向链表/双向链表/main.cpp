#include <iostream>
#include "ElementType.h"
#include "listFunction.h"

using namespace std;

int main()
{
	ElementType Array[] = {
		{ 1, "��Ī" },
		{ 2, "����" },
		{ 3, "äɮ" },
		{ 4, "��������" },
		{ 5, "������" }
	};

	List *list = new List{ nullptr, 0 };

	int len = sizeof(Array) / sizeof(Array[0]);
	for (int i = 0; i < len; i++)
		if (insert(list, Array[i], i + 1) == 0)
			cout << "����ʧ�ܣ�" << endl;
	
	insert(list, { 8, "TEST" }, 2);

	cout << "�����������(ʹ�ú�׺ָ��):" << endl;
	show(list);

	cout << "\n�����������(nextָ��ݹ�):" << endl;
	show_recursion(list->next);

	cout << "\n���������������:(ʹ��ǰ׺ָ��)" << endl;
	show_reverse(list);

	cout << "\n���������������:(nextָ��ݹ�)" << endl;
	show_reverse_recursion(list->next);

	return 0;
}

