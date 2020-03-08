#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
// 최솟값 찾기
// 연속된 데이터 범주 내에서 빠른 값 판단이 필요
// so, 쿼리에 대한 시간 감축이 필요하므로 Segment Tree 를 사용했으나,
// 재귀 호출 구조로 인해 시간초과 ( 추가적으로 찾아보니, 시간을 최대한 줄여도 아슬아슬하다고 함 )

// 따라서 우선순위 큐 방식으로 변경하여
// 모든 값에 대해 1회만 접근

#define NUM 5000000

int N, L, val[NUM]; // 원소 수, 쿼리 범위, 각 원소 값

struct func {
	bool operator()(int a, int b) {
		return val[a] > val[b]; // 소유한 값이 
	}
};

priority_queue<int, vector<int>, func> pq; // 인덱스를 정렬할 큐

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> L;
	for (int k = 0; k < N; k++) {
		cin >> val[k]; // 값 입력
	}

	int f = -L + 1, b = 0; // 구간은 ( i - L + 1, i )  
	while (b != N) {
		pq.push(b); // 현재 인덱스를 추가로 삽입
		while (pq.top() < f) pq.pop(); // 범위를 벗어난 값 정리
		cout << val[pq.top()] << " ";

		f += 1;
		b += 1; // 앞뒤 인덱스 이동 ( 범위 이동 )
	}
}