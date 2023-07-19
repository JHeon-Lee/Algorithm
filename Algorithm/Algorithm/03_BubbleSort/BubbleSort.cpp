#include "stdafx.h"
#include "BubbleSort.h"

void DoBubbleSort()
{
	vector<int> arr;
	for (int i = 0; i < 10; i++)
		arr.push_back(rand() % 100);

	for (int n : arr)
		cout << n << " ";

	BubbleSort(arr);

	cout << endll;

	for (int n : arr)
		cout << n << " ";
}

void BubbleSort(vector<int>& arr)
{
	for (int i = arr.size() - 1; i > 0; i--)
		for (int j = 0; j < i; j++)
			if (arr[j] < arr[j + 1]) // 오름차순, 내림차순 결정
				swap(arr[j], arr[j + 1]);
}
