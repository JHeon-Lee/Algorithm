#include "stdafx.h"
#include "SelectionSort.h"

void DoSelectionSort()
{
	vector<int> arr;
	for (int i = 0; i < 10; i++)
		arr.push_back(rand() % 100);

	for (int n : arr)
		cout << n << " ";

	SelectionSort(arr);

	cout << endll;

	for (int n : arr)
		cout << n << " ";
}

void SelectionSort(vector<int>& arr)
{
	int index;
	for (int i=0;i<arr.size() - 1;i++)
	{
		index = i;

		for (int j = i + 1; j < arr.size(); j++)
			if (arr[j] > arr[index]) // 오름차순, 내림차순 결정
				index = j;

		swap(arr[index], arr[i]);
	}
}
