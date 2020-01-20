#include<iostream>
using namespace std;
// 수들의 합 2
// 투 포인터를 이용한 슬라이딩 윈도우 방식을 사용

int main() {
	int N, M;
	int data[10000];

	cin >> N >> M;
	for (int k = 0; k < N; k++) {
		cin >> data[k]; // 데이터 입력
	}

	int f = 0, b = 0, sum = 0, select = 0;
	while (f != N) { // 앞쪽 포인터가 끝에 도달할 때 까지
		if (sum > M || b == N) { // 합이 요구 값보다 크거나, 뒤로 더 이상 움직일 수 없으면
			sum -= data[f]; 
			f += 1; // 앞쪽 포인터를 뒤로 당기고, 연속 배열의 합에서 뺌
		}
		else {
			sum += data[b];
			b += 1; // 그 외에는 뒤쪽 포인터를 옮기고, 배열 합에 추가
		}

		if (sum == M) // 요구 값과 정확히 일치하면
			select += 1; // 경우 수 + 1
	}
	cout << select << endl; // 출력
}