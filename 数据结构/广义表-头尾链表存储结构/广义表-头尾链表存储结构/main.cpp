#include <iostream>
#include "ElemType.h"
using namespace std;

/*
广义表的实现：C = {a,{b,c,d}}
示例图：http://data.biancheng.net/uploads/allimg/170720/2-1FH0161302422.png
*/

int main()
{
	ElemAtom a, b, c, d;
	a = { 1,"华子" };
	b = { 2,"辣条" };
	c = { 3,"槟榔" };
	d = { 4,"狗屎" };

	GList *C = new GList;

	//第一个结点及其原子结点
	C->Tag = LIST;
	C->list.head = new GList{ATOM, a};

	//第二个结点
	C->list.tail = new GList{ LIST };
	C->list.tail->list.tail = nullptr;

	//第二个结点子表定义
	C->list.tail->list.head = new GList{ LIST };

	//第二个结点子表第一个结点
	C->list.tail->list.head->Tag = LIST;
	C->list.tail->list.head->list.head = new GList{ ATOM, b };

	//第二个结点子表第二结点
	C->list.tail->list.head->list.tail = new GList{ LIST };
	C->list.tail->list.head->list.tail->list.head = new GList{ ATOM, c };

	//第二结点子表第三结点
	C->list.tail->list.head->list.tail->list.tail = new GList{ LIST };
	C->list.tail->list.head->list.tail->list.tail->list.head = new GList{ ATOM, d };
	C->list.tail->list.head->list.tail->list.tail->list.tail = nullptr;

	cout << C->list.head->atom.id << "   " << C->list.head->atom.name << endl;


	return 0;
}