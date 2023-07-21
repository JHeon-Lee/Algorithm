#include "stdafx.h"
#include "QuickSort.h"

void DoQuickSort()
{
	vector<int> arr;
	for (int i = 0; i < 10; i++)
		arr.push_back(rand() % 100);

	for (int n : arr)
		cout << n << " ";

	QuickSort(arr, 0, 9);

	cout << endll;

	for (int n : arr)
		cout << n << " ";
}

void QuickSort(vector<int>& arr, int left, int right)
{
    if (left >= right)
        return;

    int pivot = left; // 기준값
    int i = pivot + 1;
    int j = right;
    int temp;

    while (i <= j)
    {
        while (i <= right && arr[i] <= arr[pivot]) // 키 값보다 큰 값 만날때까지 오른쪽으로 이동
            i++;
        while (j > left && arr[j] >= arr[pivot]) // 키 값보다 작은 값 만날 때까지 왼쪽으로 이동
            j--;

        if (i > j) // 엇갈린 상태라면 pivot 값 교체
        {
            temp = arr[j];
            arr[j] = arr[pivot];
            arr[pivot] = temp;
        }
        else
        {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    // 재귀 호출을 통한 분할 계산
    QuickSort(arr, left, j - 1);
    QuickSort(arr, j + 1, right);
}
