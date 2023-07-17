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
	// ���ο� ��� ����
	BinaryTreeNode* newNode = new BinaryTreeNode(data);

	if (Root == nullptr) // (!Root)
	{
		Root = newNode;
		return;
	}

	// ��Ʈ ������ �����Ͽ�, �� ��带 ������ ��ġ�� ã��
	BinaryTreeNode* curNode = Root;
	while (true)
	{
		// ���� ��庸�� ���� ���� ��
		if (data < curNode->Data)
		{
			// ���� �ڽ� ��尡 ���������
			if (!curNode->LeftChild)
			{
				curNode->LeftChild = newNode;
				return;
			}
			// ������� ������, ���� �ڽ� ��带 ���� ���� �ٲٰ� �ݺ�
			curNode = curNode->LeftChild;
		}
		// ���� ��庸�� ū ���� ��
		else
		{
			// ������ �ڽ� ��尡 ���������
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
		return nullptr; // �θ� ��忡�� �ش� ��� ������ ��������
	}
	
	else if (!node->LeftChild || !node->RightChild)
	{
		BinaryTreeNode* target = (node->LeftChild != nullptr) ? node->LeftChild : node->RightChild;
		delete node;
		return target;
	}
	else
	{
		// ������ ����� ������ ���� Ʈ������ ���� ���� ���� ���� ��带 ã�Ƽ� target���� ����
		BinaryTreeNode* target = FindMin(node->RightChild);
		// ������ ����� �����͸� ã�� ����� �����ͷ� ����
		node->Data = target->Data;
		// ��带 �����ϰ�, ������ ����� ������ �ڽ� ���� ����
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

// ���� ��ȸ (���� ��� -> ���� -> ������ ����)
void BinaryTree::PreOrder(BinaryTreeNode* node)
{
	if (node)
	{
		cout << node->Data << " ";
		PreOrder(node->LeftChild);
		PreOrder(node->RightChild);
	}
}

// ���� ��ȸ (���� -> ���� -> ������ ����)
void BinaryTree::InOrder(BinaryTreeNode* node)
{
	if (node)
	{
		InOrder(node->LeftChild);
		cout << node->Data << " ";
		InOrder(node->RightChild);
	}
}

// ���� ��ȸ (���� -> ������ -> ���� ����)
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
	//����� ����� ��ġ��, ������ ������� ���ο� ���� ����� ���� ����
		cout << indent;
	if (last)
	{
		// ������ ����� ��� ���
			cout << "����";
		// indent�� 2ĭ ���� �߰�
			indent += "  ";
	}
	else
	{
		// ������ ��尡 �ƴ� ��� ���
			cout << "����";
		// indent�� �� ���� �߰�
			indent += "| ";
	}
	// ���� ����� ���� ���
		cout << node->Data << endl;

	// ������ �ڽ� ��带 �湮�Ͽ� ���� ������ ���
		Print(node->RightChild, indent, node->LeftChild == nullptr);
	// ���� �ڽ� ��带 �湮�Ͽ� ���� ������ ���
		Print(node->LeftChild, indent, true);
}
