#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;
// 치킨 배달

#define INF 50000

int N, M, visit[100]; // 맵 크기, 선택할 가게 수, 완전 탐색용 인덱스
vector<pair<int, int>> store, home; // 가게, 집 좌표

int DFS(int idx, int depth) {
	visit[depth++] = idx; // 현재 위치를 정보에 삽입
	if (depth == M) { // 원하는 높이까지 도달한 경우
		int cost[100]; // 각 집마다 가게까지의 최소거리
		for (int k = 0; k < home.size(); k++) {
			cost[k] = INF;
		}
		for (int m = 0; m < M; m++) { // 선택한 모든 가게에 대해 비교
			pair<int, int> s = store[visit[m]]; // 좌표 획득
			for (int k = 0; k < home.size(); k++) { // 각 집에 대해 최소거리를 획득
				cost[k] = min(cost[k], abs(s.first - home[k].first) + abs(s.second - home[k].second));
			}
		}
		int ans = 0; // 해당 경우의 치킨거리의 총 합
		for (int k = 0; k < home.size(); k++) {
			ans += cost[k];
		}
		return ans; // 정답 반환
	}

	int mini = INF; // 깊이가 부족한 경우, 이후 등장하는 값들에 대해 재귀호출
	for (int k = idx + 1; k < store.size(); k++) {
		mini = min(mini, DFS(k, depth)); // 최소값 선별
	}
	return mini;
}

int main() {
	cin >> N >> M;
	for (int k = 0; k < N; k++) {
		for (int m = 0; m < N; m++) {
			int data;
			cin >> data;

			if (data == 1) home.push_back(pair<int, int>(k, m));
			else if (data == 2) store.push_back(pair<int, int>(k, m)); // 가게, 집 좌표 정보 기록
		}
	}

	int ans = INF;
	for (int k = 0; k < store.size(); k++) {
		ans = min(ans, DFS(k, 0));
	} // 모든 경우 중, 치킨거리가 가장 작은 것을 선택
	cout << ans << endl;
}