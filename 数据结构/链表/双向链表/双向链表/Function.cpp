#include <iostream>
#include "ElementType.h"
using namespace std;

//插入算法
bool insert(List *list, ElementType elem, int pos)
{
	//先判断插入位置是否符合要求
	if (pos <= 0 || pos > list->length + 1)//允许在最后一个结点之后插入节点
		return 0;

	ListNode *newnode = new ListNode{ elem, nullptr, nullptr };

	if (pos == 1)//插入位置为首结点
	{
		newnode->next = list->next;
		list->next = newnode;
		list->length++;

		if (newnode->next != nullptr)//插入节点后，链表结点个数大于1
			newnode->next->prior = newnode;
		return 1;
	}

	//循环到插入位置的前一个结点
	ListNode *currnode = list->next;
	for (int i = 1; i<pos - 1; i++)
		currnode = currnode->next;

	//下一结点指向
	newnode->next = currnode->next;
	currnode->next = newnode;

	//上一结点指向
	if (newnode->next)
		newnode->next->prior = newnode;
	newnode->prior = currnode;

	list->length++;
	return 1;
}

//输出链表数据到屏幕
void show(List *list)
{
	ListNode * currnode = list->next;
	for (int i = 0; i < list->length; i++)
	{
		cout << currnode->data.id << "   " << currnode->data.name << endl;
		currnode = currnode->next;
	}
}

//输出链表数据到屏幕---递归实现
void show_recursion(ListNode* list)
{
	if (list != nullptr)
		cout << list->data.id << "   " << list->data.name << endl;
	else
		return;
	show_recursion(list->next);
}

//反向输出链表内容到屏幕上---找到尾结点反向输出
void show_reverse(List *list)
{
	ListNode * currnode = list->next;
	for (int i = 0; i < list->length - 1; i++)//找到尾结点
			currnode = currnode->next;

	for (int i = list->length; i > 0; i--)
	{
		cout << currnode->data.id << "   " << currnode->data.name << endl;
		currnode = currnode->prior;
	}
}

//反向输出链表内容到屏幕上---递归实现
void show_reverse_recursion(ListNode *list)
{
	if (list != nullptr)
		show_reverse_recursion(list->next);
	else
		return;
	cout << list->data.id << "   " << list->data.name << endl;
}