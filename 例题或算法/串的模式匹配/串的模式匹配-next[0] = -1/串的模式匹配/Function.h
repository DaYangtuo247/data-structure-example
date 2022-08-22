#pragma once
//BF算法
int index_bf(char* haystack, char* needle, int pos = 0)//haystack主串，needle子串，pos主串开始查找位置
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
			i = i - j + 1;//指针回溯
			j = 0;
		}
		if (j == m)
			return i - j;
	}
	return -1;
}

//KMP算法
int *getNext(char *T);
int *getNextVal(char *T);
int index_kmp(char* haystack, char* needle, int pos = 0)
{
	int n = strlen(haystack), m = strlen(needle);
	int i = pos, j = 0;

	int *next = getNext(needle);//与BF算法不同点

	//输出next数组
	std::cout << "next:";
	for (int i = 0; i < m; i++)
		std::cout << next[i] << ' ';
	std::cout << std::endl;

	while (i < n && j < m)
	{
		if (j == -1 || haystack[i] == needle[j])//与BF算法不同点
		{
			i++; j++;
		}
		else
		{
			j = next[j];//与BF算法不同点
		}
		if (j == m)
			return i - j;
	}
	return -1;
}

//KMP算法next数组计算
int *getNext(char *T)
{
	int m = strlen(T);
	int* next = new int[m] {-1};
	int i = 0, j = -1;

	//特别注意，如果是m，那么当i==m-1时，while放行，在next[++i]中就会出现next[m] = ++j;此时数组越界
	while (i < m-1)
	{
		if (j == -1 || T[i] == T[j])
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
	int* nextval = new int[m] {-1};
	int i = 0, j = -1;

	//特别注意，如果是m，那么当i==m-1时，while放行，在nextval[++i]中就会出现nextval[m] = ++j;此时数组越界
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