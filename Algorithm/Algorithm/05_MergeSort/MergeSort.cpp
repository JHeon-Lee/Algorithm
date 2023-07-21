#include "stdafx.h"
#include "MergeSort.h"

void DoMergeSort()
{
	vector<int> arr;
	for (int i = 0; i < 10; i++)
		arr.push_back(rand() % 100);

	for (int n : arr)
		cout << n << " ";

	MergeSort(arr, 0, 9);

	cout << endll;

	for (int n : arr)
		cout << n << " ";
}

void MergeSort(vector<int>& arr, int left, int right)
{
	// ����Ʈ�� ũ�Ⱑ 1 ������ ���, ������ �̹� �Ϸ�� ����
	if (left >= right) return;

	// ����Ʈ�� ������ ���� �ε���
	int mid = (left + right) / 2;

	// ���� �κ� ����Ʈ�� ��������� ����
	MergeSort(arr, left, mid);
	// ������ �κ� ����Ʈ�� ��������� ����
	MergeSort(arr, mid + 1, right);
	// ���ĵ� ���ʰ� ������ �κ� ����Ʈ�� ����
	Merge(arr, left, mid, right);
}

void Merge(vector<int>& arr, int left, int mid, int right)
{
	int i = left; // ���ʺκ� ���� �ε���
	int j = mid + 1; // �����ʺκ� ����Ʈ�� ���� �ε���
	int k = left; // ���ĵ� ����� ������ �迭�� �ε���
	vector<int> temp; // ���� ����� ������ �ӽ� �迭
	temp.assign(arr.size(), int());

	// ���� �κ� ����Ʈ�� ������ �κ� ����Ʈ�� ��ҵ��� ���ϸ� �ӽ� �迭�� ����
	while (i <= mid && j <= right)
	{
		if (arr[i] >= arr[j]) // ��������, �������� ����
			temp[k++] = arr[i++];
		else
			temp[k++] = arr[j++];
	}

	// ���� �κ� ����Ʈ�� ������ �κ� ����Ʈ�� ��� �� �ϳ��� ��� ���յ� ���
	// ���� ��ҵ��� �ӽ� �迭�� �߰�
	while (i <= mid)
		temp[k++] = arr[i++];
	while (j <= right)
		temp[k++] = arr[j++];

	// �ӽ� �迭�� ����� ���� ����� ���� �迭�� ����
	for (int l = left; l <= right; l++)
		arr[l] = temp[l];
}
