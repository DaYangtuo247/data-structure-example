#pragma once
#include "ElementType.h"
//初始化顺序表
void InitList(SequenceList *list, ElementType *elemArray, int elem_length);

//插入元素element在下标为index的位置处
void InsertList(SequenceList *list, ElementType element, int index);

//删除位于下标index处的元素
void DeleteList(SequenceList *list, int index);

//输出顺序表中的元素
void ShowList(SequenceList *list);

//判断顺序表是否为空
bool IsList(SequenceList *list);

//返回当前下标处的元素
ElementType GetElement(SequenceList *List, int index);

//返回线性表长度
int getLength(SequenceList* List);