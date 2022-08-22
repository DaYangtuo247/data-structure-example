#pragma once
#include "ElementType.h"
using namespace std;

//----------------------函数声明---------------------
//初始化栈
void init(LinkStack* &stack);
//压栈
bool push(LinkStack *stack, ElementType elem);
//出栈
bool pop(LinkStack *stack);
//返回栈顶元素
ElementType top(LinkStack *stack);
//判断栈是否为空
bool empty(LinkStack *stack);
//打印到屏幕
void show(LinkStack *stack);
//销毁栈
void clear(LinkStack * &stack);
//--------------------------------------------------

//注意：在初始化和销毁函数中，形参必须为引用类型；初始化：引用类型确定了new申请空间时是对实参指针申请空间
//销毁：引用类型确定了最后delete指针后，实参的指向为nullptr

//初始化栈
void init(LinkStack* &stack)
{
	stack = new LinkStack;
	stack->length = 0;
	stack->top = nullptr;
}

//压栈
bool push(LinkStack *stack, ElementType elem)
{
	if (stack == nullptr)
	{
		cout << "链栈未创建" << endl;
		return false;
	}
	StackNode *newnode = new StackNode;
	newnode->data = elem;
	newnode->next = stack->top;
	stack->top = newnode;
	stack->length++;
	return true;
}

//出栈
bool pop(LinkStack *stack)
{
	if (empty(stack))
		return false;

	StackNode *dele = stack->top;
	stack->top = stack->top->next;
	stack->length--;
	delete dele;
	return true;
}

//返回栈顶元素
ElementType top(LinkStack *stack)
{
	if (empty(stack))
	{
		cout << "链栈为空" << endl;
		return{ -1, "nullptr" };
	}
	return stack->top->data;
}

//判断栈是否为空
bool empty(LinkStack *stack)
{
	if (stack == nullptr)
	{
		cout << "链栈未创建" << endl;
		return true;
	}
	else if (stack->length == 0)
	{
		cout << "链栈为空" << endl;
		return true;
	}
	return false;
}

//显示到屏幕
void show(LinkStack *stack)
{
	if (empty(stack))
		return;
	cout << "栈中的元素为:" << endl;
	StackNode *currnode = stack->top;
	for (int i = 0; i < stack->length; i++, currnode = currnode->next)
		cout << "id:" << currnode->data.id << "\tname:" << currnode->data.name << endl;
}

//销毁栈
void clear(LinkStack * &stack)
{
	for (int i = 0; i < stack->length; i++)
		pop(stack);

	delete stack;
	stack = nullptr;
}