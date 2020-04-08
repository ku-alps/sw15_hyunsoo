#include<iostream>
#include<algorithm>
#include<stack>
using namespace std;
// 히스토그램
// 각 막대마다 자신의 좌, 우에서 연결할 수 있는 막대 수를 측정해야 함
// 기본적으로 분할 정복 문제이나, '스택' 을 활용하여 문제 풀이 가능

#define NUM 100000

int N, graph[NUM], from[NUM], to[NUM];

int main() {
	cin >> N; // 그래프 개수

	for (int k = 0; k < N; k++) {
		cin >> graph[k]; // 각 막대의 높이
	}

	{ // 왼쪽 막대 수 계산
		stack<pair<int, int>> s; // 스택
		s.push({ -1, 0 }); // 시작은 -1과 높이 0 으로 취급
		for (int k = 0; k < N; k++) {
			while (!s.empty()) {
				if (graph[k] > s.top().second) break; // 작은 경우, 추가 연결이 끊김
				s.pop(); // 현재 높이보다 크거나 같은 값은 모두 제거
			}
			from[k] = (s.empty() ? 1 : k - s.top().first); // 최대로 연결 가능한 왼쪽 막대 수
			s.push({ k,graph[k] }); // 좌표와 높이 삽입
		}
	}

	{ // 오른쪽 막대 수 계산
		stack<pair<int, int>> s;
		s.push({ N, 0 });
		for (int k = N - 1; k >= 0; k--) {
			while (!s.empty()) { // 현재 높이보다 작아지는 막대 위치를 참음
				if (graph[k] > s.top().second) break;
				s.pop();
			}
			to[k] = (s.empty() ? 1 : s.top().first - k); // 최대로 연결 가능한 오른쪽 막대 수
			s.push({ k,graph[k] }); // 좌표와 높이 삽입
		}
	}

	int ans = 0;
	for (int k = 0; k < N; k++) { // 자신 본인이 중복되므로 1을 뺀 후 연산
		ans = max(ans, (from[k] + to[k] - 1) * graph[k]); // 연속된 갯수 * 높이
	}
	cout << ans << endl;
}
