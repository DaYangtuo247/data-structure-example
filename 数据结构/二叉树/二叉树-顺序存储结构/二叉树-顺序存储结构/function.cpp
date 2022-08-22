#include <iostream>
using namespace std;
#include "function.h"
#include "sqBiTreeElemType.h"

//��������ʼ��
void createTree(BiTree* &tree)
{
	tree = new BiTree[MAXSIZE]{ '\0' };
}

//�������ݵ�������
void cinTree(BiTree *tree, int i)
{
	static int plies = 0;//���ڼ�¼����
	char ch;
	cin>>ch;
	if (ch == '#')
	{
		tree[i] = '\0';
		return;
	}
	tree[i] = ch;
	plies++;
	printf("�������%d�����֧��㣺", plies);
	cinTree(tree, i * 2 + 1);
	printf("�������%d���ҷ�֧��㣺", plies);
	cinTree(tree, i * 2 + 2);
	plies--;
}

//���������
int getDepth(BiTree *tree)
{
	if (isEmpty(tree))
		return 0;

	for (int i = MAXSIZE - 1, j = 1; i >= 0; i--)
	{
		if (tree[i] != '\0')//�Ӻ���ǰ�ң�ֱ���ҵ�һ���ǿ�Ԫ��
		{
			while (pow(2, j)-1 < i + 1)//�߶�Ϊj�Ķ����������2^j - 1�����
				j++;
			return j;
		}
	}
	return -1;//��ȼ������ʱ����-1
}

//�������洢����
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

//���ظ��ڵ�����
char getRoot(BiTree *tree)
{
	if (isEmpty(tree))
		return ' ';

	return tree[0];
}

//�ж����Ƿ�Ϊ��
bool isEmpty(BiTree *tree)
{
	if (tree == nullptr)
	{
		cout << "�������ڣ�" << endl;
		return 1;
	}
	else if (tree[0] == '\0')
	{
		cout << "����������!" << endl;
		return 1;
	}
	return 0;
}

//������
void deleTree(BiTree* &tree)
{
	delete[] tree;
	tree = nullptr;
}

//������Ϊ����
void clearTree(BiTree * tree)
{
	memset(tree, '\0', sizeof(tree));//����ȫ������Ϊ��
}

//�������������Ļ
void linkShowTree(BiTree *tree)
{
	if (isEmpty(tree))
		return;
	int len = int(pow(2,getDepth(tree)) - 1);//�߶�ΪH�Ķ����������洢2^H - 1��Ԫ��
	for (int i = 0; i < len; i++)
	{
		if (tree[i] == '\0')
			cout << "0 ";
		else
			cout << tree[i] << ' ';
	}
}

//ǰ�����
void preorderTrav(BiTree *tree, int i)//������
{
	if (tree[i] != '\0')//��ӡ��
	{
		cout << tree[i] << ' ';
		preorderTrav(tree, i * 2 + 1);//������
		preorderTrav(tree, i * 2 + 2);//������
	}
}

//�������
void inorderTrav(BiTree *tree, int i)//������
{
	if (tree[i] != '\0')
	{
		inorderTrav(tree, i * 2 + 1);
		cout << tree[i] << ' ';
		inorderTrav(tree, i * 2 + 2);
	}
}

//�������
void postorderTrav(BiTree *tree, int i)//������
{
	if (tree[i] != '\0')
	{
		postorderTrav(tree, i * 2 + 1);
		postorderTrav(tree, i * 2 + 2);
		cout << tree[i] << ' ';
	}
}