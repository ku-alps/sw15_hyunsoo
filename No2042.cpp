#include<iostream>
#include<algorithm>
using namespace std;
// 구간 합 구하기
// 데이터의 변경과 부분 탐색이 빈번하므로, 세그먼트 트리를 사용
// 또한 입력 데이터의 값은 int 형 범주를 넘어서므로, long long int 를 기반으로 구성

#define NUM ( 1 << 23 )
#define START (NUM / 2) - 1

typedef long long int lli;

lli N, M, K, seg[NUM];

lli Sum(lli idx, lli front, lli back, lli a, lli b) { // 해당 노드가 가진 범주, 찾을 범주
	if (front == a && back == b)
		return seg[idx]; // 찾는 범위랑 딱 맞으면 그 값 반환

	lli mid = (front + back) / 2; // 이분 탐색할 기준 (중간 값)
	lli ans = 0; // 좌우 합
	if (a <= mid) ans += Sum(idx * 2 + 1, front, mid, a, min(b, mid)); // 왼쪽에 값이 있는 경우
	if (b > mid) ans += Sum(idx * 2 + 2, mid + 1, back, max(a, mid + 1), b); // 오른쪽에 값이 있는 경우
	return ans;
}

int main() {
	cin >> N >> M >> K;
	for (int k = 0; k < N; k++) {
		cin >> seg[START + k];
	}

	{ // 세그먼트 트리 생성
		int idx = START;
		while (idx != 0) {
			for (int k = 0; k < idx + 1; k += 2) {
				seg[(idx + k) / 2] = seg[idx + k] + seg[idx + k + 1];
			}
			idx /= 2;
		}
	}

	for (int k = 0; k < M + K; k++) {
		lli a, b, c;
		cin >> a >> b >> c;

		if (a == 1) {
			lli idx = START + (b - 1);
			lli residual = c - seg[idx];
			seg[idx] = c; // 데이터 변경

			while (idx != 0) {
				idx = (idx - 1) / 2; // 각 자식은 +1, +2 의 값을 가지므로, 1을 뺀 후 나눠야 함
				seg[idx] += residual; // 변화량만큼 전부 영향을 줌
			}
		}
		else {
			cout << Sum(0, 1, START + 1, b, c) << endl;
		}
	}
}