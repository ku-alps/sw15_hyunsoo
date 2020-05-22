#include<iostream>
#include<queue>
#include<tuple>
using namespace std;
// 불!
// BFS 탐색 문제

#define NUM 1000
#define X "1210"
#define Y "2101"

int R, C, visit[NUM][NUM];
char map[NUM][NUM];
pair<int, int> J;
queue<tuple<int, int, int, bool>> q; // 좌표, 시간, 지훈이 or 불

int main() {
	cin >> R >> C;
	for (int k = 0; k < R; k++) {
		for (int m = 0; m < C; m++) {
			cin >> map[k][m];
			if (map[k][m] == 'J') J = { k,m }; // 지훈이인 경우, 좌표 기록
			if (map[k][m] == 'F') q.push({ k,m,0,false }); // 불인 경우, 큐에 삽입
		}
	}
	q.push({ J.first,J.second,0,true });
	// 불이 우선적으로 움직인 후, 지훈이가 움직일 수 있음

	int ans = 0; // 초기 값은 0
	while (!q.empty()) {
		int x, y, v;
		bool f;
		tie(x, y, v, f) = q.front();
		q.pop();

		if (visit[x][y]) continue; // 이미 방문한 곳이면 넘어감
		visit[x][y] = 1;

		for (int k = 0; k < 4; k++) {
			int nx = x + X[k] - '1', ny = y + Y[k] - '1';
			if (nx < 0 || nx >= R || ny < 0 || ny >= C) {
				if (f) { // 지훈이가 영역 밖으로 나간다면 종료
					ans = v + 1;
					break;
				}
				continue; // 불인 경우, 무시
			}
			if (map[nx][ny] == '#') continue; // 이동할 공간이 벽인 경우도 무시
			q.push({ nx,ny,v+1,f }); // 그 외엔 이동 가능
		}
		if (ans) break; // 값을 찾았다면 종료
	}
	if (ans) cout << ans << endl; // 값이 있다면, 탈출 성공
	else cout << "IMPOSSIBLE" << endl; // 실패
}