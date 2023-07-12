#pragma once

void DoDoubleLinkedList();
void Print();

class DoubleLinkedList
{
public:
	static DoubleLinkedList* Create(DataType data);

	static void Insert(DoubleLinkedList* cur, DoubleLinkedList* newNode);

	void InsertHead();
	void Push();

	void Remove();
	static void RemoveAll();

	static DoubleLinkedList* GetNode(int index);
	const DataType GetData() { return Data; }

	static const int GetLength() { return Length; }

	static int GetNodeCount(int index);

	static const DoubleLinkedList* GetHead() { return Head; }
	static const DoubleLinkedList* GetTail() { return Tail; }

private:
	static void RemoveAll(const DoubleLinkedList* head);

private:
	DataType Data;
	DoubleLinkedList* Prev;
	DoubleLinkedList* Next;

	static int Length;
	static DoubleLinkedList* Head;
	static DoubleLinkedList* Tail;
};