#pragma once
#include "ElementType.h"

//插入算法
bool insert(List *list, ElementType elem, int pos);

//输出链表数据到屏幕
void show(List *list);

//输出链表数据到屏幕---递归实现
void show_recursion(ListNode* list);

//反向输出链表内容到屏幕上---找到尾结点反向输出
void show_reverse(List *list);

//反向输出链表内容到屏幕上---递归方式
void show_reverse_recursion(ListNode *list);