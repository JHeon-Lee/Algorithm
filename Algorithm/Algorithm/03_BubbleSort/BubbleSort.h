#pragma once

void DoBubbleSort();
void BubbleSort(vector<int>& arr);

/*
	BubbleSort : 버블 정렬

	- 특징
		1) 인접한 두 원소를 비교하여 큰 값이 오른쪽으로 이동하며 정렬하는 알고리즘

	- 장점
		1) 구현이 간단하다

	- 단점
		1) 시간 복잡도가 크기 때문에 대용량 데이터에 적용하기 어렵다
		2) 불안정 정렬이기 때문에 같은 값의 경우 위치가 변경될 수 있다
*/