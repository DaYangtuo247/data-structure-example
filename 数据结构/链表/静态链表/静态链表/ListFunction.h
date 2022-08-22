#pragma once
#include "ElementType.h"

//初始化静态链表
void init(StaticLinkList *list);

//插入元素element到位置pos处
bool insert(StaticLinkList *list, ElementType elem, int pos);

//删除在位置pos处的元素
bool deletelist(StaticLinkList *list, int pos);

//查找，给定位置，返回该位置元素
ElementType seek(StaticLinkList *list, int pos);

//判断链表是否为空
bool isempty(StaticLinkList *list);

//判断链表是否已满,并返回剩余空间
int isfull(StaticLinkList *list);

//返回静态链表长度
int getlen(StaticLinkList *list);

//显示链表物理地址
void showStore(StaticLinkList *list);

//显示链表到屏幕
void show(StaticLinkList *list);