#include "ElementType.h"
#pragma once

//初始化
void init(SeqStack * &stack);

//压栈
bool push(SeqStack *stack, ElementType elem);

//弹出
bool pop(SeqStack *stack);

//返回栈顶元素
ElementType top(SeqStack *stack);

//判空
bool empty(SeqStack *stack);

//清理栈结点
void free(ElementType *elem);

//销毁栈
void clear(SeqStack* &stack);

//显示到屏幕
void show(SeqStack *stack);