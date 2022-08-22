#include <iostream>
#include <string>
#include "ElementType.h"
#include "Function.h"

int main()
{
	using namespace std;
	string Str;
	cout << "请输入需要存储在串中的字符串:" << endl;
	
	//getline(cin, Str);

	char n;
	while ((n = getchar()) != '#')//结束条件为输入#字符
		Str.push_back(n);//在string对象的结尾插入字符

	LinkStr *linkstr = new LinkStr;
	linkstr->next = nullptr;
	linkstr->length = 0;

	init(Str, linkstr);

	cout << "\n输出链串：" << endl;
	show(linkstr);

	cout << "\n输出链串的物理存储结构：" << endl;
	show_phy(linkstr);
	return 0;
}