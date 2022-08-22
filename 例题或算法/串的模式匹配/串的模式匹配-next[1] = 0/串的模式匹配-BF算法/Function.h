#pragma once
using namespace std;
//BF算法
int index_bf(char* S, char* T, int pos = 1)//S主串，T子串，pos主串开始查找位置
{
	int n = strlen(S) - 1, m = strlen(T) - 1;//去除空格
	int i = pos, j = 1;//字符串0位有空格，要从1位开始
	while (i <= n && j <= m)
	{
		if (S[i] == T[j])
		{
			i++; j++;
		}
		else
		{
			i = i - j + 2;//指针回溯
			j = 1;
		}
		if (j > m)
			return i - m;
	}
	return -1;
}

//KMP算法
int *getNext(char *T);
int *getNextVal(char *T);
int index_kmp(char* S, char* T, int pos = 1)
{
	int n = strlen(S) - 1, m = strlen(T) - 1;
	int i = pos, j = 1;

	int *next = getNext(T);//与BF算法不同点
	
	//输出next数组
	cout << "next：";
	for (int i = 1; i < m + 1; i++)//m+1才是原本字符串的长度
		cout << next[i] << ' ';
	cout << endl;

	while (i <= n && j <= m)
	{
		if (j == 0 || S[i] == T[j])//与BF算法不同点
		{
			i++; j++;
		}
		else
		{
			j = next[j];//与BF算法不同点
		}
		if (j > m)
			return i - m;
	}
	return -1;
}

//KMP算法next数组计算
int *getNext(char *T)
{
	int m = strlen(T);
	int *next = new int[m + 1]{ 0 };
	int i = 1, j = 0;

	//特别注意，如果是m，那么当i==m-1时，while放行，在nextval[++i]中就会出现nextval[m] = ++j;此时数组越界
	while (i < m - 1)
	{
		if (j == 0 || T[i] == T[j])
			next[++i] = ++j;
		else
			j = next[j];
	}
	return next;
}

//对next数组的改进算法
int *getNextVal(char *T)
{
	int m = strlen(T);
	int *nextval = new int[m + 1]{ -1 };
	int i = 1, j = 0;
	//特别注意，如果是m，那么当i==m-1时，while放行，在nextval[++i]中就会出现nextval[m] = ++j;此时数组越界
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