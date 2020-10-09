#include<iostream>
#include<algorithm>
using namespace std;
// 구간 합 구하기 2
// Lazy Propagation 사용

#define NUM ((1 << 21) - 1)
#define START NUM / 2
#define RANGE (NUM + 1) / 2
typedef long long int lli;

int cnt[NUM];
lli N, M, K, seg[NUM], lazy[NUM];

// 구간 갱신 함수 (아래 -> 위의 값 갱신)
lli Lazy(lli idx, lli front, lli back, lli from, lli to, lli val) {
	// 현재 좌표, 앞/뒤 범위값, 갱신 범위값, 더해질 값
	if ((front == from && back == to) || START <= idx) {
		lazy[idx] += val; // 완벽하게 일치하는 구간이면 lazy
		lli add = cnt[idx] * val; // 새로 유입된 값만큼만 수정
		seg[idx] += add; // 현재 자리의 총 합은 갱신
		return add; // 추가된 값 반환
	}

	lli ans = 0;
	lli mid = (front + back) / 2; // 이분 탐색의 중간 위치
	Lazy((idx << 1) + 1, front, mid, front, mid, lazy[idx]);
	Lazy((idx << 1) + 2, mid + 1, back, mid + 1, back, lazy[idx]);
	// 갖고 있던 값을 자식에게 1차로 넘김
	lazy[idx] = 0;

	// 범위에 따라 새로 들어온 값을 좌우로 넘김
	if (from <= mid) { // 왼쪽 범위
		ans += Lazy((idx << 1) + 1, front, mid, from, min(to, mid), val); 
	}
	if (mid < to) { // 오른쪽 범위
		ans += Lazy((idx << 1) + 2, mid + 1, back, max(from, mid + 1), to, val);
	}
	seg[idx] += ans; // 자식에서 더해진 값의 총량만큼 갱신
	return ans; // 갱신량 반환
}

// 구간 합 탐색 함수 (위 -> 아래의 값 갱신)
lli Sum(lli idx, lli front, lli back, lli from, lli to, lli val) {
	seg[idx] += val * cnt[idx]; // 값 갱신
	if ((front == from && back == to) || START <= idx) {
		lazy[idx] += val; // 레이지 갱신
		return seg[idx]; // 반환
	}

	lli ans = 0;
	lli mid = (front + back) / 2;
	Lazy((idx << 1) + 1, front, mid, front, mid, lazy[idx]);
	Lazy((idx << 1) + 2, mid + 1, back, mid + 1, back, lazy[idx]);
	lazy[idx] = 0;

	if (from <= mid) { // 좌측 탐색
		ans += Sum((idx << 1) + 1, front, mid, from, min(to, mid), val);
	}
	if (mid < to) { // 우측 탐색
		ans += Sum((idx << 1) + 2, mid + 1, back, max(from, mid + 1), to, val);
	}
	return ans; // 좌우 합 반환
}


int main() {
	cin >> N >> M >> K;
	for (int k = 0; k < N; k++) { // 입력
		cin >> seg[START + k];
		cnt[START + k] = 1;
	}
	int from = START >> 1, to = START - 1;
	while (from <= to) { // 세그먼트 트리
		for (int k = from; k <= to; k++) {
			seg[k] = seg[(k << 1) + 1] + seg[(k << 1) + 2];
			cnt[k] = cnt[(k << 1) + 1] + cnt[(k << 1) + 2];
		}
		to = from - 1;
		from /= 2;
	}

	// 탐색 or 갱신
	for (int k = 0; k < M + K; k++) {
		lli a, b, c, d;
		cin >> a;
		if (a == 1) { // 구간 갱신
			cin >> b >> c >> d;
			Lazy(0, 1, RANGE, b, c, d);
		}
		else { // 구간 합
			cin >> b >> c;
			cout << Sum(0, 1, RANGE, b, c, lazy[0]) << endl;
		}
	}
}