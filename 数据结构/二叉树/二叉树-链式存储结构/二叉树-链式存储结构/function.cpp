#include <iostream>
#include <stack>
#include <queue>
#include "BiTreeElemType.h"
#include "function.h"
using namespace std;

//��������������
void cinTree(BiTree*& tree)//ʹ������д���ĺô����ڵ�һ��ʼ�͸����ڵ�����#ʱ�����ᴴ�����ڵ㣬����ڴ�й©
{
	static int depth = 0;
	char ch;
	cin >> ch;

	if (ch == '#')
		return;

	tree = new BiTree{ ch, nullptr, nullptr };

	depth++;
	cout << "�������" << depth << "�����֧��㣺";
	cinTree(tree->left);

	cout << "�������" << depth << "���ҷ�֧��㣺";
	cinTree(tree->right);
	depth--;
}

//���ظ��ڵ�Ԫ��
char getRoot(BiTree* tree)
{
	if (tree == nullptr)
		return 'N';
	return tree->data;
}

//���������
int getDepth(BiTree* tree)
{
	if (!tree)
		return 0;

	int n = getDepth(tree->left);
	int m = getDepth(tree->right);
	return m > n ? m + 1 : n + 1;
}

//������Ԫ�ظ���
int getNumber(BiTree* tree)
{
	if (tree)
		return getNumber(tree->left) + getNumber(tree->right) + 1;
	else
		return 0;
}

//�ж����Ƿ�Ϊ��
bool isEmpty(BiTree* tree)
{
	if (tree == nullptr)
	{
		cout << "δ������" << endl;
		return 1;
	}
	if (tree->data == '\0')
	{
		cout << "��Ϊ�գ�" << endl;
		return 1;
	}
	cout << "����" << endl;
	return 0;
}

//������
void deleTree(BiTree*& tree)
{
	if (!tree)
		return;

	deleTree(tree->left);
	deleTree(tree->right);
	delete tree;
	tree = nullptr;
}

//ǰ�����
void preorderTrav(BiTree* tree)
{
	if (tree)
	{
		cout << tree->data << ' ';
		preorderTrav(tree->left);
		preorderTrav(tree->right);
	}
}

//�������
void inorderTrav(BiTree* tree)
{
	if (tree)
	{
		inorderTrav(tree->left);
		cout << tree->data << ' ';
		inorderTrav(tree->right);
	}
}

//�������
void postorderTrav(BiTree* tree)
{
	if (tree)
	{
		postorderTrav(tree->left);
		postorderTrav(tree->right);
		cout << tree->data << ' ';
	}
}

//ǰ�����--�ǵݹ�
void preorderTrav_stack(BiTree* tree)
{
	stack<BiTree*>st;//���ڴ洢���ڵ�
	while (tree || !st.empty())
	{
		if (tree)//���ڵ����ʱ
		{
			st.push(tree);//���ڵ���ջ
			cout << tree->data << ' ';
			tree = tree->left;//�������ӽ��
		}
		else
		{
			tree = st.top();//���ݸ��ڵ�
			st.pop();
			tree = tree->right;//���ӽڵ�
		}
	}
}

//�������--�ǵݹ�
void inorderTrav_stack(BiTree* tree)
{
	stack<BiTree*>st;//���ڴ洢���ڵ�
	while (tree || !st.empty())
	{
		if (tree)//���ڵ����
		{
			st.push(tree);//���ڵ���ջ
			tree = tree->left;//�������ӽڵ�
		}
		else//���ӽڵ㲻����ʱ
		{
			tree = st.top();//���ݵ����ڵ�
			st.pop();
			cout << tree->data << ' ';//��ӡ���ڵ�
			tree = tree->right;//����������
		}
	}
}

//�������--�ǵݹ�
void postorderTrav_stack(BiTree* tree)
{
	//ǰ�������ң� ��ǰ��������޸�Ϊ�������ڷ��������Ϊ����������
	stack<BiTree*>st;//���ڴ洢���ڵ�
	stack<char>ret;//���ڴ洢����������

	while (tree || !st.empty())
	{
		if (tree)//���ڵ����
		{
			st.push(tree);//���ڵ���ջ
			ret.push(tree->data);//������ջ
			tree = tree->right;//�������ӽڵ�
		}
		else
		{
			tree = st.top();//���ӽڵ㲻���ڣ����ݵ����ڵ�
			st.pop();
			tree = tree->left;//�������ӽڵ�
		}
	}
	while (!ret.empty())//������������� 
	{
		cout << ret.top() << ' ';
		ret.pop();
	}
}

//�������
void levelorderTrav(BiTree* tree)
{
	queue<BiTree*>que;
	if (tree)//ȷ��ѭ�����Կ�ʼ
		que.push(tree);
	while (!que.empty())
	{
		int size = que.size();//��forѭ����que.size()������que.pop()�ĸı���ı�

		for (int i = 0; i < size; i++)
		{
			BiTree* node = que.front();
			que.pop();
			cout << node->data << ' ';
			
			if (node->left)//��ǰ���������ӽ��ֱ����
				que.push(node->left);
			if (node->right)
				que.push(node->right);
		}
		cout << endl;//��ӡһ����м�������
	}
}