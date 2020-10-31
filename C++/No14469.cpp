#include<iostream>
#include<queue>
#include<tuple>
#include<algorithm>
using namespace std;
// 소가 길을 건너간 이유 3
// 우선순위 큐, 값 비교

typedef pair<int, int> p;

struct func {
	bool operator()(p a, p b) { return a.first > b.first; }
};

int N;
priority_queue<p, vector<p>, func> pq;
// 도착한 시각, 검문 요구시간

int main() {
	cin >> N; // 입력
	for (int k = 0; k < N; k++) {
		int a, b;
		cin >> a >> b;
		pq.emplace(a, b);
	}

	int ans = 0;
	while (!pq.empty()) {
		int a, b;
		tie(a, b) = pq.top();
		pq.pop();
		// 현재까지의 누적 시간과 소의 도착 시각 중 큰 값을 기반으로 계산
		ans = max(ans, a) + b;
	}
	cout << ans << endl;
}