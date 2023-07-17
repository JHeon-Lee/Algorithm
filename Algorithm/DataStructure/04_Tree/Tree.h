#pragma once
// binary tree
// Template���ε� ������

void DoBinaryTree();

struct BinaryTreeNode
{
	BinaryTreeNode(DataType Data)
		: Data(Data), LeftChild(nullptr), RightChild(nullptr) {}

	DataType Data;
	BinaryTreeNode* LeftChild;
	BinaryTreeNode* RightChild;
};

class BinaryTree
{
public:
	BinaryTree() : Root(nullptr) {}
	~BinaryTree();

	void Insert(DataType data);	// ������ ����
	void Remove(DataType data);	// ������ ����

	void PreOrder();	// ���� ��ȸ
	void InOrder();		// ���� ��ȸ
	void PostOrder();	// ���� ��ȸ

	void Print();	// �������� ���

private:
	BinaryTreeNode* Remove(BinaryTreeNode* node, DataType data); // ��� ���� �� ��ȯ
	BinaryTreeNode* RemoveNode(BinaryTreeNode* node); // ��� ���� �� �ڽĳ�� ��ġ
	BinaryTreeNode* FindMin(BinaryTreeNode* node); // �ּҰ� ã�� �Լ�

	void PreOrder(BinaryTreeNode* node); // ����Լ��� ����� ���� ��������
	void InOrder(BinaryTreeNode* node);
	void PostOrder(BinaryTreeNode* node);

	void DestroyTree(BinaryTreeNode* node); // ��ü ��� ����

	void Print(BinaryTreeNode* node, string indent, bool last);

private:
	BinaryTreeNode* Root;
};

/*
	Tree : Ʈ��
	-Ư¡
		1) ��Ʈ ��带 ������ ��� ���� �θ� ��尡 �ִ� ( ��Ʈ -> �������)
		2) �ϳ��� ��Ʈ ��带 ������
		3) ���� 0�� �̻��� �ڽ� ��带 ������
		4) ��ȯ ������ ������ �ʴ´�

	-����
		1) �������� ������ ǥ���� �� ������, �˻��� ����, ������ �����ϴ�
	
	-����
		1) �ұ����� Ʈ���� Ž�� �ð��� ��������
*/