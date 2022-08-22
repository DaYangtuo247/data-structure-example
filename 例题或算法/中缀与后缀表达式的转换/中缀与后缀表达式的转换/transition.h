#pragma once
#include <iostream>
#include <cmath>//ʹ����pow����
#include <stack>
#include <queue>
using namespace std;

bool preOperator(char top, char s);//��������ȼ��ж�

//��׺���ʽת��׺���ʽ
void infix_suffix(char *expr, int len)
{
	stack<char>sign;//����ջ
	queue<char>suffix;//��������

	//��׺���ʽת��׺���ʽ�����
	for (int i = 0; i < len; i++)
	{
		if (isspace(expr[i]))//�����հ��ַ�
			continue;

		if (isdigit(expr[i]) || expr[i] == '.')//���������,ֱ�����
		{
			suffix.push(expr[i]);
			continue;
		}

		suffix.push(' ');
		if (expr[i] == ')')//�����������,���ջ���������Ϸ������������
		{
			while (sign.top() != '(')
			{
				suffix.push(sign.top());//����������
				sign.pop();//�Ƴ�ջ��Ԫ��
			}
			sign.pop();//ɾ��ջ����������
			continue;
		}

		if (expr[i] != '(' && sign.size() != 0)//�������ջǰҪ��֤ջ��Ϊ��,�ҷ�����
		{
			//��ǰ��������ȼ�  ���ڻ����  ջ���������ȼ�ȫ�����
			if (preOperator(sign.top(), expr[i]))
			{
				while (sign.size() && sign.top() != '(')
				{
					suffix.push(sign.top());//����������
					sign.pop();//�Ƴ�ջ��Ԫ��
				}
			}
		}
		sign.push(expr[i]);
	}

	while (sign.size())//��ջ�����������ȫ�����
	{
		suffix.push(sign.top());
		sign.pop();
	}

	//�����д�ŵ�ԭ����
	int eq_size = suffix.size();
	expr[eq_size] = '\0';
	for (int i = 0; i < eq_size; i++)
	{
		expr[i] = suffix.front();
		suffix.pop();
	}
}

//��������ȼ��ж�
bool preOperator(char top, char s)//��������ȼ��ж�
{
	char Oper[] = { '+', '-', '*', '/', '%'};
	int len = sizeof(Oper) / sizeof(Oper[0]);
	int indextop, indexs;
	for (int i = 0; i < len; i++)//�ҵ��÷�����������е�λ��
		if (Oper[i] == s)
			indexs = i;
		else if (Oper[i] == top)
			indextop = i;

	if (indexs < 2 && indextop > 1)//��ǰ��������ȼ�����ջ��
		return 1;
	else if ((indexs < 2 && indextop < 2) || (indexs > 1 && indextop > 1))//ͬ�������
		return 1;

	return 0;
}

//���ؼ�����
double result(char *expr, int len)
{
	stack<double>sign;//����ջ
	bool indigit = false;//�����ж��ַ��Ƿ���һ��������
	bool Float = false;//��¼��������С�����Ƿ����
	int Float_size = 0;//��¼ÿһ��������С������λ��

	for (int i = 0; i < len; i++)
	{
		if (isdigit(expr[i]) || expr[i] == '.')//���������ַ���С����
		{
			if (expr[i] == '.')//ΪС����
			{
				Float = true;
				continue;
			}

			if (indigit == true)//����һ��������
			{
				double temp = sign.top();//��ջ���ַ�ȡ�����Ա�������expr[i]�ַ��ϲ�
				sign.pop();

				if (Float == true)//С�������,��Ϊ��
				{
					Float_size++;//С����λ����һ
					sign.push(temp + double((expr[i] - '0')) / pow(10, Float_size));//��С������м���
				}
				else
					sign.push(temp * 10 + (expr[i] - '0'));//��С����ǰ���м���
			}
			else//������һ��������
			{
				sign.push(expr[i] - '0');
				indigit = true;//��һ�������ַ����
			}
		}
		else//���������
		{
			indigit = false;//����Ϊ������һ��������
			if (expr[i] == ' ')//����ǿո񣬴���ø�������ȡ�Ѿ����
			{
				Float = false;
				Float_size = 0;
				continue;
			}

			//ȡ��������������������
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