#pragma once
#include "sqBiTreeElemType.h"

//����
void createTree(BiTree *&);

//�������ݵ�������
void cinTree(BiTree *, int i = 0);

//���������
int getDepth(BiTree *);

//�������洢����
int getNumber(BiTree *);

//���ظ��ڵ�����
char getRoot(BiTree *);

//�ж����Ƿ�Ϊ��
bool isEmpty(BiTree *);

//������
void deleTree(BiTree *&);

//������Ϊ����
void clearTree(BiTree *);

//�������������Ļ
void linkShowTree(BiTree *);

//ǰ�����
void preorderTrav(BiTree *, int i = 0);

//�������
void inorderTrav(BiTree *, int i = 0);

//�������
void postorderTrav(BiTree *, int i = 0);