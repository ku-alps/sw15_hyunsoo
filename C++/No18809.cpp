#include<iostream>
#include<vector>
#include<tuple>
#include<queue>
#include<algorithm>
using namespace std;
// Gaaaaaaaaaarden
// 사용되는 배양액의 종류가 2개 뿐이며, 해당 문제는 배양액이 샤용되는 지점의 '조합'
// so, 중복되는 값을 미모아이제이션으로 처리하여 시간 단축이 가능
// 또한, 두 배양액이 만나 꽃을 핀 지점은 확장이 불가능하므로 예외처리가 필요

#define NUM 50
#define BIT ( 1 << 10 ) // 미모아이제이션 요구 크기값
#define X "0121"
#define Y "1210"

int N, M, G, R;
int map[NUM][NUM], cnt[BIT][BIT]; // 지도, 탐색용 stack 정보
vector<pair<int, int>> spot; // 배양액을 놓을 수 있는 장소

int DFS(int c, int idx, int g_bit, int r_bit) { // 조합 생성 및 BFS 탐색 함수
	if (!c) { // 0인 경우 (초록색)
		if (idx == G) { // 모든 초록색을 다 선택한 경우
			int ans = 0;
			for (int k = 0; k < spot.size(); k++) {
				if ((g_bit | r_bit) & (1 << k)) continue; // 이미 사용한 지점은 건너감
				ans = max(ans, DFS(1, 1, g_bit, r_bit | (1 << k)));
			}
			return ans;
		}
		int ans = 0;
		for (int k = 0; k < spot.size(); k++) { // 아직 초록색을 선택 중인 경우
			if ((g_bit | r_bit) & (1 << k)) continue; // 이미 사용한 지점은 건너감
			ans = max(ans, DFS(c, idx + 1, g_bit | (1 << k), r_bit));
		}
		return ans;
	}

	if (idx == R) { // 모든 빨간색을 다 선택한 경우
		if (cnt[g_bit][r_bit]) return cnt[g_bit][r_bit]; // 이전에 처리한 적이 있다면 그 값을 반환

		int bfs[NUM][NUM][2] = {};
		queue<tuple<int, int, int, int>> q; // BFS 용 큐
		queue<tuple<int, int, int, int>> s_q; // 확장용 큐

		int s_bit = g_bit; // 연산용 비트
		for (int k = 0; s_bit != 0;k++) { // 초록 배양액을 놓을 자리
			if (s_bit % 2) { // 해당 번호의 자리를 사용한 경우
				int x, y;
				tie(x, y) = spot[k];
				q.emplace(x, y, 0, 1); // BFS 큐에 삽입
			}
			s_bit /= 2;
		}

		s_bit = r_bit;
		for (int k = 0; s_bit != 0; k++) { // 빨강 배양액을 놓을 자리
			if (s_bit % 2) {
				int x, y;
				tie(x, y) = spot[k];
				q.emplace(x, y, 1, 1);
			}
			s_bit /= 2;
		}
		
		while (q.size() || s_q.size()) { // 둘 모두 비어있을 때 까지 반복
			while (!q.empty()) { // BFS 탐색
				int x, y, c, v;
				tie(x, y, c, v) = q.front();
				q.pop();

				if (!map[x][y]) continue; // 갈 수 없는 물인 경우 무시

				if (bfs[x][y][c]) continue; // 이미 방문한 곳 무시
				bfs[x][y][c] = v; // 해당 시점에 방문함을 표기

				if (bfs[x][y][!c]) continue; // 역 방향도 이미 방문한 경우라면 확장 큐에 삽입 x (중복 제거)
				s_q.emplace(x, y, c, v);
			}

			while (!s_q.empty()) { // 해당 지점에서 다른 곳으로 확장할 것인가?
				int x, y, c, v;
				tie(x, y, c, v) = s_q.front();
				s_q.pop();

				if (bfs[x][y][!c]) { // 다른 색이 이미 도달한 경우
					if (bfs[x][y][!c] == bfs[x][y][c]) cnt[g_bit][r_bit] += 1; // 같은 시간대에 도달하면 꽃을 피움
					continue; // 성공 여부와 관계없이 더 이상 확장 불가
				}

				for (int k = 0; k < 4; k++) { // 네 방향으로 확장
					int n_x = x + X[k] - '1', n_y = y + Y[k] - '1';
					if (n_x < 0 || n_x >= N || n_y < 0 || n_y >= M) continue; // 범주를 벗어나면 무시
					q.emplace(n_x, n_y, c, v + 1);
				}
			}
		}
		return cnt[g_bit][r_bit] = cnt[g_bit][r_bit] ? cnt[g_bit][r_bit] : -1; // 꽃이 아예 없으면 -1
	}

	int ans = 0;
	for (int k = 0; k < spot.size(); k++) { // 아직 빨간색을 선택 중인 경우
		if ((g_bit | r_bit) & (1 << k)) continue; // 이미 사용한 지점은 건너감
		ans = max(ans, DFS(c, idx + 1, g_bit, r_bit | (1 << k)));
	}
	return ans;
}

int main() {
	cin >> N >> M >> G >> R;

	for (int k = 0; k < N; k++) {
		for (int m = 0; m < M; m++) { // 맵 입력
			cin >> map[k][m];
			if (map[k][m] == 2) spot.emplace_back(k, m); // 배양액을 뿌릴 수 있는 곳
		}
	}

	int ans = DFS(0, 0, 0, 0);
	cout << (ans < 0 ? 0 : ans) << endl; // 음수인 경우, 0으로 출력 ( 만들어낸 꽃이 없음 )
}