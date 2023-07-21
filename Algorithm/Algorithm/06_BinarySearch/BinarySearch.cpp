#include "stdafx.h"
#include "BinarySearch.h"

void DoBinarySearch()
{
	vector<int> arr;
	for (int i = 0; i < 30; i++)
		arr.push_back(i);

	cout << BinarySearch(arr, 21);
}

int BinarySearch(vector<int>& arr, int find)
{
	/*
	int pivot = arr.size() / 2;
	if (find < arr[pivot])
	{
		for (int i = arr.size() / 2; i < arr.size(); i++)
			arr.erase(arr.begin() + i);
		BinarySearch(arr, find);
	}
	else if (find > arr[pivot])
	{
		for (int i = 0; i < arr.size() / 2; i++)
			arr.erase(arr.begin() + i);
		BinarySearch(arr, find);
	}
	else
		return arr[pivot];
	*/

	int left = 0;
	int right = arr.size() - 1;

	while (left <= right)
	{
		int mid = left + (right - left) / 2;
		if (arr[mid] == find) return mid;
		else if (arr[mid] < find) left = mid + 1;
		else right = mid - 1;
	}

	return -1;
}
