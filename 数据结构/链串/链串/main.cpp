#include <iostream>
#include <string>
#include "ElementType.h"
#include "Function.h"

int main()
{
	using namespace std;
	string Str;
	cout << "��������Ҫ�洢�ڴ��е��ַ���:" << endl;
	
	//getline(cin, Str);

	char n;
	while ((n = getchar()) != '#')//��������Ϊ����#�ַ�
		Str.push_back(n);//��string����Ľ�β�����ַ�

	LinkStr *linkstr = new LinkStr;
	linkstr->next = nullptr;
	linkstr->length = 0;

	init(Str, linkstr);

	cout << "\n���������" << endl;
	show(linkstr);

	cout << "\n�������������洢�ṹ��" << endl;
	show_phy(linkstr);
	return 0;
}