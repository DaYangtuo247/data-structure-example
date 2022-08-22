#include <iostream>
#include "ElementType.h"
using namespace std;

//�����㷨
bool insert(List *list, ElementType elem, int pos)
{
	//���жϲ���λ���Ƿ����Ҫ��
	if (pos <= 0 || pos > list->length + 1)//���������һ�����֮�����ڵ�
		return 0;

	ListNode *newnode = new ListNode{ elem, nullptr, nullptr };

	if (pos == 1)//����λ��Ϊ�׽��
	{
		newnode->next = list->next;
		list->next = newnode;
		list->length++;

		if (newnode->next != nullptr)//����ڵ���������������1
			newnode->next->prior = newnode;
		return 1;
	}

	//ѭ��������λ�õ�ǰһ�����
	ListNode *currnode = list->next;
	for (int i = 1; i<pos - 1; i++)
		currnode = currnode->next;

	//��һ���ָ��
	newnode->next = currnode->next;
	currnode->next = newnode;

	//��һ���ָ��
	if (newnode->next)
		newnode->next->prior = newnode;
	newnode->prior = currnode;

	list->length++;
	return 1;
}

//����������ݵ���Ļ
void show(List *list)
{
	ListNode * currnode = list->next;
	for (int i = 0; i < list->length; i++)
	{
		cout << currnode->data.id << "   " << currnode->data.name << endl;
		currnode = currnode->next;
	}
}

//����������ݵ���Ļ---�ݹ�ʵ��
void show_recursion(ListNode* list)
{
	if (list != nullptr)
		cout << list->data.id << "   " << list->data.name << endl;
	else
		return;
	show_recursion(list->next);
}

//��������������ݵ���Ļ��---�ҵ�β��㷴�����
void show_reverse(List *list)
{
	ListNode * currnode = list->next;
	for (int i = 0; i < list->length - 1; i++)//�ҵ�β���
			currnode = currnode->next;

	for (int i = list->length; i > 0; i--)
	{
		cout << currnode->data.id << "   " << currnode->data.name << endl;
		currnode = currnode->prior;
	}
}

//��������������ݵ���Ļ��---�ݹ�ʵ��
void show_reverse_recursion(ListNode *list)
{
	if (list != nullptr)
		show_reverse_recursion(list->next);
	else
		return;
	cout << list->data.id << "   " << list->data.name << endl;
}