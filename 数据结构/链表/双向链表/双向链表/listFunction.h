#pragma once
#include "ElementType.h"

//�����㷨
bool insert(List *list, ElementType elem, int pos);

//����������ݵ���Ļ
void show(List *list);

//����������ݵ���Ļ---�ݹ�ʵ��
void show_recursion(ListNode* list);

//��������������ݵ���Ļ��---�ҵ�β��㷴�����
void show_reverse(List *list);

//��������������ݵ���Ļ��---�ݹ鷽ʽ
void show_reverse_recursion(ListNode *list);