#include <iostream>
#include "transition.h"
#define SIZE 100
/*
�����飺�ü������ɼ����+, -, *, /, %, ()�Ļ�������,ͬʱ���Զ��������
���磬���������PΪ����a��b�η�������aPb�����ɼ���a��b�η�

�Զ��巽�����޸�infix_suffix()��������ȼ��ж�λ���Լ�result��case��ǩλ��
*/
int main()
{
	using namespace std;
	char expr[SIZE];
	cout << "���������ʽ:";	
	cin.getline(expr, SIZE);

	infix_suffix(expr, strlen(expr));

	cout << "ת��Ϊ��׺���ʽ��";
	for (int i = 0; expr[i] != '\0'; i++)
		cout << expr[i];

	cout << "\n�ɺ�׺���ʽ������Ľ����" << result(expr, strlen(expr)) << endl;
	return 0;
}