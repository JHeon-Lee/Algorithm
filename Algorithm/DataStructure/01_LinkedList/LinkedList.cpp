// 상대경로 설정 대신 프로젝트 우클릭 설정 -> vc++ 디렉터리 -> 포함 디렉터리 -> 편집 -> 프로젝트 디렉터리 추가
#include "stdafx.h"
#include "LinkedList.h"

int LinkedListNode::Length = 0;
LinkedListNode* LinkedListNode::Head = nullptr;
LinkedListNode* LinkedListNode::Tail = nullptr;

void DoLinkedList()
{
	LinkedListNode::Create(10)->Push();

	for (int i = 0; i < 5; i++)
		LinkedListNode::Create(i)->Push();

	Print();

	cout << endll;

	LinkedListNode* newNode = LinkedListNode::Create(15);
	LinkedListNode::Insert(LinkedListNode::GetNode(2), newNode);
	LinkedListNode* forNode = LinkedListNode::Create(20);
	forNode->InsertHead();

	Print();

	cout << endll;

	LinkedListNode::GetNode(3)->Remove();

	Print();

	cout << endll;

	LinkedListNode::RemoveAll();
	
	Print();
}

void Print()
{
	if (LinkedListNode::GetLength() <= 0)
	{
		cout << "List Is NULL" << endl;
		return;
	}

	for (int i = 0; i < LinkedListNode::GetLength(); i++)
		cout << "Index [ " << i << " ] " << LinkedListNode::GetNode(i)->GetData() << endl;
}

LinkedListNode* LinkedListNode::Create(DataType data)
{
	LinkedListNode* node = new LinkedListNode;

	node->Data = data;
	node->Next = nullptr;

	return node;
}

void LinkedListNode::Insert(LinkedListNode* cur, LinkedListNode* newNode)
{
	newNode->Next = cur->Next;
	cur->Next = newNode;

	++Length;
}

void LinkedListNode::InsertHead()
{
	this->Next = Head;
	Head = this;

	++Length;
}

void LinkedListNode::Push()
{
	if (Head == nullptr)
	{
		Head = this;
		Tail = this;
	}
	else
	{
		Tail->Next = this;
		Tail = this;
	}

	++Length;
}

void LinkedListNode::Remove()
{
	if (this == Head)
	{
		if (this->Next)
			Head = this->Next;

		delete this;
		return;
	}

	LinkedListNode* checker = Head;

	while (true)
	{
		if (checker->Next == this)
		{
			checker->Next = this->Next;
			delete this;
			break;
		}
		else
			checker = checker->Next;
	}

	--Length;
}

void LinkedListNode::RemoveAll()
{
	Length = 0;

	if (Head == nullptr)
	{
		cout << "List is already NULL" << endl;
		return;
	}

	if (Head->Next != nullptr)
		RemoveAll(Head->Next);

	cout << Head->Data << "\tData Remove Completed" << endl;
	delete Head;

	Head = nullptr;
	Tail = nullptr;
}

void LinkedListNode::RemoveAll(const LinkedListNode* head)
{
	if (head->Next != nullptr)
		RemoveAll(head->Next);

	cout << head->Data << "\tData Remove Completed" << endl;
	delete head;
}

LinkedListNode* LinkedListNode::GetNode(int index)
{
	if (Head == nullptr)
		return nullptr;
	
	LinkedListNode* find = Head;

	while (find != nullptr && --index >= 0)
		find = find->Next;

	return find;
}

int LinkedListNode::GetNodeCount(int index)
{
	LinkedListNode* cur = GetNode(index);

	if (cur == nullptr)
		return -1;

	int count = 1;
	while (cur->Next != nullptr)
	{
		cur = cur->Next;
		++count;
	}

	return count;
}
