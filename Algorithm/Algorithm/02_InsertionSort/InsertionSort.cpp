#include "stdafx.h"
#include "InsertionSort.h"

void DoInsertionSort()
{
	vector<int> arr;
	for (int i = 0; i < 10; i++)
		arr.push_back(rand() % 100);

	for (int n : arr)
		cout << n << " ";

	InsertionSort(arr);

	cout << endll;

	for (int n : arr)
		cout << n << " ";
}

void InsertionSort(vector<int>& arr)
{
	int i, j, key;
	for (i = 1; i < arr.size(); i++)
	{
		key = arr[i];

		for (j = i - 1; j >= 0; j--)
		{
			if (arr[j] < key)
				arr[j + 1] = arr[j];
			else
				break;
		}
		arr[j + 1] = key;
	}
}
