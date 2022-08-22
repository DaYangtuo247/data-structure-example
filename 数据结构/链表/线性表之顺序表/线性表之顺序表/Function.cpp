#pragma once
//����˳���ĸ�������
#include <iostream>
#include "ElementType.h"
#include "listFunction.h"
using namespace std;
//��ʼ��˳���
void InitList(SequenceList *list, ElementType *elemArray, int elem_length)
{
	if (elem_length > MAX_SIZE)
	{
		cout << "��ʼ��������ĳ��ȳ�����˳���������������ȣ���ʼ��ʧ�ܣ���" << endl;
		return;
	}
	list->length = 0;

	for (int i = 0; i < elem_length; i++)
		InsertList(list, elemArray[i], list->length);
}

//���±�Ϊindex��λ�ò���Ԫ��element
void InsertList(SequenceList *list, ElementType element, int index)
{
	if (list->length + 1 > MAX_SIZE)
	{
		cout << "˳����������޷���ɲ������������" << endl;
		return;
	}
	if (index < 0 || index > list->length)
	{
		cout << "�����λ�ò���˳���Ŀɲ��뷶Χ�ڣ����뷶ΧΪ��[0," << list->length << ']' << endl;
		return;
	}

	for (int i = list->length; i > index; i--)
		list->data[i] = list->data[i - 1];

	list->length++;
	list->data[index] = element;
}

//ɾ��λ���±�index����Ԫ��element
void DeleteList(SequenceList *list, int index)
{
	if (list->length == 0)
	{
		cout << "˳�����û���κ�Ԫ�أ��޷����ɾ������������" << endl;
		return;
	}
	if (index < 0 && index > list->length)
	{
		cout << "ɾ����λ�ò���˳���Ŀɲ��뷶Χ�ڣ����뷶ΧΪ��[0," << list->length << ']' << endl;
		return;
	}

	for (int i = index + 1; i < list->length - 1; i++)
		list->data[i] = list->data[i + 1];
	list->length--;
}

//�ж�˳����Ƿ�Ϊ��
bool IsList(SequenceList *list)
{
	if (list->length == 0)
		return false;
	return true;
}

//���˳����е�Ԫ��
void ShowList(SequenceList *list)
{
	for (int i = 0; i < list->length; i++)
		cout << list->data[i].id << "  " << list->data[i].name << endl;
}

//���ص�ǰ�±괦��Ԫ��
ElementType GetElement(SequenceList *list, int index)
{
	return list->data[index];
}

//�������Ա���
int getLength(SequenceList* List)
{
	return List->length;
}