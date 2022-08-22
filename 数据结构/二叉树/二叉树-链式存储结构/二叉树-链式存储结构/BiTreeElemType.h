#pragma once

//二叉树结构定义
typedef struct BiTreeNode {
	char data;
	struct BiTreeNode *left;
	struct BiTreeNode *right;
}BiTree;