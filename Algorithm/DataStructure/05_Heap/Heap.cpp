#include "stdafx.h"
#include "Heap.h"

void DoHeap()
{
	Heap h(10);
	cout << "Insert Heap" << endl;
	for (int i = 0; i < 10; i++)
		h.Insert(rand() % 100);

	h.Print();

	cout << endll << "Array" << endl;
	for (int i = 0; i < 10; i++)
		cout << "Data [ " << i << " ]  " << h.GetData(i) << endl;
	
	cout << "Pop Heap" << endl;
	for (int i = 0; i < 10; i++)
		cout << h.Pop() << " ";
}

Heap::Heap(int maxSize)
	: MaxSize(maxSize)
{
	Data = new DataType[maxSize];
	Size = 0;
}

Heap::~Heap()
{
	delete[] Data;
}

void Heap::Insert(DataType data)
{
	if (IsFull())
		return;

	Data[Size] = data;
	HeapifyUp(Size);
	Size++;
}

DataType Heap::Pop()
{
	if (IsEmpty())
		return -1;

	cout << endl;
	Print();
	cout << endl;

	DataType RootData = Data[0];

	// ������ ����� �����͸� ��Ʈ ���� �ű�� ũ�⸦ ���δ�
	Data[0] = Data[Size - 1];
	Size--;

	// ��Ʈ ��带 �������� �� ������ �����ϵ��� HeapifyDown �Լ� ȣ��
	HeapifyDown(0);

	return RootData;
}

void Heap::clear()
{
	delete[] Data;
	Data = new DataType[MaxSize];
	Size = 0;
}

void Heap::Print()
{
	Print(0, "", true);
}

int Heap::GetParent(int index)
{
	return (index - 1) / 2;
}

int Heap::GetLeftChild(int index)
{
	return index * 2 + 1;
}

int Heap::GetRightChild(int index)
{
	return index * 2 + 2;
}

// ���ο� ���Ҹ� �����ϰų� ���� ���Ҹ� ������ ��
// �� ������ �����ϵ��� �θ� ���� �ڽ� ��带 ���Ͽ� ��ȯ�ϴ� �Լ�
void Heap::HeapifyUp(int index)
{
	int parentIndex = GetParent(index);

	if (index > 0 && Data[index] > Data[parentIndex])
	{
		swap(Data[index], Data[parentIndex]);
		// �θ� ���� ���� ��尡 ��ȯ�Ǿ����Ƿ�, �θ� ��带 ��������
		// HeapifyUp �Լ��� �ٽ� ȣ��
		HeapifyUp(parentIndex);
	}
}

// ��Ʈ ��带 ������ ��, ������ ��带 ��Ʈ ���� �ű� ��
// �ڽ� ���� ���Ͽ� ��ȯ�ϸ鼭 �� ������ �����ϵ��� �ϴ� �Լ�
void Heap::HeapifyDown(int index)
{
	int left = GetLeftChild(index);
	int right = GetRightChild(index);

	int largestIndex = index;

	if (left < Size && Data[left] > Data[largestIndex])
		largestIndex = left;

	if (right<Size && Data[right] > Data[largestIndex])
		largestIndex = right;

	// ���� ū �ε����� ���� ���� �ٸ� ���
	// ��, �ڽ� ��� �� �ϳ��� �� ū ���
	if (largestIndex != index)
	{
		swap(Data[index], Data[largestIndex]);
		HeapifyDown(largestIndex);
	}
}

void Heap::Print(int index, string indent, bool last)
{
	// ����� ����� ��ġ��, ������ ������� ���ο� ���� ����� ���� ����
	cout << indent;
	if (last)
	{
		// ������ ����� ��� ���
		cout << "���� ";
		// indent�� 2ĭ ���� �߰�
		indent += "  ";
	}
	else
	{
		// ������ ��尡 �ƴ� ��� ���
		cout << "���� ";
		// indent�� |�� ���� �߰�"
		indent += "| ";
	}

	// ���� ����� ���� ���
	cout << Data[index] << endl;

	// ������ �ڽ� ��带 �湮�Ͽ� ���� ������ ���
	if (2 * index + 2 < Size)
	{
		bool lastRight = false;
		if (2 * index + 1 >= Size)
			lastRight = true;
		Print(2 * index + 2, indent + (last ? "  " : "| "), lastRight);
	}

	// ���� �ڽ� ��带 �湮�Ͽ� ���� ������ ���
	if (2 * index + 1 < Size)
	{
		Print(2 * index + 1, indent + (last ? "  " : "| "), true);
	}
}
