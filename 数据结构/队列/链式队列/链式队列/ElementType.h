#pragma once

typedef struct ElementType {
	int id;
	char *name;
}ElementType;

typedef struct LinkNode {
	ElementType data;
	struct LinkNode *next;
}LinkNode;

typedef struct LinkQueue {
	int length;
	struct LinkNode *front;
	struct LinkNode *rear;
}LinkQueue;
