#include<iostream>
#include<queue>
#include<tuple>
#include<vector>
using namespace std;
// 배달
// 매 차례 방향을 바꿔야 함 + 이미 방문한 곳을 다시 방문할 수 있음
// so, 접근 방향, 배달 성공한 지점에 따라 정보를 분할하여 접근, 관리해야함
// BFS 의 단순 2차원 배열이 아닌, 4차원 배열을 요구

#define NUM 50
#define X "0121"
#define Y "1210" // 아래쪽부터 반시계 방향

int N, M, step[NUM][NUM][4][4]; // 맵 좌표, 접근 방향, 배달 여부
char map[NUM][NUM];
pair<int, int> from; // 출발 좌표
vector<pair<int,int>> to; // 도착지 좌표 (2개)

int main() {
	cin >> N >> M; // 맵 크기 입력

	// 지도 입력
	for (int k = 0; k < N; k++) { 
		for (int m = 0; m < M; m++) {
			cin >> map[k][m];
			if (map[k][m] == 'S') from = pair<int, int>(k, m);
			if (map[k][m] == 'C') to.emplace_back(k, m);
		}
	}

	int ans = -1; // 실패 값은 -1
	queue<tuple<int, int, int, int, int>> q; // BFS 용 큐

	// 시작점은 방향의 영향을 받지 않으므로, 4 종류를 모두 삽입
	for (int k = 0; k < 4; k++) { 
		q.emplace(from.first, from.second, k, 0, 0);
	}

	while (!q.empty()) { // BFS 탐색
		int x, y, dir, bit, val; // 좌표, 해당 지점으로 온 방향, 방문 비트, 이동량
		tie(x, y, dir, bit, val) = q.front();
		q.pop();

		if (map[x][y] == '#') continue; // 갈수없는 곳 무시
		if (step[x][y][dir][bit]) continue; // 이미 왔던 곳 무시
		for (int k = 0; k < to.size(); k++) {
			if (x == to[k].first && y == to[k].second) { // 목적지 중 한 곳에 도달했다먼,
				bit |= (1 << k); // 목적지 도착 여부를 갱신
			}
		}

		step[x][y][dir][bit] = val; // 현재 위치에 도달하는데 최적 값

		if (bit == 3) { // 모든 도착지에 도달한 경우
			ans = val;
			break; // 값을 저장하고 종료
		}

		for (int k = 0; k < 4; k++) {
			if (dir == k) continue; // 동일한 방향으론 1번 이상 진행 불가

			int n_x = x + X[k] - '1', n_y = y + Y[k] - '1'; // 이동할 좌표
			if (n_x < 0 || n_x >= N || n_y < 0 || n_y >= M) continue; // 범주를 벗어나도 무시
			q.emplace(n_x, n_y, k, bit, val + 1); // 탐색 큐에 삽입
		}
	}
	cout << ans << endl; // 정답 출력
}