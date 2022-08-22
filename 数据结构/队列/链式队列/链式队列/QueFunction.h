#pragma once
#include "ElementType.h"

using std::cout;
using std::endl;
bool isempty(LinkQueue *queue);

//��ʼ��
void init(LinkQueue* &queue)
{
	queue = new LinkQueue;
	queue->length = 0;
	queue->front = nullptr;
	queue->rear = nullptr;
}

//���
void push(LinkQueue *queue, ElementType elem)
{
	LinkNode *newnode = new LinkNode;
	newnode->data = elem;
	newnode->next = nullptr;
	if (queue->front == nullptr)//��ӵ��ǵ�һ�����
	{
		queue->front = newnode;
		queue->rear = newnode;
	}
	else
		queue->rear->next = newnode;

	queue->rear = newnode;
	queue->length++;
}

//����
void pop(LinkQueue *queue)
{
	if (isempty(queue))
		return;
	LinkNode *dele = queue->front;
	queue->front = queue->front->next;
	delete dele;
	queue->length--;
}

//���ض�ͷԪ���Ҳ�ɾ��
ElementType front(LinkQueue *queue)
{
	if(isempty(queue))
		return{ -1, "��" };
	return queue->front->data;
}

//���ض�βԪ���Ҳ�ɾ��
ElementType rear(LinkQueue *queue)
{
	if (isempty(queue))
		return{-1, "��"};
	return queue->rear->data;
}

//���ض��г���
int getlen(LinkQueue *queue)
{
	return queue->length;
}

//�ж��Ƿ�Ϊ��
bool isempty(LinkQueue *queue)
{
	if (queue == nullptr)
	{
		cout << "����δ����" << endl;
		return true;
	}
	return queue->length == 0;
}

//���ٶ���
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

//�������Ļ
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