#pragma once
struct ElementType {
	int id;
	char *name;
};
struct ListNode {
	ElementType data;
	struct ListNode *prior;//也可用*prev代替
	struct ListNode *next;
};

struct List {
	struct ListNode * next;
	int length;
};