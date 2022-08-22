#pragma once

//��������������
void cinTree(BiTree*&);

//���ظ��ڵ�Ԫ��
char getRoot(BiTree*);

//���������
int getDepth(BiTree*);

//������Ԫ�ظ���
int getNumber(BiTree*);

//�ж����Ƿ�Ϊ��
bool isEmpty(BiTree*);

//������
void deleTree(BiTree*&);

//ǰ�����
void preorderTrav(BiTree*);

//ǰ�����--�ǵݹ�
void preorderTrav_stack(BiTree*);

//�������
void inorderTrav(BiTree*);

//�������--�ǵݹ�
void inorderTrav_stack(BiTree*);

//�������
void postorderTrav(BiTree*);

//�������--�ǵݹ�
void postorderTrav_stack(BiTree*);

//�������
void levelorderTrav(BiTree*);