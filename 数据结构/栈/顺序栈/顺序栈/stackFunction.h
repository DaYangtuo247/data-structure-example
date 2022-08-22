#include "ElementType.h"
#pragma once

//��ʼ��
void init(SeqStack * &stack);

//ѹջ
bool push(SeqStack *stack, ElementType elem);

//����
bool pop(SeqStack *stack);

//����ջ��Ԫ��
ElementType top(SeqStack *stack);

//�п�
bool empty(SeqStack *stack);

//����ջ���
void free(ElementType *elem);

//����ջ
void clear(SeqStack* &stack);

//��ʾ����Ļ
void show(SeqStack *stack);