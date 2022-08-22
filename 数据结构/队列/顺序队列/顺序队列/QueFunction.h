#pragma once

using std::cout;
using std::endl;
bool isEmpty(SeqQueue *queue);
bool isFull(SeqQueue *queue);

//��ʼ��
void init(SeqQueue * &queue)
{
	queue = new SeqQueue;
	queue->front = 0;
	queue->rear = 0;
}

//���
void push(SeqQueue *queue, ElementType elem)
{
	if (isFull(queue))
		return;
	queue->data[queue->rear] = elem;
	queue->rear = (queue->rear + 1) % MAX_SIZE;
}

//����
void pop(SeqQueue *queue)
{
	if (isEmpty(queue))
		return;
	queue->data[queue->front] = { 0,nullptr };
	queue->front = (queue->front + 1) % MAX_SIZE;
}

//���ض�ͷԪ��
ElementType front(SeqQueue *queue)
{
	if (isEmpty(queue))
		return{ 0, "��" };
	return queue->data[queue->front];
}

//���ض�βԪ��
ElementType rear(SeqQueue *queue)
{
	if(isEmpty(queue))
		return{ 0, "��" };
	if(queue->rear == 0)
		return queue->data[MAX_SIZE-1];
	else
		return queue->data[queue->rear - 1];
}

//f���ض���Ԫ�ظ���
int getLength(SeqQueue* queue)
{
	if (isEmpty(queue))
		return 0;
	else
		return (queue->rear - queue->front + MAX_SIZE) % MAX_SIZE;
}

//�ж��Ƿ�Ϊ��
bool isEmpty(SeqQueue *queue)
{
	if (queue == nullptr)
	{
		cout << "����δ����" << endl;
		return true;
	}
	if (queue->front == queue->rear)
	{
		cout << "����Ϊ��" << endl;
		return true;
	}
	return false;
}

//�ж��Ƿ�����
bool isFull(SeqQueue *queue)
{
	if (queue == nullptr)
	{
		cout << "����δ����" << endl;
		return 0;
	}
	if ((queue->rear + 1) % MAX_SIZE == queue->front)
	{
		cout << "��������" << endl;
		return true;
	}
	return false;
}

//��ʾ����Ļ��
void show(SeqQueue *queue)
{
	cout << "�����д��У�" << getLength(queue) << " ��Ԫ��" << endl;
	if (isEmpty(queue))
		return;
	for (int i = queue->front; i != queue->rear; i = (i + 1) % MAX_SIZE)
		cout << "id:" << queue->data[i].id << "\tname:" << queue->data[i].name << endl;
}

//���ٶ���
void clear(SeqQueue * &queue)
{
	delete queue;
	queue = nullptr;
}