#pragma once

//�ڵ����������������
typedef struct ElementType {
	int id;
	char *name;
}ElementType;

//������Ľڵ㶨��
typedef struct ListNode {
	ElementType data;
	struct ListNode *next;
}ListNode;

//ͷ���Ķ���
typedef struct Linklist {
	struct ListNode *next;
	int length;
}LinkList;
