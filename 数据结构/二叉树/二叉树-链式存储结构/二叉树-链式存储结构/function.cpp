#include <iostream>
#include <stack>
#include <queue>
#include "BiTreeElemType.h"
#include "function.h"
using namespace std;

//创建并输入数据
void cinTree(BiTree*& tree)//使用引用写法的好处在于当一开始就给根节点输入#时，不会创建根节点，造成内存泄漏
{
	static int depth = 0;
	char ch;
	cin >> ch;

	if (ch == '#')
		return;

	tree = new BiTree{ ch, nullptr, nullptr };

	depth++;
	cout << "请输入第" << depth << "层左分支结点：";
	cinTree(tree->left);

	cout << "请输入第" << depth << "层右分支结点：";
	cinTree(tree->right);
	depth--;
}

//返回根节点元素
char getRoot(BiTree* tree)
{
	if (tree == nullptr)
		return 'N';
	return tree->data;
}

//返回树深度
int getDepth(BiTree* tree)
{
	if (!tree)
		return 0;

	int n = getDepth(tree->left);
	int m = getDepth(tree->right);
	return m > n ? m + 1 : n + 1;
}

//返回树元素个数
int getNumber(BiTree* tree)
{
	if (tree)
		return getNumber(tree->left) + getNumber(tree->right) + 1;
	else
		return 0;
}

//判断树是否为空
bool isEmpty(BiTree* tree)
{
	if (tree == nullptr)
	{
		cout << "未创建！" << endl;
		return 1;
	}
	if (tree->data == '\0')
	{
		cout << "树为空！" << endl;
		return 1;
	}
	cout << "存在" << endl;
	return 0;
}

//销毁树
void deleTree(BiTree*& tree)
{
	if (!tree)
		return;

	deleTree(tree->left);
	deleTree(tree->right);
	delete tree;
	tree = nullptr;
}

//前序遍历
void preorderTrav(BiTree* tree)
{
	if (tree)
	{
		cout << tree->data << ' ';
		preorderTrav(tree->left);
		preorderTrav(tree->right);
	}
}

//中序遍历
void inorderTrav(BiTree* tree)
{
	if (tree)
	{
		inorderTrav(tree->left);
		cout << tree->data << ' ';
		inorderTrav(tree->right);
	}
}

//后序遍历
void postorderTrav(BiTree* tree)
{
	if (tree)
	{
		postorderTrav(tree->left);
		postorderTrav(tree->right);
		cout << tree->data << ' ';
	}
}

//前序遍历--非递归
void preorderTrav_stack(BiTree* tree)
{
	stack<BiTree*>st;//用于存储父节点
	while (tree || !st.empty())
	{
		if (tree)//父节点存在时
		{
			st.push(tree);//父节点入栈
			cout << tree->data << ' ';
			tree = tree->left;//访问左子结点
		}
		else
		{
			tree = st.top();//回溯父节点
			st.pop();
			tree = tree->right;//右子节点
		}
	}
}

//中序遍历--非递归
void inorderTrav_stack(BiTree* tree)
{
	stack<BiTree*>st;//用于存储父节点
	while (tree || !st.empty())
	{
		if (tree)//父节点存在
		{
			st.push(tree);//父节点入栈
			tree = tree->left;//访问左子节点
		}
		else//左子节点不存在时
		{
			tree = st.top();//回溯到父节点
			st.pop();
			cout << tree->data << ' ';//打印父节点
			tree = tree->right;//访问右子树
		}
	}
}

//后序遍历--非递归
void postorderTrav_stack(BiTree* tree)
{
	//前序中左右， 在前序基础上修改为中右左，在反向输出即为后序左右中
	stack<BiTree*>st;//用于存储父节点
	stack<char>ret;//用于存储后序遍历结果

	while (tree || !st.empty())
	{
		if (tree)//父节点存在
		{
			st.push(tree);//父节点入栈
			ret.push(tree->data);//数据入栈
			tree = tree->right;//访问右子节点
		}
		else
		{
			tree = st.top();//右子节点不存在，回溯到父节点
			st.pop();
			tree = tree->left;//访问左子节点
		}
	}
	while (!ret.empty())//输出中序遍历结果 
	{
		cout << ret.top() << ' ';
		ret.pop();
	}
}

//层序遍历
void levelorderTrav(BiTree* tree)
{
	queue<BiTree*>que;
	if (tree)//确保循环可以开始
		que.push(tree);
	while (!que.empty())
	{
		int size = que.size();//在for循环中que.size()会随着que.pop()的改变而改变

		for (int i = 0; i < size; i++)
		{
			BiTree* node = que.front();
			que.pop();
			cout << node->data << ' ';
			
			if (node->left)//当前结点的左右子结点分别入队
				que.push(node->left);
			if (node->right)
				que.push(node->right);
		}
		cout << endl;//打印一层后换行加以区分
	}
}