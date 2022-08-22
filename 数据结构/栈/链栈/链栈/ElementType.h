#pragma once

//栈存储的数据类型
typedef struct ElementType {
	int id;
	char *name;
}ElementType;

//栈结点
typedef struct StackNode {
	ElementType data;
	struct StackNode* next;
}StackNode;

//头结点
typedef struct LinkStack {
	int length;
	struct StackNode* top;
}LinkStack;