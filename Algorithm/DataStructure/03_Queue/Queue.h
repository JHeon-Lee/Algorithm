#pragma once

void DoQueue();

template<typename T>
class Queue
{
public:
	Queue()
		: Front(0), Rear(0), Size(0)
	{}

	bool IsEmpty() { return Size == 0; }
	bool IsFull() { return Size == MAX_SIZE; }
	
	int GetSize() { return Size; }

	void Enqueue(T data);
	void Dequeue();

	T GetFront();

private:
	int Front;
	int Rear;
	int Size;
	T Data[MAX_SIZE];
};

// 환형 큐 사용 -> front, rear 사용

/*
	Queue : 큐
	-특징
		1) 선입선출(FIFO) 구조를 가지는 자료구조
		2) 삽입은 Enqueue, 삭제는 Dequeue 연산을 사용

	-장점
		1) 구현이 간단
		2) 작업 처리 대기열, 메시지 전달 등에서 유용하다

	-단점
		1) 큐의 크기가 고정되어 있을 때, 큐가 가득 차면 더 이상 데이터를 추가할 수 없다
*/