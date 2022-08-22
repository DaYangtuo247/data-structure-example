#pragma once
#define MAX_SIZE 10

typedef struct ElementType {
	int id;
	char *name;
}ElementType;

typedef struct StaticLinkList {
	ElementType data;
	int cursor;
}StaticLinkList;