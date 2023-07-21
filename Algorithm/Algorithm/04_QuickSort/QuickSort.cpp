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
    // 리스트의 크기가 1 이하인 경우, 정렬이 이미 완료된 상태
    if (left >= right)
        return;

    int pivot = left; // 기준값 (리스트의 첫 요소를 pivot으로 설정)
    int i = pivot + 1;
    int j = right;
    int temp;

    // i와 j가 교차할 때까지 pivot보다 작은 요소는 i를,
    // pivot보다 큰 요소는 j를 찾음
    while (i <= j)
    {
        while (i <= right && arr[i] <= arr[pivot]) // 키 값보다 큰 값 만날때까지 오른쪽으로 이동
            // 오름차순, 내림차순 결정
            i++;
        while (j > left && arr[j] >= arr[pivot]) // 키 값보다 작은 값 만날 때까지 왼쪽으로 이동
            // 오름차순, 내림차순 결정
            j--;

        if (i > j) // 엇갈린 상태라면 pivot 값 교체
        {
            temp = arr[j];
            arr[j] = arr[pivot];
            arr[pivot] = temp; // swap(arr[j], arr[pivot]);
        }
        else
        {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp; // swap(arr[i], arr[j]);
        }
    }

    // 재귀 호출을 통한 분할 계산
    // pivot을 기준으로 분할된 왼쪽과 오른쪽 부분 리스트를 재귀적으로 정렬
    QuickSort(arr, left, j - 1);
    QuickSort(arr, j + 1, right);
}
