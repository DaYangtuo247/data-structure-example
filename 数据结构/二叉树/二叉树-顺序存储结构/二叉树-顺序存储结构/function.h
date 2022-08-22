#pragma once
#include "sqBiTreeElemType.h"

//创建
void createTree(BiTree *&);

//输入数据到二叉树
void cinTree(BiTree *, int i = 0);

//返回树深度
int getDepth(BiTree *);

//返回树存储个数
int getNumber(BiTree *);

//返回根节点数据
char getRoot(BiTree *);

//判断树是否为空
bool isEmpty(BiTree *);

//销毁树
void deleTree(BiTree *&);

//将树清为空树
void clearTree(BiTree *);

//线性输出数到屏幕
void linkShowTree(BiTree *);

//前序遍历
void preorderTrav(BiTree *, int i = 0);

//中序遍历
void inorderTrav(BiTree *, int i = 0);

//后虚遍历
void postorderTrav(BiTree *, int i = 0);