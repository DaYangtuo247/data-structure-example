#include <iostream>
#include "Function.h"
/*
*������ܣ�����ģʽƥ���㷨֮BF/KMP�㷨
*����ǰ�᣺Ҫ��������ַ�����Ч �� ���Ӵ��ǿ�
*/

int main()
{
	using namespace std;

	char ST[][2][25] = {
		{ "hello" , "ll" },
		{ "goodgoogle" , "google" },
		{ "aaaaa" ,"bba" },
		{ "aabbaabbf" ,"aabbf" },
		{ "good", "g" },
		{ "aaaadce", "aaaaax"}
	};

	int len = sizeof(ST) / sizeof(ST[0]);

	for (int i = 0; i < len; i++)
	{
		cout << "����:" << ST[i][0] << "\n�Ӵ�:" << ST[i][1] << "\nBF�㷨:"
			<< index_bf(ST[i][0], ST[i][1])
			<< "\nKMP�㷨:" << index_kmp(ST[i][0], ST[i][1]) << endl << endl;
	}
	return 0;
}