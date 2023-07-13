#include "stdafx.h"
#include "DoubleLinkedList.h"

int DoubleLinkedList::Length = 0;
DoubleLinkedList* DoubleLinkedList::Head = nullptr;
DoubleLinkedList* DoubleLinkedList::Tail = nullptr;

void DoDoubleLinkedList()
{
	DoubleLinkedList::Push(DoubleLinkedList::DoubleLinkedListCreate(10));

	for (int i = 0; i < 5; i++)
		DoubleLinkedList::Push(DoubleLinkedList::DoubleLinkedListCreate(i));

	DLLPrint();

	cout << endll;

	DoubleLinkedList* newNode = DoubleLinkedList::DoubleLinkedListCreate(15);
	DoubleLinkedList::Insert(DoubleLinkedList::GetNode(2), newNode);
	DoubleLinkedList* forNode = DoubleLinkedList::DoubleLinkedListCreate(20);
	DoubleLinkedList::InsertHead(forNode);

	DLLPrint();

	cout << endll;

	DoubleLinkedList::GetNode(3)->Remove();

	DLLPrint();

	cout << endll;

	DoubleLinkedList::RemoveAll();

	DLLPrint();
}

void DLLPrint()
{
	if (DoubleLinkedList::GetLength() <= 0)
	{
		cout << "List Is NULL" << endl;
		return;
	}

	for (int i = 0; i < DoubleLinkedList::GetLength(); i++)
		cout << "Index [ " << i << " ] " << DoubleLinkedList::GetNode(i)->GetData() << endl;
}

DoubleLinkedList* DoubleLinkedList::DoubleLinkedListCreate(DataType data)
{
	DoubleLinkedList* node = new DoubleLinkedList;

	node->Data = data;
	node->Prev = nullptr;
	node->Next = nullptr;

	return node;
}

void DoubleLinkedList::Insert(DoubleLinkedList* cur, DoubleLinkedList* newNode)
{
	newNode->Next = cur->Next;
	cur->Next = newNode;
	newNode->Next->Prev = newNode;
	newNode->Prev = cur;

	++Length;
}

void DoubleLinkedList::InsertHead(DoubleLinkedList* newNode)
{
	newNode->Next = Head;
	Head = newNode;
	newNode->Next->Prev = newNode;
	Tail->Next = Head;

	++Length;
}

void DoubleLinkedList::Push(DoubleLinkedList* newNode)
{
	if (Head == nullptr)
	{
		Head = newNode;
		Tail = newNode;
		newNode->Next = Tail;
		newNode->Prev = Tail;
	}
	else
	{
		Tail->Next = newNode;
		newNode->Prev = Tail;
		Tail = newNode;
		newNode->Next = Head;
	}

	++Length;
}

void DoubleLinkedList::Remove()
{
	if (this == Head)
	{
		if (this->Next)
		{
			Head = this->Next;
			Tail->Next = Head;
			Head->Prev = Tail;
		}

		delete this;
		return;
	}

	DoubleLinkedList* checker = Head;

	while (true)
	{
		if (checker->Next == this)
		{
			checker->Next = this->Next;
			this->Next->Prev = checker;

			delete this;
			break;
		}
		else
			checker = checker->Next;
	}

	--Length;
}

void DoubleLinkedList::RemoveAll()
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

void DoubleLinkedList::RemoveAll(const DoubleLinkedList* head)
{
	if (head->Next != Head)
		RemoveAll(head->Next);

	cout << head->Data << "\tData Remove Completed" << endl;
	delete head;
}

void DoubleLinkedList::SetHead(DoubleLinkedList* node)
{
	if (Head != nullptr)
	{
		node->Next = Head->Next;
		Tail->Next = node;
		Head->Next->Prev = node;
		node->Prev = Head->Prev;
		Head = node;
	}

	else
		InsertHead(node);
}

void DoubleLinkedList::SetTail(DoubleLinkedList* node)
{
	if (Tail != nullptr)
	{
		node->Next = Tail->Next;
		Tail->Prev->Next = node;
		Head->Prev = node;
		node->Prev = Tail->Prev;
		Tail = node;
	}

	else
		Push(node);
}

DoubleLinkedList* DoubleLinkedList::GetNode(int index)
{
	if (Head == nullptr)
		return nullptr;

	DoubleLinkedList* find = Head;

	while (find != nullptr && --index >= 0)
		find = find->Next;

	return find;
}

int DoubleLinkedList::GetNodeCount(int index)
{
	DoubleLinkedList* cur = GetNode(index);

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

int DoubleLinkedList::GetNodeReverseCount(int index)
{
	DoubleLinkedList* cur = GetNode(index);

	if (cur == nullptr)
		return -1;

	int count = 1;
	while (cur->Prev != nullptr)
	{
		cur = cur->Prev;
		++count;
	}

	return count;
}
