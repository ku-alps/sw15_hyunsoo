#include<cstdio>
#include<algorithm>
using namespace std;
// 최솟값과 최댓값
// 특정 구간의 특수 값을 저장하는 형태의 자료구조가 필요
// so, 세그먼트 트리를 사용

#define NUM ( 1 << 19 ) // 데이터 크기 10만개 (약 1의 18승)
#define START ( NUM >> 1 ) - 1 // 실제 값이 위치할 인덱스
#define LIM 1000000000 // 값의 최대치 10억

int N, M, start = START;
pair<int, int>  segment[NUM]; // 최대, 최소 값 세그먼트 트리

int F_Max(int idx, int s, int e, int f, int b) { // 최대값 탐색
	if (s == f && e == b) { // 범위가 완전 딱 맞는 경우
		return segment[idx].first; // 해당 인덱스의 최대값 반환
	}

	int val = 0, mid = (s + e) / 2; // 중간위치
	if (f < mid) { // 탐색 범위가 앞을 포함
		int limit = min(b, mid);
		val = max(val, F_Max(idx * 2 + 1, s, mid, f, limit));
	}
	if (mid < b) { // 탐색 범위가 뒤를 포함
		int limit = max(f, mid);
		val = max(val, F_Max(idx * 2 + 2, mid, e, limit, b));
	}
	return val;
}

int F_Min(int idx, int s, int e, int f, int b) { // 최소값 탐색
	if (s == f && e == b) { // 범위가 완전 딱 맞는 경우
		return segment[idx].second; // 해당 인덱스의 최소값 반환
	}

	int val = LIM, mid = (s + e) / 2; // 중간위치
	if (f < mid) { // 탐색 범위가 앞을 포함
		int limit = min(b, mid);
		val = min(val, F_Min(idx * 2 + 1, s, mid, f, limit));
	}
	if (mid < b) { // 탐색 범위가 뒤를 포함
		int limit = max(f, mid);
		val = min(val, F_Min(idx * 2 + 2, mid, e, limit, b));
	}
	return val;
}

int main() {
	scanf("%d %d", &N, &M);
	for (int k = 0; k < N; k++) {
		int num;
		scanf("%d", &num);
		segment[start + k] = pair<int, int>(num, num); // 값 하나가 최대 및 최소
	}

	int f = start, b = (NUM >> 1); // 세그먼트 트리 구성
	while (f) { // 루트가 아니면 계속
		for (int k = 0; k < b; k += 2) {
			pair<int, int> first = segment[f + k], second = segment[f + k + 1];
			segment[(f + k) / 2] = pair<int, int>(max(first.first, second.first), min(first.second, second.second));
			// 각각 최대, 최소값을 선택하여 다음 루트에 값을 기록
		}
		f /= 2;
		b /= 2; // 구간 및 시작 인덱스 변경
	}

	for (int k = 0; k < M; k++) { // 명령 처리
		int a, b;
		scanf("%d %d", &a, &b); // 범위 입력

		a -= 1; // 데이터 전처리 ( 인덱스 동기화 )
		printf("%d %d\n", F_Min(0, 0, NUM / 2, a, b), F_Max(0, 0, NUM / 2, a, b)); // 최대, 최소값 탐색하여 출력
	}
}