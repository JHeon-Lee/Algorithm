#pragma once
// binary tree
// Template으로도 만들어보기

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

	void Insert(DataType data);	// 데이터 삽입
	void Remove(DataType data);	// 데이터 삭제

	void PreOrder();	// 전위 순회
	void InOrder();		// 중위 순회
	void PostOrder();	// 후위 순회

	void Print();	// 계층구조 출력

private:
	BinaryTreeNode* Remove(BinaryTreeNode* node, DataType data); // 노드 삭제 및 반환
	BinaryTreeNode* RemoveNode(BinaryTreeNode* node); // 노드 삭제 후 자식노드 배치
	BinaryTreeNode* FindMin(BinaryTreeNode* node); // 최소값 찾는 함수

	void PreOrder(BinaryTreeNode* node); // 재귀함수로 만들기 위해 만들어놓음
	void InOrder(BinaryTreeNode* node);
	void PostOrder(BinaryTreeNode* node);

	void DestroyTree(BinaryTreeNode* node); // 전체 노드 삭제

	void Print(BinaryTreeNode* node, string indent, bool last);

private:
	BinaryTreeNode* Root;
};

/*
	Tree : 트리
	-특징
		1) 루트 노드를 제외한 모든 노드는 부모 노드가 있다 ( 루트 -> 리프노드)
		2) 하나의 루트 노드를 가진다
		3) 노드는 0개 이상의 자식 노드를 가진다
		4) 순환 구조를 가지지 않는다

	-장점
		1) 계층적인 구조를 표현할 수 있으며, 검색과 삽입, 삭제가 용이하다
	
	-단점
		1) 불균형한 트리는 탐색 시간이 느려진다
*/