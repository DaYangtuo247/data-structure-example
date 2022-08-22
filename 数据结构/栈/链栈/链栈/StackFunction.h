#pragma once
#include "ElementType.h"
using namespace std;

//----------------------��������---------------------
//��ʼ��ջ
void init(LinkStack* &stack);
//ѹջ
bool push(LinkStack *stack, ElementType elem);
//��ջ
bool pop(LinkStack *stack);
//����ջ��Ԫ��
ElementType top(LinkStack *stack);
//�ж�ջ�Ƿ�Ϊ��
bool empty(LinkStack *stack);
//��ӡ����Ļ
void show(LinkStack *stack);
//����ջ
void clear(LinkStack * &stack);
//--------------------------------------------------

//ע�⣺�ڳ�ʼ�������ٺ����У��βα���Ϊ�������ͣ���ʼ������������ȷ����new����ռ�ʱ�Ƕ�ʵ��ָ������ռ�
//���٣���������ȷ�������deleteָ���ʵ�ε�ָ��Ϊnullptr

//��ʼ��ջ
void init(LinkStack* &stack)
{
	stack = new LinkStack;
	stack->length = 0;
	stack->top = nullptr;
}

//ѹջ
bool push(LinkStack *stack, ElementType elem)
{
	if (stack == nullptr)
	{
		cout << "��ջδ����" << endl;
		return false;
	}
	StackNode *newnode = new StackNode;
	newnode->data = elem;
	newnode->next = stack->top;
	stack->top = newnode;
	stack->length++;
	return true;
}

//��ջ
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

//����ջ��Ԫ��
ElementType top(LinkStack *stack)
{
	if (empty(stack))
	{
		cout << "��ջΪ��" << endl;
		return{ -1, "nullptr" };
	}
	return stack->top->data;
}

//�ж�ջ�Ƿ�Ϊ��
bool empty(LinkStack *stack)
{
	if (stack == nullptr)
	{
		cout << "��ջδ����" << endl;
		return true;
	}
	else if (stack->length == 0)
	{
		cout << "��ջΪ��" << endl;
		return true;
	}
	return false;
}

//��ʾ����Ļ
void show(LinkStack *stack)
{
	if (empty(stack))
		return;
	cout << "ջ�е�Ԫ��Ϊ:" << endl;
	StackNode *currnode = stack->top;
	for (int i = 0; i < stack->length; i++, currnode = currnode->next)
		cout << "id:" << currnode->data.id << "\tname:" << currnode->data.name << endl;
}

//����ջ
void clear(LinkStack * &stack)
{
	for (int i = 0; i < stack->length; i++)
		pop(stack);

	delete stack;
	stack = nullptr;
}