#pragma once
/*
* 为了避免同一个头文件被包含（include）多次导致编译多次
* C/C++中有两种宏实现方式：一种是#ifndef方式；另一种是#pragma once方式。
* 方法保证了虽然同一头文件被包含多次，但是仅会编译一次
*/
#define MAX_SIZE 255

//定义数据元素
typedef struct {
	int id;
	char *name;
}ElementType;

//定义顺序表结构
typedef struct {
	ElementType data[MAX_SIZE];
	int length;
}SequenceList;