#pragma once

void DoHeap();

class Heap
{
public:
	Heap(int maxSize);
	~Heap();

	void Insert(DataType data);

	DataType Pop();
	void clear();

	bool IsEmpty() { return Size == 0; }
	bool IsFull() { return Size == MaxSize; }

	void Print();

	const DataType GetData(int index) { return Data[index]; }

private:
	int GetParent(int index);	// 부모 노드의 인덱스 리턴
	int GetLeftChild(int index);	// 왼쪽 자식 인덱스 리턴
	int GetRightChild(int index);	// 오른쪽 자식 인덱스 리턴

	void HeapifyUp(int index);	// 힙의 상향식 재배열
	void HeapifyDown(int index);	// 힙의 하향식 재배열
	
	void Print(int index, string indent, bool last);

private:
	DataType* Data;	// 저장하는 배열
	int MaxSize;	// 최대 크기
	int Size;	// 현재 요소의 개수
};

/*
	Heap : 힙
	- 특징
		1) 완전 이진 트리 형태
		2) 부모 노드와 자식 노드 간의 대소관계가 정해진 완전 이진 트리 구조
		3) 루트 노드는 항상 최소값 또는 최대값을 가진다
		4) 최소 힙 또는 최대 힙이 있다
			- 최소 힙 : 부모 노드의 값이 자식 노드의 값보다 작은 경우
			- 최대 힙 : 부모 노드의 값이 자식 노드의 값보다 큰 경우

	- 장점
		1) 최소값 또는 최대값을 상수 시간(0(1))에 찾을 수 있다
		2) 정렬, 우선순위 큐 등에서 유용하게 사용된다
		3) 이진 탐색 트리보다 간단하고 빠르게 구현할 수 있다.

	- 단점
		1) 중복된 값의 처리가 어렵다
		2) 삽입, 삭제 연산에 시간 복잡도가 0(log n)이 소요된다

	완전 이진 트리(Complete Binary Tree)
	- 특징
		1) 모든 노드가 꽉 찬 이진트리
		2) 마지막 레벨을 제외한 모든 레벨이 꽉 차있어야 한다
		3) 마지막 레벨은 왼쪽부터 차례대로 채워진다
		4) 모든 노드는 왼쪽에서 오른쪽으로 채워져야 한다

	- 장점
		1) 배열로 구현할 때 간단하게 구현할 수 있다
			- i 번째 노드의 왼쪽 자식 노드 = 2i 번째 노드
			- i 번째 노드의 오른쪽 자식 노드  = 2i + 1 번째 노드
			- i 번째 노드의 부모 노드 = i/2 번째 노드
		2) 탐색 시간이 0(log n)으로 매우 빠르다
		3) 노드의 개수가 적어 공간 복잡도가 적다

	- 단점
		1) 삽입과 삭제시 노드의 이동이 많아서 시간 복잡도가 높다
*/