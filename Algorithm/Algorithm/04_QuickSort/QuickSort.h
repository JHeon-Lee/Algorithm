#pragma once

void DoQuickSort();
void QuickSort(vector<int>& arr, int left, int right);

/*
	Quick Sort : �� ����

	- Ư¡
		1) ���� ���� ����� ����ϴ� �˰�����
		2) pivot�� �������� �¿�� �����Ͽ� �����ϴ� ������� ����

	- ����
		1) ��κ��� ��� ���� �ӵ��� ������ �����Ѵ�
		2) �޸� ��뷮�� ����

	- ����
		1) �����ϰ��� �ϴ� �迭�� �̹� ���ĵǾ� �ְų�, ��� ������ ���� ���� ��� ������ �ް��� ���ϵ�
		2) �ұ����� ������ �߻��� ��� ������ �������� ������ �ִ�
*/