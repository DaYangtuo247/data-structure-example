#include <iostream>
#include "ElementType.h"
#include "StackFunction.h"


int main()
{
	using namespace std;

	ElementType Array[] = {
		{ 1,"迅捷斥候" },
		{ 2,"德玛西亚" },
		{ 3,"盲僧" },
		{ 4,"提莫" },
		{ 5,"卡特琳娜" },
		{ 6,"德莱文" }
	};

	int len = sizeof(Array) / sizeof(Array[0]);
	LinkStack* stack = nullptr;
	
	//初始化
	init(stack);

	//压栈
	for (int i = 0; i < len; i++)
		push(stack, Array[i]);
	
	show(stack);

	//出栈一个元素
	cout << "\n出栈一个元素:" << endl;
	pop(stack);
	
	show(stack);

	//出栈所有元素
	cout << "\n出栈所有元素:" << endl;
	while (stack->length)
		pop(stack);
	  
	show(stack);

	cout << "\n销毁栈后输出栈:" << endl;
	clear(stack);

	show(stack);
	return 0;
}