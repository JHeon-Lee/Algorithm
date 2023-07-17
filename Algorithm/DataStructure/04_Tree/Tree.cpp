#include "stdafx.h"
#include "Tree.h"

void DoBinaryTree()
{
	BinaryTree tree;
	int arr[15];

	for (int& i : arr)
	{
		i = rand() % 100;
		cout << i << " ";
		tree.Insert(i);
	}

	cout << endll;

	cout << "Before Remove" << endl;
	tree.InOrder();

	tree.Remove(arr[rand() % 15]);

	cout << endl << "After Remove" << endl;
	tree.InOrder();

	cout << endll;
	tree.Print();

	return;
}

BinaryTree::~BinaryTree()
{
	DestroyTree(Root);
}

void BinaryTree::Insert(DataType data)
{
	// 새로운 노드 생성
	BinaryTreeNode* newNode = new BinaryTreeNode(data);

	if (Root == nullptr) // (!Root)
	{
		Root = newNode;
		return;
	}

	// 루트 노드부터 시작하여, 새 노드를 삽입할 위치를 찾음
	BinaryTreeNode* curNode = Root;
	while (true)
	{
		// 현재 노드보다 작은 값일 때
		if (data < curNode->Data)
		{
			// 왼쪽 자식 노드가 비어있으면
			if (!curNode->LeftChild)
			{
				curNode->LeftChild = newNode;
				return;
			}
			// 비어있지 않으면, 왼쪽 자식 노드를 현재 노드로 바꾸고 반복
			curNode = curNode->LeftChild;
		}
		// 현재 노드보다 큰 값일 때
		else
		{
			// 오른쪽 자식 노드가 비어있으면
			if (!curNode->RightChild)
			{
				curNode->RightChild = newNode;
				return;
			}
			curNode = curNode->RightChild;
		}
	}
}

void BinaryTree::Remove(DataType data)
{
	Root = Remove(Root, data);
}

void BinaryTree::PreOrder()
{
	PreOrder(Root);
	cout << endl;
}

void BinaryTree::InOrder()
{
	InOrder(Root);
	cout << endl;
}

void BinaryTree::PostOrder()
{
	PostOrder(Root);
	cout << endl;
}

void BinaryTree::Print()
{
	if (!Root)
		cout << "Empty Tree" << endl;
	else
		Print(Root, "", true);
}

BinaryTreeNode* BinaryTree::Remove(BinaryTreeNode* node, DataType data)
{
	if (!node) return nullptr;

	if (node->Data == data) return RemoveNode(node);
	else if (data < node->Data)
	{
		node->LeftChild = Remove(node->LeftChild, data);
		return node;
	}
	else
	{
		node->RightChild = Remove(node->RightChild, data);
		return node;
	}
}

BinaryTreeNode* BinaryTree::RemoveNode(BinaryTreeNode* node)
{
	if (!node->LeftChild && !node->RightChild)
	{
		delete node;
		return nullptr; // 부모 노드에서 해당 노드 연결을 끊기위함
	}
	
	else if (!node->LeftChild || !node->RightChild)
	{
		BinaryTreeNode* target = (node->LeftChild != nullptr) ? node->LeftChild : node->RightChild;
		delete node;
		return target;
	}
	else
	{
		// 삭제할 노드의 오른쪽 서브 트리에서 가장 작은 값을 가진 노드를 찾아서 target으로 설정
		BinaryTreeNode* target = FindMin(node->RightChild);
		// 삭제할 노드의 데이터를 찾은 노드의 데이터로 변경
		node->Data = target->Data;
		// 노드를 삭제하고, 삭제된 노드의 오른쪽 자식 노드와 연결
		node->RightChild = Remove(node->RightChild, target->Data);
		return node;
	}
}

BinaryTreeNode* BinaryTree::FindMin(BinaryTreeNode* node)
{
	while (node->LeftChild)
		node = node->LeftChild;

	return node;
}

// 전위 순회 (현재 노드 -> 왼쪽 -> 오른쪽 순서)
void BinaryTree::PreOrder(BinaryTreeNode* node)
{
	if (node)
	{
		cout << node->Data << " ";
		PreOrder(node->LeftChild);
		PreOrder(node->RightChild);
	}
}

// 중위 순회 (왼족 -> 현재 -> 오른쪽 순서)
void BinaryTree::InOrder(BinaryTreeNode* node)
{
	if (node)
	{
		InOrder(node->LeftChild);
		cout << node->Data << " ";
		InOrder(node->RightChild);
	}
}

// 후위 순회 (왼쪽 -> 오른쪽 -> 현재 순서)
void BinaryTree::PostOrder(BinaryTreeNode* node)
{
	if (node)
	{
		PostOrder(node->LeftChild);
		PostOrder(node->RightChild);
		cout << node->Data << " ";
	}
}

void BinaryTree::DestroyTree(BinaryTreeNode* node)
{
	if (node)
	{
		DestroyTree(node->LeftChild);
		DestroyTree(node->RightChild);
		delete node;
	}
}

void BinaryTree::Print(BinaryTreeNode* node, string indent, bool last)
{
	if (node == nullptr)
		return;
	//출력할 노드의 위치와, 마지막 노드인지 여부에 따라 출력할 문구 설정
		cout << indent;
	if (last)
	{
		// 마지막 노드인 경우 출력
			cout << "└─";
		// indent에 2칸 공백 추가
			indent += "  ";
	}
	else
	{
		// 마지막 노드가 아닌 경우 출력
			cout << "├─";
		// indent에 와 공백 추가
			indent += "| ";
	}
	// 현재 노드의 값을 출력
		cout << node->Data << endl;

	// 오른쪽 자식 노드를 방문하여 계층 구조를 출력
		Print(node->RightChild, indent, node->LeftChild == nullptr);
	// 왼쪽 자식 노드를 방문하여 계층 구조를 출력
		Print(node->LeftChild, indent, true);
}
