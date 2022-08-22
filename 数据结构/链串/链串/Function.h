#pragma once
#include <iostream>
#include <string>
#include "ElementType.h"
using namespace std;

void init(string Str, LinkStr *linkstr)
{
	strNode *curr = nullptr;
	for (size_t i = 0; i < Str.size(); i++)
	{
		if (i%strNodeLen == 0)
		{
			strNode *newnode = new strNode;
			newnode->next = nullptr;
			if (linkstr->next == nullptr)
			{
				linkstr->next = newnode;
				curr = linkstr->next;
			}
			else
			{
				curr->next = newnode;
				curr = curr->next;
			}
		}
		curr->str[i%strNodeLen] = Str[i];
		linkstr->length++;
	}
}

//输出链串
void show(LinkStr *linkstr)
{
	strNode *curr = linkstr->next;
	for (int i = 0; i < linkstr->length; i++)
	{
		if (i != 0 && i%strNodeLen == 0)
			curr = curr->next;

		cout << curr->str[i%strNodeLen];
	}
	cout << endl;
}

//输出链串物理存储结构
void show_phy(LinkStr *linkstr)
{
	strNode *curr = linkstr->next;
	for (int i = 0; i < linkstr->length; i++)
	{
		if (i != 0 && i%strNodeLen == 0)
		{
			curr = curr->next;
			cout << endl;
		}

		cout << curr->str[i%strNodeLen];
	}
	cout << endl;
}