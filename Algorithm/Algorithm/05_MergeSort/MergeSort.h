#pragma once

void DoMergeSort();
void MergeSort(vector<int>& arr, int left, int right);
void Merge(vector<int>& arr, int left, int mid, int right);

/*
	MergeSort : 병합 정렬

	- 특징
		1) 분할 정복 방법을 사용하는 알고리즘
		2) 리스트를 반씩 나눠가며 정렬 후 병합

	- 장점
		1) 안정 정렬에 속한다
		2) 큰 데이터를 처리할 때 다른 알고리즘에 비해 상대적으로 빠른 성능

	- 단점
		1) 정렬된 리스트를 추가로 저장해야 하기 때문에 메모리 공간이 더 필요
*/