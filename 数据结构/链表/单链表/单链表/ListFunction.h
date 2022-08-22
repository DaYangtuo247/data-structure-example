#pragma once
#include <iostream>
#include "ElementType.h"
using namespace std;


bool InsertLinkList(LinkList*, ElementType, int);//函数声明

//初始化链表
void InitLinkList(LinkList* &list, ElementType *Array, int ArraySize)
{
	list = new LinkList{ nullptr, 0 };
	for (int i = 0; i < ArraySize; i++)
		if (InsertLinkList(list, Array[i], i + 1) == 0)
		{
			cout << "初始化失败！" << endl;
			return;
		}
}

//查找链表中某个元素
int SeekLinkList(LinkList *list, ElementType elem)
{
	ListNode *currnode = list->next;
	for (int i = 1; i < list->length; i++)
	{
		if (currnode->data.id == elem.id && currnode->data.name == elem.name)
			return i;
	}
	return -1;
}

//插入element元素到链表的pos位置
bool InsertLinkList(LinkList *list, ElementType elem, int pos)
{
	if (pos <= 0 || pos > list->length + 1)
		return 0;

	ListNode *newnode = new ListNode{ elem, nullptr };

	if (pos == 1)
	{
		newnode->next = list->next;
		list->next = newnode;
		list->length++;
		return 1;
	}

	ListNode *currnode = list->next;
	for (int i = 1; i < pos-1; i++)
		currnode = currnode->next;
	newnode->next = currnode->next;
	currnode->next = newnode;
	list->length++;
	return 1;
}

//删除pos位置的元素
bool DeleteLinkList(LinkList *list, int pos)
{
	if (pos <= 0 || pos > list->length + 1)
		return 0;

	ListNode *currnode = list->next;
	for (int i = 1; i < pos; i++)
		currnode = currnode->next;

	ListNode *delenode = currnode->next;
	currnode->next = currnode->next->next;
	delete delenode;
	return 1;
}

//返回pos位置处的元素
ElementType GetLinkList(LinkList *list, int pos)
{
	if (pos <= 0 || pos > list->length)
		return{ 0, nullptr };
	
	ListNode *currnode = list->next;
	for (int i = 1; i < pos; i++)
		currnode = currnode->next;

	return currnode->data;
}

//判断链表是否为空
bool IsLinkListEmpty(LinkList* list)
{
	if (list == nullptr || list->length == 0)
	{
		cout << "链表为空！" << endl;
		return 1;
	}
	else
		return 0;
}

//显示链表中的内容
void showlist(LinkList *list)
{
	if (IsLinkListEmpty(list) == 1)
		return;
	ListNode * head = list->next;
	for (int i = 1; i <= list->length; i++)
	{
		printf("%d   %s\n", head->data.id, head->data.name);
		head = head->next;
	}
}

//反向输出链表内容到屏幕上---递归实现
void show_recursion(ListNode *list)
{
	if (list == nullptr)
		return;
	show_recursion(list->next);
	cout << list->data.id << "   " << list->data.name << endl;
}