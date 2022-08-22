#include <iostream>
#include "ElemType.h"
using namespace std;

/*
������ʵ�֣�C = {a,{b,c,d}}
ʾ��ͼ��http://data.biancheng.net/uploads/allimg/170720/2-1FH0161302422.png
*/

int main()
{
	ElemAtom a, b, c, d;
	a = { 1,"����" };
	b = { 2,"����" };
	c = { 3,"����" };
	d = { 4,"��ʺ" };

	GList *C = new GList;

	//��һ����㼰��ԭ�ӽ��
	C->Tag = LIST;
	C->list.head = new GList{ATOM, a};

	//�ڶ������
	C->list.tail = new GList{ LIST };
	C->list.tail->list.tail = nullptr;

	//�ڶ�������ӱ���
	C->list.tail->list.head = new GList{ LIST };

	//�ڶ�������ӱ��һ�����
	C->list.tail->list.head->Tag = LIST;
	C->list.tail->list.head->list.head = new GList{ ATOM, b };

	//�ڶ�������ӱ�ڶ����
	C->list.tail->list.head->list.tail = new GList{ LIST };
	C->list.tail->list.head->list.tail->list.head = new GList{ ATOM, c };

	//�ڶ�����ӱ�������
	C->list.tail->list.head->list.tail->list.tail = new GList{ LIST };
	C->list.tail->list.head->list.tail->list.tail->list.head = new GList{ ATOM, d };
	C->list.tail->list.head->list.tail->list.tail->list.tail = nullptr;

	cout << C->list.head->atom.id << "   " << C->list.head->atom.name << endl;


	return 0;
}