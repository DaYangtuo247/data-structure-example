#include <iostream>
#include "Function.h"
/*
*程序介绍：串的模式匹配算法之BF/KMP算法
*输入前提：要求给定的字符串有效 且 主子串非空
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
		cout << "主串:" << ST[i][0] << "\n子串:" << ST[i][1] << "\nBF算法:"
			<< index_bf(ST[i][0], ST[i][1])
			<< "\nKMP算法:" << index_kmp(ST[i][0], ST[i][1]) << endl << endl;
	}
	return 0;
}