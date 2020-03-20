#include<iostream>
#include<tuple>
#include<queue>
#include<algorithm>
using namespace std;
// 물탱크
// 물의 수위는 높은 쪽에서 낮은 쪽으로 흐르며,
// 자신의 주위 높이와 구멍의 높이 중, 높은 값을 한계치로 갖게 됨
// so, 외부와 연결된 점을 시작점으로 우선순위 큐를 사용한 그리디적 BFS 를 사용

#define NUM 1000
#define X "0121"
#define Y "1210"
typedef tuple<int, int, int> bfs_info; // 좌표, 맞춰야 하는 물 높이

struct func { // 튜플의 우선순위 큐 정렬 공식 (높이값이 낮은 순으로 정렬)
	bool operator()(bfs_info a, bfs_info b) {
		return get<2>(a) > get<2>(b);
	}
};

int N, M, H;
int wall[NUM * 2 + 1][NUM * 2 + 1]; // 물탱크 정보
priority_queue<bfs_info, vector<bfs_info>, func> pq;
// BFS 탐색용 우선순위 큐

int main() {
	cin >> N >> M >> H;
	for (int k = 0; k <= N; k++) { // 가로 벽
		for (int m = 0; m < M; m++) {
			cin >> wall[2 * k][2 * m + 1];
			if (k == 0 || k == N) { // 해당 벽이 사이드인 경우
				if (wall[2 * k][2 * m + 1] < 0) continue; // 구멍이 없다면 무시

				// 위쪽 벽이면 아래를 선택, 아랫 벽이면 위를 선택
				pq.emplace(k - (k != 0), m, wall[2 * k][2 * m + 1]);
			}
		}
	}
	for (int k = 0; k < N; k++) { // 세로 벽
		for (int m = 0; m <= M; m++) {
			cin >> wall[2 * k + 1][2 * m];
			if (m == 0 || m == M) { // 해당 벽이 사이드인 경우
				if (wall[2 * k + 1][2 * m] < 0) continue;

				// 왼쪽 벽이면 오른쪽 선택, 오른쪽 벽이면 왼쪽 선택
				pq.emplace(k, m - (m != 0), wall[2 * k + 1][2 * m]);
			}
		}
	}

	int minus = 0; // 빠지는 물의 총 합
	while (!pq.empty()) { // 우선순위 큐 탐색
		int x, y, v; // 좌표, 맞춰야하는 물 높이
		tie(x, y, v) = pq.top();
		pq.pop();

		x = 2 * x + 1;
		y = 2 * y + 1; // 실제로 사용할 좌표로 변환

		if (wall[x][y]) continue; // 물탱크의 빈 공간은 방문 값 판단으로 사용
		wall[x][y] = 1; // 방문함

		minus += H - v; // 빼야 하는 값 계산
		for (int k = 0; k < 4; k++) { // 4 방향으로 탐색 시도
			int x_dir = X[k] - '1', y_dir = Y[k] - '1'; // 방향 값
			if (wall[x + x_dir][y + y_dir] < 0) continue; // 구멍이 없다면 무시

			int n_x = x + 2 * x_dir, n_y = y + 2 * y_dir; // 다음 물탱크 위치
			if (n_x < 0 || n_x>2 * N || n_y < 0 || n_y >2 * M) continue; // 범주를 넘어서도 무시

			pq.emplace(n_x / 2, n_y / 2, max(v, wall[x + x_dir][y + y_dir]));
			// 현재 위치를 채운 값 vs 다음 위치로 넘어갈 구멍 높이 중 큰 값을 선택 (한계치)
		}
	}
	cout << N * M * H - minus << endl; // 전체 부피에서 빼야하는 값을 제거
}