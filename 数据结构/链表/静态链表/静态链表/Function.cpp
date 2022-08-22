#include <iostream>
#include "ListFunction.h"
using namespace std;

//初始化静态链表
void init(StaticLinkList *list)
{
	for (int i = 0; i < MAX_SIZE; i++)
		list[i].cursor = i + 1;

	list[MAX_SIZE - 1].cursor = 0;
	list[MAX_SIZE - 2].cursor = 0;
}

//插入元素element到位置pos处
bool insert(StaticLinkList *list, ElementType elem, int pos)
{
	if (pos <= 0 || pos > getlen(list) + 1)//len + 1代表允许尾插法
	{
		cout << "插入位置不在范围内！" << endl;
		return 0;
	}

	if (!isfull(list))//当链表满时退出
		return 0;

	int curr = MAX_SIZE-1;//从头结点开始
	for (int i = 0; i < pos - 1; i++)//找到pos位置的前一个位置
		curr = list[curr].cursor;

	int noenode = list[0].cursor;//第一个空闲结点
	list[0].cursor = list[noenode].cursor;//更新备用链表表头
	
	list[noenode].data = elem;//存入数据
	
	list[noenode].cursor = list[curr].cursor;//指向当前节点的下一节点
	list[curr].cursor = noenode;

	return 1;
}

//删除在位置pos处的元素
bool deletelist(StaticLinkList *list, int pos)
{
	if (pos <= 0 || pos > getlen(list))
		return 0;
	//先找到该pos结点的前一个结点
	int curr = MAX_SIZE - 1;
	for (int i = 0; i < pos - 1; i++)
		curr = list[curr].cursor;

	int Free = list[curr].cursor;//待回收结点
	list[curr].cursor = list[Free].cursor;//pos的前缀结点指向pos的后缀结点

	//将pos结点回收，并放入备用链表之中
	int temp = list[0].cursor;
	list[0].cursor = Free;
	list[Free].cursor = temp;
	
	//该行代码可去除，无实际意义
	list[Free].data.id = 0, list[Free].data.name = "空空空";
	
	return 1;
}

//查找，给定位置，返回该位置元素
ElementType seek(StaticLinkList *list, int pos)
{
	int len = getlen(list);
	if (pos <= 0 || pos > len)
	{
		cout << "静态链表为空！" << endl;
		return{ -1, nullptr };
	}

	int curr = list[MAX_SIZE - 1].cursor;
	while (--pos)
		curr = list[curr].cursor;

	return list[curr].data;
}

//判断链表是否为空
bool isempty(StaticLinkList *list)
{
	if (getlen(list))
		return 0;
	else
		return 1;
}

//判断链表是否已满,并返回剩余空间
int isfull(StaticLinkList *list)
{
	if (getlen(list) == MAX_SIZE - 2)
	{
		cout << "链表已满！" << endl;
		return 0;
	}
		return MAX_SIZE - 2 - getlen(list);
}

//返回静态链表长度
int getlen(StaticLinkList *list)
{
	int length = 0;
	int curr = list[MAX_SIZE - 1].cursor;

	while (curr)//如果是空表，那么起点是0，如果是非空表，那么终点是0
	{
		curr = list[curr].cursor;
		length++;
	}

	return length;
}

//显示链表物理地址
void showStore(StaticLinkList *list)
{
	int len = getlen(list);
	for (int i = 0; i <MAX_SIZE; i++)
		printf("index:%d\tid:%d\tdata:%s\tcursor:%d\n", 
			i, list[i].data.id, list[i].data.name, list[i].cursor);
}

//显示链表到屏幕
void show(StaticLinkList *list)
{
	if (isempty(list))
		return;
	
	int curr = list[MAX_SIZE - 1].cursor;
	while (curr)
	{
		cout << "id:" << list[curr].data.id << "\tname:" << list[curr].data.name << endl;
		curr = list[curr].cursor;
	}
}