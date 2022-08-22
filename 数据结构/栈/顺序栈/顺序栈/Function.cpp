#pragma once
#include <iostream>
#include "ElementType.h"
#include "stackFunction.h"
using namespace std;

//��ʼ��
void init(SeqStack * &stack)
{
	stack = new SeqStack;
	stack->bottom = new ElementType[MAX_SIZE]; // ElementType bottom[MAX_SIZE];
	stack->top = stack->bottom;
}

//ѹջ
bool push(SeqStack *stack, ElementType elem)
{
	if (stack->top - stack->bottom == MAX_SIZE)
	{
		cout << "ջ��" << endl;
		return false;
	}
	*stack->top = elem;
	stack->top++;
	return true;
}

//����
bool pop(SeqStack *stack)
{
	if (empty(stack))
		return false;

	stack->top--;
	free(stack->top);
	return true;
}

//����ջ��Ԫ��
ElementType top(SeqStack *stack)
{
	if (empty(stack))
		return{-1, nullptr};

	return *(stack->top - 1);
}

//�п�
bool empty(SeqStack *stack)
{
	if (!stack)
	{
		cout << "ջδ����!" << endl;
		return true;
	}
	else if (stack->top == stack->bottom)
	{
		cout << "ջΪ��" << endl;
		return 1;
	}
	return 0;
}

//����ջ���
void free(ElementType *elem)
{
	elem->id = -1;
	elem->name = nullptr;
}

//����ջ
void clear(SeqStack* &stack)
{
	delete [] stack->bottom;
	delete stack;
	stack = nullptr;
}

//��ʾ����Ļ
void show(SeqStack *stack)
{
	if (empty(stack))
		return;

	int len = stack->top - stack->bottom;
	for (int i = 0; i < len; i++)
		cout << "id:" << stack->bottom[i].id << "\tname:" << stack->bottom[i].name << endl;
}
