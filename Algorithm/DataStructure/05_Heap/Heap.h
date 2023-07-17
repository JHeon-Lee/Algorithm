#pragma once

void DoHeap();

class Heap
{
public:
	Heap(int maxSize);
	~Heap();

	void Insert(DataType data);

	DataType Pop();
	void clear();

	bool IsEmpty() { return Size == 0; }
	bool IsFull() { return Size == MaxSize; }

	void Print();

	const DataType GetData(int index) { return Data[index]; }

private:
	int GetParent(int index);	// �θ� ����� �ε��� ����
	int GetLeftChild(int index);	// ���� �ڽ� �ε��� ����
	int GetRightChild(int index);	// ������ �ڽ� �ε��� ����

	void HeapifyUp(int index);	// ���� ����� ��迭
	void HeapifyDown(int index);	// ���� ����� ��迭
	
	void Print(int index, string indent, bool last);

private:
	DataType* Data;	// �����ϴ� �迭
	int MaxSize;	// �ִ� ũ��
	int Size;	// ���� ����� ����
};

/*
	Heap : ��
	- Ư¡
		1) ���� ���� Ʈ�� ����
		2) �θ� ���� �ڽ� ��� ���� ��Ұ��谡 ������ ���� ���� Ʈ�� ����
		3) ��Ʈ ���� �׻� �ּҰ� �Ǵ� �ִ밪�� ������
		4) �ּ� �� �Ǵ� �ִ� ���� �ִ�
			- �ּ� �� : �θ� ����� ���� �ڽ� ����� ������ ���� ���
			- �ִ� �� : �θ� ����� ���� �ڽ� ����� ������ ū ���

	- ����
		1) �ּҰ� �Ǵ� �ִ밪�� ��� �ð�(0(1))�� ã�� �� �ִ�
		2) ����, �켱���� ť ��� �����ϰ� ���ȴ�
		3) ���� Ž�� Ʈ������ �����ϰ� ������ ������ �� �ִ�.

	- ����
		1) �ߺ��� ���� ó���� ��ƴ�
		2) ����, ���� ���꿡 �ð� ���⵵�� 0(log n)�� �ҿ�ȴ�

	���� ���� Ʈ��(Complete Binary Tree)
	- Ư¡
		1) ��� ��尡 �� �� ����Ʈ��
		2) ������ ������ ������ ��� ������ �� ���־�� �Ѵ�
		3) ������ ������ ���ʺ��� ���ʴ�� ä������
		4) ��� ���� ���ʿ��� ���������� ä������ �Ѵ�

	- ����
		1) �迭�� ������ �� �����ϰ� ������ �� �ִ�
			- i ��° ����� ���� �ڽ� ��� = 2i ��° ���
			- i ��° ����� ������ �ڽ� ���  = 2i + 1 ��° ���
			- i ��° ����� �θ� ��� = i/2 ��° ���
		2) Ž�� �ð��� 0(log n)���� �ſ� ������
		3) ����� ������ ���� ���� ���⵵�� ����

	- ����
		1) ���԰� ������ ����� �̵��� ���Ƽ� �ð� ���⵵�� ����
*/