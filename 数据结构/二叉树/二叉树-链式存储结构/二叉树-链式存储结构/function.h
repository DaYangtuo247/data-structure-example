#pragma once

//创建并输入数据
void cinTree(BiTree*&);

//返回根节点元素
char getRoot(BiTree*);

//返回树深度
int getDepth(BiTree*);

//返回树元素个数
int getNumber(BiTree*);

//判断树是否为空
bool isEmpty(BiTree*);

//销毁树
void deleTree(BiTree*&);

//前序遍历
void preorderTrav(BiTree*);

//前序遍历--非递归
void preorderTrav_stack(BiTree*);

//中序遍历
void inorderTrav(BiTree*);

//中序遍历--非递归
void inorderTrav_stack(BiTree*);

//后序遍历
void postorderTrav(BiTree*);

//后序遍历--非递归
void postorderTrav_stack(BiTree*);

//层序遍历
void levelorderTrav(BiTree*);