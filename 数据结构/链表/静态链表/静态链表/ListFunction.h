#pragma once
#include "ElementType.h"

//��ʼ����̬����
void init(StaticLinkList *list);

//����Ԫ��element��λ��pos��
bool insert(StaticLinkList *list, ElementType elem, int pos);

//ɾ����λ��pos����Ԫ��
bool deletelist(StaticLinkList *list, int pos);

//���ң�����λ�ã����ظ�λ��Ԫ��
ElementType seek(StaticLinkList *list, int pos);

//�ж������Ƿ�Ϊ��
bool isempty(StaticLinkList *list);

//�ж������Ƿ�����,������ʣ��ռ�
int isfull(StaticLinkList *list);

//���ؾ�̬������
int getlen(StaticLinkList *list);

//��ʾ���������ַ
void showStore(StaticLinkList *list);

//��ʾ������Ļ
void show(StaticLinkList *list);