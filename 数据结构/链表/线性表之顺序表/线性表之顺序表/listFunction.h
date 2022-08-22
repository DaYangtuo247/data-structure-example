#pragma once
#include "ElementType.h"
//��ʼ��˳���
void InitList(SequenceList *list, ElementType *elemArray, int elem_length);

//����Ԫ��element���±�Ϊindex��λ�ô�
void InsertList(SequenceList *list, ElementType element, int index);

//ɾ��λ���±�index����Ԫ��
void DeleteList(SequenceList *list, int index);

//���˳����е�Ԫ��
void ShowList(SequenceList *list);

//�ж�˳����Ƿ�Ϊ��
bool IsList(SequenceList *list);

//���ص�ǰ�±괦��Ԫ��
ElementType GetElement(SequenceList *List, int index);

//�������Ա���
int getLength(SequenceList* List);