#include "stdafx.h"
#include "Heap.h"

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

	// 마지막 노드의 데이터를 루트 노드로 옮기고 크기를 줄인다
	Data[0] = Data[Size - 1];
	Size--;

	// 루트 노드를 기준으로 힙 구조를 유지하도록 HeapifyDown 함수 호출
	HeapifyDown(0);

	return RootData;
}

void Heap::clear()
{
}

void Heap::Print()
{
}

int Heap::GetParent(int index)
{
	return 0;
}

int Heap::GetLeftChild(int index)
{
	return 0;
}

int Heap::GetRightChild(int index)
{
	return 0;
}

void Heap::HeapifyUp(int index)
{
}

void Heap::HeapifyDown(int index)
{
}

void Heap::Print(int index, string indent, bool last)
{
}
