#pragma once
//BF�㷨
int index_bf(char* haystack, char* needle, int pos = 0)//haystack������needle�Ӵ���pos������ʼ����λ��
{
	int n = strlen(haystack), m = strlen(needle);
	int i = pos, j = 0;
	while (i < n && j < m)
	{
		if (haystack[i] == needle[j])
		{
			i++; j++;
		}
		else
		{
			i = i - j + 1;//ָ�����
			j = 0;
		}
		if (j == m)
			return i - j;
	}
	return -1;
}

//KMP�㷨
int *getNext(char *T);
int *getNextVal(char *T);
int index_kmp(char* haystack, char* needle, int pos = 0)
{
	int n = strlen(haystack), m = strlen(needle);
	int i = pos, j = 0;

	int *next = getNext(needle);//��BF�㷨��ͬ��

	//���next����
	std::cout << "next:";
	for (int i = 0; i < m; i++)
		std::cout << next[i] << ' ';
	std::cout << std::endl;

	while (i < n && j < m)
	{
		if (j == -1 || haystack[i] == needle[j])//��BF�㷨��ͬ��
		{
			i++; j++;
		}
		else
		{
			j = next[j];//��BF�㷨��ͬ��
		}
		if (j == m)
			return i - j;
	}
	return -1;
}

//KMP�㷨next�������
int *getNext(char *T)
{
	int m = strlen(T);
	int* next = new int[m] {-1};
	int i = 0, j = -1;

	//�ر�ע�⣬�����m����ô��i==m-1ʱ��while���У���next[++i]�оͻ����next[m] = ++j;��ʱ����Խ��
	while (i < m-1)
	{
		if (j == -1 || T[i] == T[j])
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
	int* nextval = new int[m] {-1};
	int i = 0, j = -1;

	//�ر�ע�⣬�����m����ô��i==m-1ʱ��while���У���nextval[++i]�оͻ����nextval[m] = ++j;��ʱ����Խ��
	while (i < m - 1)
	{
		if (j == -1 || T[i] == T[j])
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