#pragma once

void DoStack();

template<typename T>
class Stack
{
public:
	Stack();

	bool IsEmpty() { return Top == -1; }
	bool IsFull() { return Top == MAX_SIZE; }

	void Push(T data);

	T Pop();
	T Peek();

private:
	int Top;
	T Data[MAX_SIZE];
};

/*
	Stack : 스택
	- 특징
		1) 후입선출(LIFO) 구조를 가지는 자료구조
		2) 삽입은 Push, 삭제는 Pop 연산을 사용

	- 장점
		1) 구현이 간단하다
		2) 함수 호출의 역추적, 수식 계산, 문자열 역순 등에서 유용하다

	- 단점
		1) 중간의 원소에 접근하기 어렵다
*/
