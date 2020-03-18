#include<iostream>
#include<queue>
#include<tuple>
using namespace std;
// 열쇠
// 모든 조건에 따라 전체탐색을 하는 경우, 시간초과가 발생 ( 열쇠와 문의 종류가 너무 많음 )
// so, BFS 를 통해 각 구간에 대해 중복 탐색을 없애길 원함

// 바깥부터 가능한 모든 공간을 탐색하며,
// 탐색하는 공간의 종류에 따라 행동을 분류

#define ALP 26 // 알파벳  a~z 까지 26개
#define NUM 100 // 높이값
#define X "0121"
#define Y "1210"

int main() {	int T, N, M;
	cin >> T;
	while (T--) {
		int ans = 0, keySet = 0; // 정답 값, 갖고 있는 열쇠 
		bool visit[NUM][NUM] = {}; // 방문 여부
		char map[NUM][NUM] = {};
		queue<pair<int, int>> bfs;
		queue<pair<int, int>> door[ALP]; // 각 열쇠를 요구하는 문의 좌표

		cin >> N >> M;
		for (int k = 0; k < N; k++) {
			for (int m = 0; m < M; m++) {
				cin >> map[k][m];
				if (k == 0 || k == N - 1 || m == 0 || m == M - 1) {
					// 사방 모서리 위치인 경우, 접근 가능한지 확인
					if (map[k][m] != '*') bfs.emplace(k, m); // 벽만 아니면 탐색 시도
				}
			}
		}

		string keys;
		cin >> keys;
		keys = (keys == "0") ? "" : keys; // "0" 이 들어온 경우, 가진 키가 없음
		for (int k = 0; k < keys.length(); k++) {
			int k_idx = keys[k] - 'a';
			keySet |= (1 << k_idx); // 가진 열쇠를 비트마스킹으로 표기
		}

		while (!bfs.empty()) { // BFS 탐색 수행
			int x, y;
			tie(x, y) = bfs.front();
			bfs.pop();
			
			if (visit[x][y]) continue; // 이미 둘러본 곳이면 무시

			// 각 도달한 위치의 종류에 따라 분할하여 처리
			if (map[x][y] == '*') continue; // 벽
			if (map[x][y] == '$') ans += 1; // 문서
			if (map[x][y] >= 'a' && map[x][y] <= 'z') { // 열쇠
				int k_idx = map[x][y] - 'a';
				keySet |= 1 << k_idx; // 열쇠를 가져감

				// 현재까지 도달한 문 중, 해당 열쇠를 갖고 열 수 있던 문을 전부 큐에 삽입
				while (!door[k_idx].empty()) {
					bfs.push(door[k_idx].front());
					door[k_idx].pop();
				}
			}
			if (map[x][y] >= 'A' && map[x][y] <= 'Z') { // 문
				int d_idx = map[x][y] - 'A';
				if (!(keySet & 1 << d_idx)) {
					// 해당 문을 열 수 있는 키를 갖고있지 않다면
					door[d_idx].emplace(x, y); // 해당 좌표가 문임을 기록해둠
					continue; // 건너감
				}
			}
			visit[x][y] = true; // 방문함

			for (int k = 0; k < 4; k++) { // 네 방향에 대해 탐색
				int n_x = x + X[k] - '1', n_y = y + Y[k] - '1';
				if (n_x < 0 || n_x >= N || n_y < 0 || n_y >= M) continue; // 범주를 벗어난 경우
				bfs.emplace(n_x, n_y);
			}
		}
		cout << ans << endl;
	}
}