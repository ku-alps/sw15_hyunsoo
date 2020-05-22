#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
// 커피숍 2
// 새그먼트 트리를 사용한 풀이
// 주어지는 데이터의 범위가 int형이므로, 그 합은 long long int 형을 사용해야만 함
// 함수의 반환값과 차이값 또한 long long int 형식을 유지해야 한다는 점에서 걸렸음

#define MAX (1<<19)
#define NUM_MAX (MAX >> 1) // 세그먼트 트리용

long long int arr[MAX]; // 세그먼트 트리
int start = NUM_MAX - 1; // 시작 index
int N, Q;

long long int S(int idx, int from, int to, int a, int b) {
	if (from == a && to == b) return arr[idx]; // 찾는 범위와 정확히 일치하면 종료

	long long int sum = 0;
	int mid = (from + to) / 2; // 중간값
	if (a <= mid) { // 중간 값 밑의 범위를 갖는 경우
		sum += S(idx * 2 + 1, from, mid, a, min(mid, b)); 
	} // 시작 지점 ~ 중간값 까지 재탐색
	if (b > mid) { // 중간 값 위의 범위를 갖는 경우
		sum += S(idx * 2 + 2, mid + 1, to, max(mid + 1, a), b);
	} // 중간 + 1 ~ 끝 지점까지 재탐색

	//이때 각각 찾는 범위 a, b 는 mid 와의 크기차이로 결정됨
	return sum; // 합을 출력
}

int main() {
	scanf("%d %d", &N, &Q);
	for (int k = 0; k < N; k++) {
		scanf("%lld", &arr[start + k]);
	}

	int f = start, b = MAX - 1; // 세그먼트 트리 각 depth 의 범위
	while (f != 0) { // 루트에 도달할 때까지
		for (int k = f; k < b; k += 2) 
			arr[k / 2] = arr[k] + arr[k + 1]; // 해당 단계의 모든 빈칸을 채움
		b = f - 1;
		f /= 2;
	}

	for (int k = 0; k < Q; k++) {
		int from, to;
		scanf("%d %d", &from, &to);
		if (from > to) { // 배열 인덱스 크기가 뒤바뀌었으면 swap
			int save = from;
			from = to;
			to = save;
		}
		printf("%lld\n", S(0, 1, NUM_MAX, from, to)); // 결과를 long long int 로 출력

		int sel;
		long long int change;
		scanf("%d %lld", &sel, &change); // 선택 인덱스와 변화 값

		int sel_idx = start + sel - 1;
		long long int differ = change - arr[sel_idx]; // 기존값과의 차이값을 계산
		while (sel_idx) { // 루트로 거슬러 올라갈 떄 까지 반복
			arr[sel_idx] += differ; //변화한 값만큼 모두 갱신
			sel_idx = (sel_idx - 1) / 2;
		}
		arr[0] += differ; // 루트 값 갱신
	}
}