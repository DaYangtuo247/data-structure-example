#include <iostream>
using namespace std;
#include "function.h"
#include "sqBiTreeElemType.h"

//创建并初始化
void createTree(BiTree* &tree)
{
	tree = new BiTree[MAXSIZE]{ '\0' };
}

//输入数据到二叉树
void cinTree(BiTree *tree, int i)
{
	static int plies = 0;//用于记录层数
	char ch;
	cin>>ch;
	if (ch == '#')
	{
		tree[i] = '\0';
		return;
	}
	tree[i] = ch;
	plies++;
	printf("请输入第%d层左分支结点：", plies);
	cinTree(tree, i * 2 + 1);
	printf("请输入第%d层右分支结点：", plies);
	cinTree(tree, i * 2 + 2);
	plies--;
}

//返回树深度
int getDepth(BiTree *tree)
{
	if (isEmpty(tree))
		return 0;

	for (int i = MAXSIZE - 1, j = 1; i >= 0; i--)
	{
		if (tree[i] != '\0')//从后往前找，直到找到一个非空元素
		{
			while (pow(2, j)-1 < i + 1)//高度为j的二叉树最多有2^j - 1个结点
				j++;
			return j;
		}
	}
	return -1;//深度计算错误时返回-1
}

//返回树存储个数
int getNumber(BiTree *tree)
{
	if (isEmpty(tree))
		return 0;

	int len = 0;
	for (int i = 0; i < MAXSIZE; i++)
		if (tree[i] != '\0')
			len++;
	return len;
}

//返回根节点数据
char getRoot(BiTree *tree)
{
	if (isEmpty(tree))
		return ' ';

	return tree[0];
}

//判断树是否为空
bool isEmpty(BiTree *tree)
{
	if (tree == nullptr)
	{
		cout << "树不存在！" << endl;
		return 1;
	}
	else if (tree[0] == '\0')
	{
		cout << "树中无数据!" << endl;
		return 1;
	}
	return 0;
}

//销毁树
void deleTree(BiTree* &tree)
{
	delete[] tree;
	tree = nullptr;
}

//将树清为空树
void clearTree(BiTree * tree)
{
	memset(tree, '\0', sizeof(tree));//将树全部清理为空
}

//线性输出数到屏幕
void linkShowTree(BiTree *tree)
{
	if (isEmpty(tree))
		return;
	int len = int(pow(2,getDepth(tree)) - 1);//高度为H的二叉树，最多存储2^H - 1个元素
	for (int i = 0; i < len; i++)
	{
		if (tree[i] == '\0')
			cout << "0 ";
		else
			cout << tree[i] << ' ';
	}
}

//前序遍历
void preorderTrav(BiTree *tree, int i)//中左右
{
	if (tree[i] != '\0')//打印中
	{
		cout << tree[i] << ' ';
		preorderTrav(tree, i * 2 + 1);//左子树
		preorderTrav(tree, i * 2 + 2);//右子树
	}
}

//中序遍历
void inorderTrav(BiTree *tree, int i)//左中右
{
	if (tree[i] != '\0')
	{
		inorderTrav(tree, i * 2 + 1);
		cout << tree[i] << ' ';
		inorderTrav(tree, i * 2 + 2);
	}
}

//后虚遍历
void postorderTrav(BiTree *tree, int i)//左右中
{
	if (tree[i] != '\0')
	{
		postorderTrav(tree, i * 2 + 1);
		postorderTrav(tree, i * 2 + 2);
		cout << tree[i] << ' ';
	}
}