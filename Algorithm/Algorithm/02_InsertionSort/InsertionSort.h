#pragma once

void DoInsertionSort();
void InsertionSort(vector<int>& arr);

/*
	InsertionSort : 삽입 정렬

	- 특징
		1) 정렬되지 않은 부분의 가장 첫 번째 원소를 정렬된 부분에 삽입하는 방식으로 정렬을 수행하는 알고리즘

	- 장점
		1) 구현이 간단하며, 작은 데이터에서는 선택 정렬과 거의 비슷한 성능을 보인다
		2) 대부분이 이미 정렬된 데이터에 대해서 빠르게 정렬이 가능하다

	- 단점
		1) 최악의 경우 시간 복잡도가 매우 느리다
		2) 불안정 정렬이기 때문에 같은 값의 경우 위치가 변경될 수 있다
*/