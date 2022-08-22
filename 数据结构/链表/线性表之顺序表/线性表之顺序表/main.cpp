#include <iostream>
#include "ElementType.h"
#include "listFunction.h"
using namespace std;
int main()
{
	ElementType InitType[]{
		{ 2012010, "���첩ʿ" },
		{ 2012016,"�̾��˺ƿ�" },
		{ 2013543,"�ɰ�С����" },
	};

	SequenceList *List = new SequenceList;
	InitList(List, InitType, sizeof(InitType) / sizeof(InitType[0]));
	cout << "��ʼ��������:" << endl;
	ShowList(List);

	ElementType element{ 2078010, "������" };
	cout << "\n��������Ԫ��:" << element.id << "  " << element.name << endl << endl;

	cout << "˳���ɲ��뷶ΧΪ��[0, " << getLength(List) - 1<< "]" << endl;
	cout << "��������Ԫ����λ��1��" << endl;
	InsertList(List, element, 1);
	ShowList(List);

	cout << "\n�����±�λ��Ϊ1��Ԫ��Ϊ��" << GetElement(List, 1).id << "  " << GetElement(List, 1).name << endl;

	cout.setf(ios_base::boolalpha);//��bool������false��true���
	cout << "\n˳������Ƿ��������:" << IsList(List) << endl;

	cout << "\n���˳����е����ݺ�" << endl;
	for (int i = List->length; i > 0; i--)//ɾ��˳����е�����Ԫ��
		DeleteList(List, i);

	cout << "˳������Ƿ��������:" << IsList(List) << endl << endl;

	return 0;
}