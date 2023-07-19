#pragma once

void DoSelectionSort();
void SelectionSort(vector<int>& arr);

/*
	Selection Sort : 선택 정렬

	- 특징
		1) 현재 위치에서 가장 큰(작은) 원소를 찾아서 맨 앞으로 이동시키는 알고리즘

	- 장점
		1) 구현이 간단하며, 공간 복잡도가 작다

	- 단점
		1) 시간 복잡도가 크기 때문에 대용량 데이터에 적용하기 어렵다
		2) 불안정 정렬이기 때문에 같은 값의 경우 위치가 변경될 수 있다
*/