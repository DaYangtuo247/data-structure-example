#include <iostream>
#include <stack>
#define SIZE 10
using namespace std;
int count = 0;

//移动单个元素
void move(int n, stack<int>& A, stack<int>& C)
{
	::count++;
	C.push(A.top());
	A.pop();
}

//汉诺塔算法
void hanio(int n, stack<int>& A, stack<int>& B, stack<int>& C)
{
	if (n == 1)
		move(n, A, C);
	else
	{
		hanio(n - 1, A, C, B);//将n-1个移动到B，C做辅助
		move(n, A, C);//将n号移动到C
		hanio(n - 1, B, A, C);//将n-1个移动到C，A做辅助
	}
}


//输出到屏幕
void show(stack<int>temp)
{
	if (!temp.size())
	{
		cout << "该栈为空" << endl;
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

	cout << "移动次数：" << ::count;
	return 0;
}
