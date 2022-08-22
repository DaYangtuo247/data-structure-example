#pragma once

//节点数据域的数据类型
typedef struct ElementType {
	int id;
	char *name;
}ElementType;

//单链表的节点定义
typedef struct ListNode {
	ElementType data;
	struct ListNode *next;
}ListNode;

//头结点的定义
typedef struct Linklist {
	struct ListNode *next;
	int length;
}LinkList;
