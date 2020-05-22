#include<iostream>
#include<vector>
#include<queue>
#include<tuple>
using namespace std;
// 불켜기
// BFS 탐색으로 코드가 구성되지만, 왔던 길을 되돌아 갈 수 있다는 조건이 존재
// so, 이를 처리하기 위해 도달했지만 불이 꺼저 진입하지 못한 방에 대해
// 따로 정보를 기록해두는 방식을 사용

#define NUM 100
#define X "1210"
#define Y "2101"

int N, M, on[NUM + 1][NUM + 1], visit[NUM + 1][NUM + 1], fail[NUM + 1][NUM + 1];
vector<pair<int, int>> v[NUM + 1][NUM + 1]; // 전구 스위치 정보
queue<pair<int, int>> q; // 탐색용 큐


int main() {
	cin >> N >> M;
	for (int k = 0; k < M; k++) {
		int x, y, a, b;
		cin >> x >> y >> a >> b;
		v[x][y].push_back({ a,b }); // x,y 좌표에선 a, b 를 킬 수 있음
	}

	int ans = 1;
	on[1][1] = 1;
	q.push({ 1,1 }); // 시작 좌표

	// BFS 탐색
	while (!q.empty()) {
		int x, y;
		tie(x, y) = q.front();
		q.pop();

		if (!on[x][y]) {  // 만일 불켜진 곳이 아니면 표기 후 무시
			fail[x][y] = 1;
			continue;
		}
		if (visit[x][y]) continue; // 이미 도달했던 곳이여도 무시
		visit[x][y] = 1;

		for (pair<int, int> pos : v[x][y]) {
			ans += on[pos.first][pos.second] ? 0 : 1; // 이미 켜져있던 방이면 계산에서 제함
			on[pos.first][pos.second] = 1; // 해당 지점의 불을 켬
			if (fail[pos.first][pos.second]) { // 이전에 불이 없어서 실패한 공간이면
				q.push({ pos.first, pos.second }); // 해당 공간을 넣고
				fail[pos.first][pos.second] = 0; // 세팅 초기화
			}
		}

		for (int k = 0; k < 4; k++) { // 네 방향의 BFS
			int nx = x + X[k] - '1', ny = y + Y[k] - '1';
			if (nx < 1 || nx > N || ny < 1 || ny > N) continue; // 범위 밖
			q.push({ nx,ny });
		}
	}

	cout << ans << endl;
}