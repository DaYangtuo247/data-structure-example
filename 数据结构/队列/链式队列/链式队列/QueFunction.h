#pragma once
#include "ElementType.h"

using std::cout;
using std::endl;
bool isempty(LinkQueue *queue);

//初始化
void init(LinkQueue* &queue)
{
	queue = new LinkQueue;
	queue->length = 0;
	queue->front = nullptr;
	queue->rear = nullptr;
}

//入队
void push(LinkQueue *queue, ElementType elem)
{
	LinkNode *newnode = new LinkNode;
	newnode->data = elem;
	newnode->next = nullptr;
	if (queue->front == nullptr)//入队的是第一个结点
	{
		queue->front = newnode;
		queue->rear = newnode;
	}
	else
		queue->rear->next = newnode;

	queue->rear = newnode;
	queue->length++;
}

//出队
void pop(LinkQueue *queue)
{
	if (isempty(queue))
		return;
	LinkNode *dele = queue->front;
	queue->front = queue->front->next;
	delete dele;
	queue->length--;
}

//返回队头元素且不删除
ElementType front(LinkQueue *queue)
{
	if(isempty(queue))
		return{ -1, "空" };
	return queue->front->data;
}

//返回队尾元素且不删除
ElementType rear(LinkQueue *queue)
{
	if (isempty(queue))
		return{-1, "空"};
	return queue->rear->data;
}

//返回队列长度
int getlen(LinkQueue *queue)
{
	return queue->length;
}

//判断是否为空
bool isempty(LinkQueue *queue)
{
	if (queue == nullptr)
	{
		cout << "队列未创建" << endl;
		return true;
	}
	return queue->length == 0;
}

//销毁队列
void clear(LinkQueue * &queue)
{
	if (queue->front != nullptr)
	{
		LinkNode *currnode = queue->front, *temp;
		while (currnode)
		{
			temp = currnode;
			currnode = currnode->next;
			delete temp;
		}
	}
	delete queue;
	queue = nullptr;
}

//输出到屏幕
void show(LinkQueue *queue)
{
	if (isempty(queue))
		return;

	LinkNode *curr = queue->front;
	for (int i = 0; i < queue->length; i++)
	{
		cout << "id:" << curr->data.id << "\tname:" << curr->data.name << endl;
		curr = curr->next;
	}
}