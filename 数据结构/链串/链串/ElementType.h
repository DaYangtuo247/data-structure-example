#pragma once
#define strNodeLen 6

typedef struct strNode {
	char str[strNodeLen];
	struct strNode *next;
}strNode;

typedef struct LinkStr {
	struct strNode *next;
	int length;
}LinkStr;