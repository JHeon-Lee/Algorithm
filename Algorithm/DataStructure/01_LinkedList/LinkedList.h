#pragma once

void DoLinkedList();
void Print();

class LinkedListNode
{
public:
	static LinkedListNode* Create(DataType data);

	static void Insert(LinkedListNode* cur, LinkedListNode* newNode);

	void InsertHead();
	void Push();

	void Remove();
	static void RemoveAll();

	static LinkedListNode* GetNode(int index);
	const DataType GetData() { return Data;}

	static const int GetLength() { return Length; }
	
	static int GetNodeCount(int index);

	static const LinkedListNode* GetHead() { return Head; }
	static const LinkedListNode* GetTail() { return Tail; }

private:
	static void RemoveAll(const LinkedListNode* head);

private:
	DataType Data;
	LinkedListNode* Next;

	static int Length;
	static LinkedListNode* Head;
	static LinkedListNode* Tail;
};

/*
	LinkedList : 연결 리스트
	
	특징
	1) 노드와 포인터로 이루어진 선형 자료구조.
	2) 노드는 데이터와 다음 노드를 가리키는 포인터로 구성.
	3) 크기가 가변적이므로 동적 메모리 할당과 함께 사용되기도 한다.

	장점
	1) 삽입, 삭제가 용이하며, 데이터의 크기가 가변적일 경우 유용하다.
	2) 데이터를 읽는 것보다 데이터를 추가, 삭제하는데 빠르다.

	단점
	1) 데이터를 찾는 데 걸리는 시간이 선형적으로 증가하기 때문에 탐색속도가 느리다.
	2) 중간에 있는 노드를 삭제하려면 메모리 낭비가 발생할 수 있다.
*/