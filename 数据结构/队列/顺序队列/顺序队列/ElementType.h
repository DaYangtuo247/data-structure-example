#pragma once
#define MAX_SIZE 10

typedef struct ElementType{
	int id;
	char *name;
}ElementType;

typedef struct SeqQueue {
	ElementType data[MAX_SIZE];
	int front;//��ͷ
	int rear;//��β
}SeqQueue;