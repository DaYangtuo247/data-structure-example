#pragma once
struct ElementType {
	int id;
	char *name;
};
struct ListNode {
	ElementType data;
	struct ListNode *prior;//Ҳ����*prev����
	struct ListNode *next;
};

struct List {
	struct ListNode * next;
	int length;
};