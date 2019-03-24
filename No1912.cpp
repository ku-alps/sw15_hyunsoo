#include<iostream>
using namespace std;
// 연속합
// Maximum array 알고리즘

int main() {
	int size;
	cin >> size; // 현재 사이즈를 입력받음

	int* arr = new int[size]; //입력받은 사이즈만큼 배열 생성
	int total = -1000; //전체 총 합 (정답)
		// 값을 -1000 으로 스타트를 끊는 이유는, 최소한 하나의 값은 뽑아야 하기 때문
	int save = 0; // 임시저장
	for (int i = 0; i < size; i++) {
		cin >> arr[i];
		save += arr[i]; //기존 값에 입력값을 더함

		if (save > total)  //현재까지의 값이 유추된 정답보다 크다면
			total = save; // 정답을 바꾸기
		if (save < 0) // 0칸짜리와 비교, 음수가 되는 경우
			save = 0; // 0으로 초기화 (없애버림)
	}
	cout << total << endl; //출력
	delete[] arr; // 동적할당 삭제
}