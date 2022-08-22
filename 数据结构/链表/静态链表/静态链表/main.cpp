#include <iostream>
#include "ElementType.h"
#include"ListFunction.h"

int main()
{
	using namespace std;
	
	ElementType Array[] = {
		{ 1, "提莫" },
		{ 2, "蛮王" },
		{ 3, "盲僧" },
		{ 4, "德玛西亚" },
		{ 5, "德莱文" }
	};

	StaticLinkList *list = new StaticLinkList[MAX_SIZE];

	//方便后续直观观察
	for (int i = 0; i < MAX_SIZE; i++)
		list[i].data.id = 0, list[i].data.name = "空空空";

	init(list);

	for (int i = 0; i < sizeof(Array) / sizeof(Array[0]); i++)
		insert(list, Array[i], i + 1);

	showStore(list);
	show(list);
	
	return 0;
}