#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
// 행렬 곱셈 순서

#define MAX 500 // 입력 최대치

long long int N, sum[MAX][MAX]; // i~j 의 곱 연산량
pair<int, int> arr[MAX]; // 각 행렬의 크기 정보

long long int DP(int from, int to) {
	if (from == to) return 0; // 범위가 1인 경우 연산량 없음
	if (sum[from][to]) return sum[from][to]; // 이미 기록되어있으면 반환

	pair<int, int> a = arr[from];
	pair<int, int> b = arr[to];
	sum[from][to] = (1 << 31) - 1; // 최대 데이터
	for (int k = from + 1; k <= to; k++) { // 가능한 모든 경우를 만들어 비교
		pair<int, int> c = arr[k]; // 해당 행렬의 크기 정보
		int add = a.first * b.second * c.first; // 추가적으로 더해지는 연산량 
		// ( 앞 행렬 1번 크기 ) * ( 중간 행렬 1번 크기 ) * ( 뒷 행렬 2번 크기 )
		sum[from][to] = min(sum[from][to], DP(from, k - 1) + DP(k, to) + add); // 최소 값을 결정
	}
	return sum[from][to]; // 결과 반환
}

int main() {
	scanf("%d", &N);
	int a, b;
	for (int k = 0; k < N; k++) {
		scanf("%d %d", &a, &b);
		arr[k] = pair<int, int>(a, b);
	}
	printf("%lld\n", DP(0, N - 1)); // 결과 출력
}