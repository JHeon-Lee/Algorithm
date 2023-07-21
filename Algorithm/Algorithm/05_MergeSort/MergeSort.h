#pragma once

void DoMergeSort();
void MergeSort(vector<int>& arr, int left, int right);
void Merge(vector<int>& arr, int left, int mid, int right);

/*
	MergeSort : ���� ����

	- Ư¡
		1) ���� ���� ����� ����ϴ� �˰���
		2) ����Ʈ�� �ݾ� �������� ���� �� ����

	- ����
		1) ���� ���Ŀ� ���Ѵ�
		2) ū �����͸� ó���� �� �ٸ� �˰��� ���� ��������� ���� ����

	- ����
		1) ���ĵ� ����Ʈ�� �߰��� �����ؾ� �ϱ� ������ �޸� ������ �� �ʿ�
*/