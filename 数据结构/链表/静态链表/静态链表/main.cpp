#include <iostream>
#include "ElementType.h"
#include"ListFunction.h"

int main()
{
	using namespace std;
	
	ElementType Array[] = {
		{ 1, "��Ī" },
		{ 2, "����" },
		{ 3, "äɮ" },
		{ 4, "��������" },
		{ 5, "������" }
	};

	StaticLinkList *list = new StaticLinkList[MAX_SIZE];

	//�������ֱ�۹۲�
	for (int i = 0; i < MAX_SIZE; i++)
		list[i].data.id = 0, list[i].data.name = "�տտ�";

	init(list);

	for (int i = 0; i < sizeof(Array) / sizeof(Array[0]); i++)
		insert(list, Array[i], i + 1);

	showStore(list);
	show(list);
	
	return 0;
}