#pragma once

//ջ�洢����������
typedef struct ElementType {
	int id;
	char *name;
}ElementType;

//ջ���
typedef struct StackNode {
	ElementType data;
	struct StackNode* next;
}StackNode;

//ͷ���
typedef struct LinkStack {
	int length;
	struct StackNode* top;
}LinkStack;