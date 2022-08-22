#pragma once
#include <iostream>
#include "ElementType.h"
#include "stackFunction.h"
using namespace std;

//初始化
void init(SeqStack * &stack)
{
	stack = new SeqStack;
	stack->bottom = new ElementType[MAX_SIZE]; // ElementType bottom[MAX_SIZE];
	stack->top = stack->bottom;
}

//压栈
bool push(SeqStack *stack, ElementType elem)
{
	if (stack->top - stack->bottom == MAX_SIZE)
	{
		cout << "栈满" << endl;
		return false;
	}
	*stack->top = elem;
	stack->top++;
	return true;
}

//弹出
bool pop(SeqStack *stack)
{
	if (empty(stack))
		return false;

	stack->top--;
	free(stack->top);
	return true;
}

//返回栈顶元素
ElementType top(SeqStack *stack)
{
	if (empty(stack))
		return{-1, nullptr};

	return *(stack->top - 1);
}

//判空
bool empty(SeqStack *stack)
{
	if (!stack)
	{
		cout << "栈未创建!" << endl;
		return true;
	}
	else if (stack->top == stack->bottom)
	{
		cout << "栈为空" << endl;
		return 1;
	}
	return 0;
}

//清理栈结点
void free(ElementType *elem)
{
	elem->id = -1;
	elem->name = nullptr;
}

//销毁栈
void clear(SeqStack* &stack)
{
	delete [] stack->bottom;
	delete stack;
	stack = nullptr;
}

//显示到屏幕
void show(SeqStack *stack)
{
	if (empty(stack))
		return;

	int len = stack->top - stack->bottom;
	for (int i = 0; i < len; i++)
		cout << "id:" << stack->bottom[i].id << "\tname:" << stack->bottom[i].name << endl;
}
