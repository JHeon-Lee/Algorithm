#pragma once

void DoQueue();

template<typename T>
class Queue
{
public:
	Queue()
		: Front(0), Rear(0), Size(0)
	{}

	bool IsEmpty() { return Size == 0; }
	bool IsFull() { return Size == MAX_SIZE; }
	
	int GetSize() { return Size; }

	void Enqueue(T data);
	void Dequeue();

	T GetFront();

private:
	int Front;
	int Rear;
	int Size;
	T Data[MAX_SIZE];
};

// ȯ�� ť ��� -> front, rear ���

/*
	Queue : ť
	-Ư¡
		1) ���Լ���(FIFO) ������ ������ �ڷᱸ��
		2) ������ Enqueue, ������ Dequeue ������ ���

	-����
		1) ������ ����
		2) �۾� ó�� ��⿭, �޽��� ���� ��� �����ϴ�

	-����
		1) ť�� ũ�Ⱑ �����Ǿ� ���� ��, ť�� ���� ���� �� �̻� �����͸� �߰��� �� ����
*/