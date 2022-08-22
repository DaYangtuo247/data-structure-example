#pragma once
#include <iostream>
#include "ElementType.h"
using namespace std;


bool InsertLinkList(LinkList*, ElementType, int);//��������

//��ʼ������
void InitLinkList(LinkList* &list, ElementType *Array, int ArraySize)
{
	list = new LinkList{ nullptr, 0 };
	for (int i = 0; i < ArraySize; i++)
		if (InsertLinkList(list, Array[i], i + 1) == 0)
		{
			cout << "��ʼ��ʧ�ܣ�" << endl;
			return;
		}
}

//����������ĳ��Ԫ��
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

//����elementԪ�ص������posλ��
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

//ɾ��posλ�õ�Ԫ��
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

//����posλ�ô���Ԫ��
ElementType GetLinkList(LinkList *list, int pos)
{
	if (pos <= 0 || pos > list->length)
		return{ 0, nullptr };
	
	ListNode *currnode = list->next;
	for (int i = 1; i < pos; i++)
		currnode = currnode->next;

	return currnode->data;
}

//�ж������Ƿ�Ϊ��
bool IsLinkListEmpty(LinkList* list)
{
	if (list == nullptr || list->length == 0)
	{
		cout << "����Ϊ�գ�" << endl;
		return 1;
	}
	else
		return 0;
}

//��ʾ�����е�����
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

//��������������ݵ���Ļ��---�ݹ�ʵ��
void show_recursion(ListNode *list)
{
	if (list == nullptr)
		return;
	show_recursion(list->next);
	cout << list->data.id << "   " << list->data.name << endl;
}