#include <iostream>
#include "ElementType.h"
#include "listFunction.h"
using namespace std;
int main()
{
	ElementType InitType[]{
		{ 2012010, "奇异博士" },
		{ 2012016,"绿巨人浩克" },
		{ 2013543,"可爱小羊驼" },
	};

	SequenceList *List = new SequenceList;
	InitList(List, InitType, sizeof(InitType) / sizeof(InitType[0]));
	cout << "初始化的数据:" << endl;
	ShowList(List);

	ElementType element{ 2078010, "钢铁侠" };
	cout << "\n插入数据元素:" << element.id << "  " << element.name << endl << endl;

	cout << "顺序表可插入范围为：[0, " << getLength(List) - 1<< "]" << endl;
	cout << "插入数据元素在位置1后：" << endl;
	InsertList(List, element, 1);
	ShowList(List);

	cout << "\n返回下标位置为1的元素为：" << GetElement(List, 1).id << "  " << GetElement(List, 1).name << endl;

	cout.setf(ios_base::boolalpha);//将bool类型以false，true输出
	cout << "\n顺序表中是否存在数据:" << IsList(List) << endl;

	cout << "\n清空顺序表中的数据后" << endl;
	for (int i = List->length; i > 0; i--)//删除顺序表中的所有元素
		DeleteList(List, i);

	cout << "顺序表中是否存在数据:" << IsList(List) << endl << endl;

	return 0;
}