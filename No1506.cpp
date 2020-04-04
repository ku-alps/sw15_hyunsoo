#include<iostream>
#include<algorithm>
using namespace std;
// 경찰서
// 도시를 통제하기 위해선 되돌아오는 경로가 반드시 필요
// 이는 사이클을 의미하며, a가 b를 통제할 수 있다면, b 또한 a를 통제할 수 있음

// 즉, 각 지점에 대해 사이클을 판단 후, 각 그룹마다 최소값을 선택
// 각 구간으로 연결되는 길이 있는지만 판단하면 충분하므로, 플로이드 워셜을 활용

#define NUM 100

int N, cost[NUM], bridge[NUM][NUM]; // 비용, 연결 여부
int visit[NUM]; // 방문 여부

int main() {
	// 입력
	cin >> N;
	for (int k = 0; k < N; k++) {
		cin >> cost[k];
	}
	for (int k = 0; k < N; k++) {
		for (int m = 0; m < N; m++) {
			char ch;
			cin >> ch;
			bridge[k][m] = ch - '0';
		}
	}

	// 플로이드 워셜 알고리즘
	for (int k = 0; k < N; k++) {
		for (int m = 0; m < N; m++) {
			for (int i = 0; i < N; i++) {
				bridge[m][i] |= bridge[m][k] & bridge[k][i]; // 연결된 경로의 존재 여부
			}
		}
	}

	int ans = 0;
	for (int k = 0; k < N; k++) {
		if (visit[k]) continue; // 이미 방문한 곳이면 무시
		visit[k] = 1;

		int w = cost[k]; // 기본 비용
		for (int m = k + 1; m < N; m++) { // 이후에 등장하는 모든 지역과 연결여부 판단
			if (bridge[k][m] & bridge[m][k]) { // 왕복이 가능하면
				visit[m] = 1; // 해당 지역을 사용
				w = min(w, cost[m]); // 최소비용을 선택
			}
		}
		ans += w; // 선택한 최소비용을 답에 더함
	}
	cout << ans << endl;
}