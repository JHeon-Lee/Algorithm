#include "stdafx.h"
#include "Stack.h"

void DoStack()
{
	Stack<int> s;

	s.Push(1);
	s.Push(2);
	s.Push(3);

	cout << s.Pop() << endl;
	cout << s.Peek() << endl;
	cout << s.Pop() << endl;
	cout << s.Pop() << endl;
	cout << s.Pop() << endl;

	return;
}

template<typename T>
inline Stack<T>::Stack()
{
	Top = -1;
}

template<typename T>
inline void Stack<T>::Push(T data)
{
	if (IsFull())
	{
		cout << "stack is full" << endl;
		return;
	}

	Data[++Top] = data;
	return;
}

template<typename T>
inline T Stack<T>::Pop()
{
	if (IsEmpty())
	{
		cout << "stack is null" << endl;
		return T();
	}

	return Data[Top--];
}

template<typename T>
inline T Stack<T>::Peek()
{
	if (IsEmpty())
	{
		cout << "stack is null" << endl;
		return T();
	}

	return Data[Top];
}