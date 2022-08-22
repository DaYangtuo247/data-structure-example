#include <iostream>
#include "ListFunction.h"
using namespace std;

//��ʼ����̬����
void init(StaticLinkList *list)
{
	for (int i = 0; i < MAX_SIZE; i++)
		list[i].cursor = i + 1;

	list[MAX_SIZE - 1].cursor = 0;
	list[MAX_SIZE - 2].cursor = 0;
}

//����Ԫ��element��λ��pos��
bool insert(StaticLinkList *list, ElementType elem, int pos)
{
	if (pos <= 0 || pos > getlen(list) + 1)//len + 1��������β�巨
	{
		cout << "����λ�ò��ڷ�Χ�ڣ�" << endl;
		return 0;
	}

	if (!isfull(list))//��������ʱ�˳�
		return 0;

	int curr = MAX_SIZE-1;//��ͷ��㿪ʼ
	for (int i = 0; i < pos - 1; i++)//�ҵ�posλ�õ�ǰһ��λ��
		curr = list[curr].cursor;

	int noenode = list[0].cursor;//��һ�����н��
	list[0].cursor = list[noenode].cursor;//���±��������ͷ
	
	list[noenode].data = elem;//��������
	
	list[noenode].cursor = list[curr].cursor;//ָ��ǰ�ڵ����һ�ڵ�
	list[curr].cursor = noenode;

	return 1;
}

//ɾ����λ��pos����Ԫ��
bool deletelist(StaticLinkList *list, int pos)
{
	if (pos <= 0 || pos > getlen(list))
		return 0;
	//���ҵ���pos����ǰһ�����
	int curr = MAX_SIZE - 1;
	for (int i = 0; i < pos - 1; i++)
		curr = list[curr].cursor;

	int Free = list[curr].cursor;//�����ս��
	list[curr].cursor = list[Free].cursor;//pos��ǰ׺���ָ��pos�ĺ�׺���

	//��pos�����գ������뱸������֮��
	int temp = list[0].cursor;
	list[0].cursor = Free;
	list[Free].cursor = temp;
	
	//���д����ȥ������ʵ������
	list[Free].data.id = 0, list[Free].data.name = "�տտ�";
	
	return 1;
}

//���ң�����λ�ã����ظ�λ��Ԫ��
ElementType seek(StaticLinkList *list, int pos)
{
	int len = getlen(list);
	if (pos <= 0 || pos > len)
	{
		cout << "��̬����Ϊ�գ�" << endl;
		return{ -1, nullptr };
	}

	int curr = list[MAX_SIZE - 1].cursor;
	while (--pos)
		curr = list[curr].cursor;

	return list[curr].data;
}

//�ж������Ƿ�Ϊ��
bool isempty(StaticLinkList *list)
{
	if (getlen(list))
		return 0;
	else
		return 1;
}

//�ж������Ƿ�����,������ʣ��ռ�
int isfull(StaticLinkList *list)
{
	if (getlen(list) == MAX_SIZE - 2)
	{
		cout << "����������" << endl;
		return 0;
	}
		return MAX_SIZE - 2 - getlen(list);
}

//���ؾ�̬������
int getlen(StaticLinkList *list)
{
	int length = 0;
	int curr = list[MAX_SIZE - 1].cursor;

	while (curr)//����ǿձ���ô�����0������Ƿǿձ���ô�յ���0
	{
		curr = list[curr].cursor;
		length++;
	}

	return length;
}

//��ʾ���������ַ
void showStore(StaticLinkList *list)
{
	int len = getlen(list);
	for (int i = 0; i <MAX_SIZE; i++)
		printf("index:%d\tid:%d\tdata:%s\tcursor:%d\n", 
			i, list[i].data.id, list[i].data.name, list[i].cursor);
}

//��ʾ������Ļ
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