#include <iostream>
#include "transition.h"
#define SIZE 100
/*
程序简介：该计算器可计算带+, -, *, /, %, ()的基本运算,同时可自定义运算符
例如，定义运算符P为计算a的b次方，输入aPb，即可计算a的b次方

自定义方法：修改infix_suffix()运算符优先级判断位置以及result的case标签位置
*/
int main()
{
	using namespace std;
	char expr[SIZE];
	cout << "请输入的算式:";	
	cin.getline(expr, SIZE);

	infix_suffix(expr, strlen(expr));

	cout << "转换为后缀表达式：";
	for (int i = 0; expr[i] != '\0'; i++)
		cout << expr[i];

	cout << "\n由后缀表达式所计算的结果：" << result(expr, strlen(expr)) << endl;
	return 0;
}