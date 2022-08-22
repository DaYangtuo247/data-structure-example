#pragma once
#include <iostream>
#include <cmath>//使用了pow函数
#include <stack>
#include <queue>
using namespace std;

bool preOperator(char top, char s);//运算符优先级判断

//中缀表达式转后缀表达式
void infix_suffix(char *expr, int len)
{
	stack<char>sign;//创建栈
	queue<char>suffix;//创建队列

	//中缀表达式转后缀表达式并入队
	for (int i = 0; i < len; i++)
	{
		if (isspace(expr[i]))//跳过空白字符
			continue;

		if (isdigit(expr[i]) || expr[i] == '.')//如果是数字,直接入队
		{
			suffix.push(expr[i]);
			continue;
		}

		suffix.push(' ');
		if (expr[i] == ')')//如果是右括号,输出栈中左括号上方的所有运算符
		{
			while (sign.top() != '(')
			{
				suffix.push(sign.top());//将运算符入队
				sign.pop();//移出栈顶元素
			}
			sign.pop();//删除栈顶的左括号
			continue;
		}

		if (expr[i] != '(' && sign.size() != 0)//运算符入栈前要保证栈不为空,且非括号
		{
			//当前运算符优先级  低于或等于  栈顶符号优先级全部输出
			if (preOperator(sign.top(), expr[i]))
			{
				while (sign.size() && sign.top() != '(')
				{
					suffix.push(sign.top());//将运算符入队
					sign.pop();//移出栈顶元素
				}
			}
		}
		sign.push(expr[i]);
	}

	while (sign.size())//将栈中余下运算符全部入队
	{
		suffix.push(sign.top());
		sign.pop();
	}

	//将队列存放到原数组
	int eq_size = suffix.size();
	expr[eq_size] = '\0';
	for (int i = 0; i < eq_size; i++)
	{
		expr[i] = suffix.front();
		suffix.pop();
	}
}

//运算符优先级判断
bool preOperator(char top, char s)//运算符优先级判断
{
	char Oper[] = { '+', '-', '*', '/', '%'};
	int len = sizeof(Oper) / sizeof(Oper[0]);
	int indextop, indexs;
	for (int i = 0; i < len; i++)//找到该符号在运算符中的位置
		if (Oper[i] == s)
			indexs = i;
		else if (Oper[i] == top)
			indextop = i;

	if (indexs < 2 && indextop > 1)//当前运算符优先级低于栈顶
		return 1;
	else if ((indexs < 2 && indextop < 2) || (indexs > 1 && indextop > 1))//同级运算符
		return 1;

	return 0;
}

//返回计算结果
double result(char *expr, int len)
{
	stack<double>sign;//创建栈
	bool indigit = false;//用于判断字符是否在一个整数内
	bool Float = false;//记录浮点数的小数点是否出现
	int Float_size = 0;//记录每一个浮点数小数点后的位数

	for (int i = 0; i < len; i++)
	{
		if (isdigit(expr[i]) || expr[i] == '.')//属于数字字符或小数点
		{
			if (expr[i] == '.')//为小数点
			{
				Float = true;
				continue;
			}

			if (indigit == true)//属于一个数字中
			{
				double temp = sign.top();//将栈顶字符取出，以便后续与该expr[i]字符合并
				sign.pop();

				if (Float == true)//小数点存在,且为真
				{
					Float_size++;//小数点位数加一
					sign.push(temp + double((expr[i] - '0')) / pow(10, Float_size));//对小数后进行计算
				}
				else
					sign.push(temp * 10 + (expr[i] - '0'));//对小数点前进行计算
			}
			else//不属于一个数字中
			{
				sign.push(expr[i] - '0');
				indigit = true;//第一个数字字符起点
			}
		}
		else//属于运算符
		{
			indigit = false;//重置为不属于一个数字中
			if (expr[i] == ' ')//如果是空格，代表该浮点数读取已经完成
			{
				Float = false;
				Float_size = 0;
				continue;
			}

			//取出两个运算对象进行运算
			double a = sign.top();	sign.pop();
			double b = sign.top();  sign.pop();

			switch (expr[i])
			{
				case '+':sign.push(b + a); break;
				case '-':sign.push(b - a); break;
				case '*':sign.push(b * a); break;
				case '/':sign.push(b / a); break;
				case '%':sign.push(int(b) % int(a)); break;
			}
		}
	}

	return sign.top();
}