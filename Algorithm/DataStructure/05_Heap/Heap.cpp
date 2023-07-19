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

	// 마지막 노드의 데이터를 루트 노드로 옮기고 크기를 줄인다
	Data[0] = Data[Size - 1];
	Size--;

	// 루트 노드를 기준으로 힙 구조를 유지하도록 HeapifyDown 함수 호출
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

// 새로운 원소를 삽입하거나 기존 원소를 수정한 후
// 힙 조건을 만족하도록 부모 노드와 자식 노드를 비교하여 교환하는 함수
void Heap::HeapifyUp(int index)
{
	int parentIndex = GetParent(index);

	if (index > 0 && Data[index] > Data[parentIndex])
	{
		swap(Data[index], Data[parentIndex]);
		// 부모 노드와 현재 노드가 교환되었으므로, 부모 노드를 기준으로
		// HeapifyUp 함수를 다시 호출
		HeapifyUp(parentIndex);
	}
}

// 루트 노드를 제거한 후, 마지막 노드를 루트 노드로 옮긴 후
// 자식 노드와 비교하여 교환하면서 힙 조건을 만족하도록 하는 함수
void Heap::HeapifyDown(int index)
{
	int left = GetLeftChild(index);
	int right = GetRightChild(index);

	int largestIndex = index;

	if (left < Size && Data[left] > Data[largestIndex])
		largestIndex = left;

	if (right<Size && Data[right] > Data[largestIndex])
		largestIndex = right;

	// 제일 큰 인덱스가 현재 노드와 다른 경우
	// 즉, 자식 노드 중 하나가 더 큰 경우
	if (largestIndex != index)
	{
		swap(Data[index], Data[largestIndex]);
		HeapifyDown(largestIndex);
	}
}

void Heap::Print(int index, string indent, bool last)
{
	// 출력할 노드의 위치와, 마지막 노드인지 여부에 따라 출력할 문구 설정
	cout << indent;
	if (last)
	{
		// 마지막 노드인 경우 출력
		cout << "└─ ";
		// indent에 2칸 공백 추가
		indent += "  ";
	}
	else
	{
		// 마지막 노드가 아닌 경우 출력
		cout << "├─ ";
		// indent에 |와 공백 추가"
		indent += "| ";
	}

	// 현재 노드의 값을 출력
	cout << Data[index] << endl;

	// 오른쪽 자식 노드를 방문하여 계층 구조를 출력
	if (2 * index + 2 < Size)
	{
		bool lastRight = false;
		if (2 * index + 1 >= Size)
			lastRight = true;
		Print(2 * index + 2, indent + (last ? "  " : "| "), lastRight);
	}

	// 왼쪽 자식 노드를 방문하여 계층 구조를 출력
	if (2 * index + 1 < Size)
	{
		Print(2 * index + 1, indent + (last ? "  " : "| "), true);
	}
}
