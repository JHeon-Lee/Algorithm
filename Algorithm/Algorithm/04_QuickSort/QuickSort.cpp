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

    int pivot = left; // ���ذ�
    int i = pivot + 1;
    int j = right;
    int temp;

    while (i <= j)
    {
        while (i <= right && arr[i] <= arr[pivot]) // Ű ������ ū �� ���������� ���������� �̵�
            i++;
        while (j > left && arr[j] >= arr[pivot]) // Ű ������ ���� �� ���� ������ �������� �̵�
            j--;

        if (i > j) // ������ ���¶�� pivot �� ��ü
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

    // ��� ȣ���� ���� ���� ���
    QuickSort(arr, left, j - 1);
    QuickSort(arr, j + 1, right);
}
