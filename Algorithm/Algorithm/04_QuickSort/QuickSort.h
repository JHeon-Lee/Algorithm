#pragma once

void DoQuickSort();
void QuickSort(vector<int>& arr, int left, int right);

/*
	Quick Sort : 퀵 정렬

	- 특징
		1) 분할 정복 방법을 사용하는 알고리즘
		2) pivot을 기준으로 좌우로 분할하여 정렬하는 방식으로 동작

	- 장점
		1) 대부분의 경우 빠른 속도로 정렬을 수행한다
		2) 메모리 사용량이 적다

	- 단점
		1) 정렬하고자 하는 배열이 이미 정렬되어 있거나, 모든 원소의 값이 같은 경우 성능이 급격히 저하됨
		2) 불균형한 분할이 발생할 경우 성능이 떨어지는 경향이 있다
*/