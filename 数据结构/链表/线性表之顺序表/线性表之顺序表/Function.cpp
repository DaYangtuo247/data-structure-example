#pragma once
//定义顺序表的各个函数
#include <iostream>
#include "ElementType.h"
#include "listFunction.h"
using namespace std;
//初始化顺序表
void InitList(SequenceList *list, ElementType *elemArray, int elem_length)
{
	if (elem_length > MAX_SIZE)
	{
		cout << "初始化的数组的长度超出了顺序表的最大可容量长度，初始化失败！！" << endl;
		return;
	}
	list->length = 0;

	for (int i = 0; i < elem_length; i++)
		InsertList(list, elemArray[i], list->length);
}

//向下标为index的位置插入元素element
void InsertList(SequenceList *list, ElementType element, int index)
{
	if (list->length + 1 > MAX_SIZE)
	{
		cout << "顺序表已满！无法完成插入操作！！！" << endl;
		return;
	}
	if (index < 0 || index > list->length)
	{
		cout << "插入的位置不在顺序表的可插入范围内，插入范围为：[0," << list->length << ']' << endl;
		return;
	}

	for (int i = list->length; i > index; i--)
		list->data[i] = list->data[i - 1];

	list->length++;
	list->data[index] = element;
}

//删除位于下标index处的元素element
void DeleteList(SequenceList *list, int index)
{
	if (list->length == 0)
	{
		cout << "顺序表中没有任何元素！无法完成删除操作！！！" << endl;
		return;
	}
	if (index < 0 && index > list->length)
	{
		cout << "删除的位置不在顺序表的可插入范围内，插入范围为：[0," << list->length << ']' << endl;
		return;
	}

	for (int i = index + 1; i < list->length - 1; i++)
		list->data[i] = list->data[i + 1];
	list->length--;
}

//判断顺序表是否为空
bool IsList(SequenceList *list)
{
	if (list->length == 0)
		return false;
	return true;
}

//输出顺序表中的元素
void ShowList(SequenceList *list)
{
	for (int i = 0; i < list->length; i++)
		cout << list->data[i].id << "  " << list->data[i].name << endl;
}

//返回当前下标处的元素
ElementType GetElement(SequenceList *list, int index)
{
	return list->data[index];
}

//返回线性表长度
int getLength(SequenceList* List)
{
	return List->length;
}