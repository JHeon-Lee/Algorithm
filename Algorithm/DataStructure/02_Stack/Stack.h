#pragma once

void DoStack();

template<typename T>
class Stack
{
public:
	Stack();

	bool IsEmpty() { return Top == -1; }
	bool IsFull() { return Top == MAX_SIZE; }

	void Push(T data);

	T Pop();
	T Peek();

private:
	int Top;
	T Data[MAX_SIZE];
};

/*
	Stack : ����
	- Ư¡
		1) ���Լ���(LIFO) ������ ������ �ڷᱸ��
		2) ������ Push, ������ Pop ������ ���

	- ����
		1) ������ �����ϴ�
		2) �Լ� ȣ���� ������, ���� ���, ���ڿ� ���� ��� �����ϴ�

	- ����
		1) �߰��� ���ҿ� �����ϱ� ��ƴ�
*/
