#pragma once
using namespace std;
//BF�㷨
int index_bf(char* S, char* T, int pos = 1)//S������T�Ӵ���pos������ʼ����λ��
{
	int n = strlen(S) - 1, m = strlen(T) - 1;//ȥ���ո�
	int i = pos, j = 1;//�ַ���0λ�пո�Ҫ��1λ��ʼ
	while (i <= n && j <= m)
	{
		if (S[i] == T[j])
		{
			i++; j++;
		}
		else
		{
			i = i - j + 2;//ָ�����
			j = 1;
		}
		if (j > m)
			return i - m;
	}
	return -1;
}

//KMP�㷨
int *getNext(char *T);
int *getNextVal(char *T);
int index_kmp(char* S, char* T, int pos = 1)
{
	int n = strlen(S) - 1, m = strlen(T) - 1;
	int i = pos, j = 1;

	int *next = getNext(T);//��BF�㷨��ͬ��
	
	//���next����
	cout << "next��";
	for (int i = 1; i < m + 1; i++)//m+1����ԭ���ַ����ĳ���
		cout << next[i] << ' ';
	cout << endl;

	while (i <= n && j <= m)
	{
		if (j == 0 || S[i] == T[j])//��BF�㷨��ͬ��
		{
			i++; j++;
		}
		else
		{
			j = next[j];//��BF�㷨��ͬ��
		}
		if (j > m)
			return i - m;
	}
	return -1;
}

//KMP�㷨next�������
int *getNext(char *T)
{
	int m = strlen(T);
	int *next = new int[m + 1]{ 0 };
	int i = 1, j = 0;

	//�ر�ע�⣬�����m����ô��i==m-1ʱ��while���У���nextval[++i]�оͻ����nextval[m] = ++j;��ʱ����Խ��
	while (i < m - 1)
	{
		if (j == 0 || T[i] == T[j])
			next[++i] = ++j;
		else
			j = next[j];
	}
	return next;
}

//��next����ĸĽ��㷨
int *getNextVal(char *T)
{
	int m = strlen(T);
	int *nextval = new int[m + 1]{ -1 };
	int i = 1, j = 0;
	//�ر�ע�⣬�����m����ô��i==m-1ʱ��while���У���nextval[++i]�оͻ����nextval[m] = ++j;��ʱ����Խ��
	while (i < m - 1)
	{
		if (j == 0 || T[i] == T[j])
		{
			i++; j++;
			if (T[i] != T[j])
				nextval[i] = j;
			else
				nextval[i] = nextval[j];
		}
		else
			j = nextval[j];
	}
	return nextval;
}