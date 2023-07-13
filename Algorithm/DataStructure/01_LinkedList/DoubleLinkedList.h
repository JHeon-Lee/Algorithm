#pragma once

void DoDoubleLinkedList();
void DLLPrint();

class DoubleLinkedList
{
public:
	static DoubleLinkedList* DoubleLinkedListCreate(DataType data);
	static void Insert(DoubleLinkedList* cur, DoubleLinkedList* newNode);
	static void InsertHead(DoubleLinkedList* newNode);
	static void Push(DoubleLinkedList* newNode);

	void Remove();
	static void RemoveAll();
	static void RemoveAll(const DoubleLinkedList* head);

	static void SetHead(DoubleLinkedList* node);
	static void SetTail(DoubleLinkedList* node);

	static const DoubleLinkedList* GetHead() { return Head; }
	static const DoubleLinkedList* GetTail() { return Tail; }

	void SetNext(DoubleLinkedList* next) { Next = next; }
	void SetPrev(DoubleLinkedList* prev) { Prev = prev; }
	void SetData(DataType data) { Data = data; }

	const DoubleLinkedList* GetNext() { return Next; }
	const DoubleLinkedList* GetPrev() { return Prev; }
	const DataType GetData() { return Data; }

	static DoubleLinkedList* GetNode(int index);
	static const int GetLength() { return Length; }

	static int GetNodeCount(int index);
	static int GetNodeReverseCount(int index);

private:
	DataType Data;
	DoubleLinkedList* Prev;
	DoubleLinkedList* Next;

	static int Length;
	static DoubleLinkedList* Head;
	static DoubleLinkedList* Tail;
};