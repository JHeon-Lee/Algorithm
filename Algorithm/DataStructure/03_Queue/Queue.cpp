#include "stdafx.h"
#include "Queue.h"

void DoQueue()
{
	Queue<int> q;

	q.Enqueue(1);
	q.Enqueue(2);
	q.Enqueue(3);

	cout << "Queue Size : " << q.GetSize() << endl;

	cout << "Front element : " << q.GetFront() << endl;
	q.Dequeue();

	cout << "Front element : " << q.GetFront() << endl;
	q.Dequeue();
	
	cout << "Front element : " << q.GetFront() << endl;
	q.Dequeue();
	
	cout << "Front element : " << q.GetFront() << endl;
	q.Dequeue();

	cout << "Queue Size : " << q.GetSize() << endl;

	return;
}

template<typename T>
inline void Queue<T>::Enqueue(T data)
{
	if (IsFull())
	{
		cout << "Queue is Full" << endl;
		return;
	}

	Data[Rear] = data;
	Rear = (Rear + 1) % MAX_SIZE; // MAX_SIZE 넘어갔는지 확인
	Size++;
}

template<typename T>
inline void Queue<T>::Dequeue()
{
	if (IsEmpty())
	{
		cout << "Queue is Empty" << endl;
		return;
	}

	Front = (Front + 1) % MAX_SIZE;
	Size--;
}

template<typename T>
inline T Queue<T>::GetFront()
{
	if (IsEmpty())
	{
		cout << "Queue is Empty" << endl;
		return T();
	}

	return Data[Front];
}
