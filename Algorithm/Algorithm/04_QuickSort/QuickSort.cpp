#include "stdafx.h"
#include "QuickSort.h"

void DoQuickSort()
{
	vector<int> arr;
	for (int i = 0; i < 10; i++)
		arr.push_back(rand() % 100);

	for (int n : arr)
		cout << n << " ";

	QuickSort(arr, 5, 5);

	cout << endll;

	for (int n : arr)
		cout << n << " ";
}

void QuickSort(vector<int>& arr, int left, int right)
{
}
