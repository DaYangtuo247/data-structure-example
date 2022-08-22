#include <iostream>
#include <stack>
#define SIZE 10
using namespace std;
int count = 0;

//�ƶ�����Ԫ��
void move(int n, stack<int>& A, stack<int>& C)
{
	::count++;
	C.push(A.top());
	A.pop();
}

//��ŵ���㷨
void hanio(int n, stack<int>& A, stack<int>& B, stack<int>& C)
{
	if (n == 1)
		move(n, A, C);
	else
	{
		hanio(n - 1, A, C, B);//��n-1���ƶ���B��C������
		move(n, A, C);//��n���ƶ���C
		hanio(n - 1, B, A, C);//��n-1���ƶ���C��A������
	}
}


//�������Ļ
void show(stack<int>temp)
{
	if (!temp.size())
	{
		cout << "��ջΪ��" << endl;
		return;
	}
	while (temp.size())
	{
		printf("%3d\n", temp.top());
		temp.pop();
	}
}

int main()
{
	stack<int>A, B, C;
	for (int i = SIZE; i > 0; i--)
		A.push(i);

	show(A);	show(B);	show(C);
	cout << endl << endl;

	hanio(SIZE, A, B, C);

	show(A);	show(B);	show(C);

	cout << "�ƶ�������" << ::count;
	return 0;
}
