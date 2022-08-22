#pragma once

using std::cout;
using std::endl;
bool isEmpty(SeqQueue *queue);
bool isFull(SeqQueue *queue);

//初始化
void init(SeqQueue * &queue)
{
	queue = new SeqQueue;
	queue->front = 0;
	queue->rear = 0;
}

//入队
void push(SeqQueue *queue, ElementType elem)
{
	if (isFull(queue))
		return;
	queue->data[queue->rear] = elem;
	queue->rear = (queue->rear + 1) % MAX_SIZE;
}

//出队
void pop(SeqQueue *queue)
{
	if (isEmpty(queue))
		return;
	queue->data[queue->front] = { 0,nullptr };
	queue->front = (queue->front + 1) % MAX_SIZE;
}

//返回队头元素
ElementType front(SeqQueue *queue)
{
	if (isEmpty(queue))
		return{ 0, "空" };
	return queue->data[queue->front];
}

//返回队尾元素
ElementType rear(SeqQueue *queue)
{
	if(isEmpty(queue))
		return{ 0, "空" };
	if(queue->rear == 0)
		return queue->data[MAX_SIZE-1];
	else
		return queue->data[queue->rear - 1];
}

//f返回队列元素个数
int getLength(SeqQueue* queue)
{
	if (isEmpty(queue))
		return 0;
	else
		return (queue->rear - queue->front + MAX_SIZE) % MAX_SIZE;
}

//判断是否为空
bool isEmpty(SeqQueue *queue)
{
	if (queue == nullptr)
	{
		cout << "队列未创建" << endl;
		return true;
	}
	if (queue->front == queue->rear)
	{
		cout << "队列为空" << endl;
		return true;
	}
	return false;
}

//判断是否已满
bool isFull(SeqQueue *queue)
{
	if (queue == nullptr)
	{
		cout << "队列未创建" << endl;
		return 0;
	}
	if ((queue->rear + 1) % MAX_SIZE == queue->front)
	{
		cout << "队列已满" << endl;
		return true;
	}
	return false;
}

//显示到屏幕上
void show(SeqQueue *queue)
{
	cout << "队列中存有：" << getLength(queue) << " 个元素" << endl;
	if (isEmpty(queue))
		return;
	for (int i = queue->front; i != queue->rear; i = (i + 1) % MAX_SIZE)
		cout << "id:" << queue->data[i].id << "\tname:" << queue->data[i].name << endl;
}

//销毁队列
void clear(SeqQueue * &queue)
{
	delete queue;
	queue = nullptr;
}