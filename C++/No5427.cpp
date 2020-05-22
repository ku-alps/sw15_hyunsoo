#include<iostream>
#include<queue>
#include<tuple>
using namespace std;
// 불
// 불과 상근이 각각에 대한 BFS 탐색이 필요
// 초기값으로 인한 로직의 문제가 발생하여 오답이 출력되는 문제가 있었음

#define NUM 1000
#define X "1210"
#define Y "2101"
#define IMP "IMPOSSIBLE"

int W, H, time[NUM + 1][NUM + 1], visit[NUM + 1][NUM + 1]; // 가로, 세로, 불이 걸린 시간, 방문여부
char map[NUM + 1][NUM + 1]; // 지도

int main() {
	int N;
	cin >> N;
	while (N--) { // 테스트 케이스
		cin >> W >> H;

		queue<tuple<int, int, int>> q[2]; // BFS 용 큐 (불, 사람)
		for (int k = 1; k <= H; k++) {
			for (int m = 1; m <= W; m++) {
				cin >> map[k][m];
				time[k][m] = visit[k][m] = 0;


				if (map[k][m] == '*') q[0].emplace(k, m, 0);
				if (map[k][m] == '@') q[1].emplace(k, m, 0); // 시작 지점
			}
		}

		while (!q[0].empty()) { // 불의 이동에 대한 전처리
			int x, y, v;
			tie(x, y, v) = q[0].front();
			q[0].pop();

			if (time[x][y]) continue; // 방문한 곳이면 무시
			time[x][y] = v; // 해당 블록까지 불이 퍼지는 최소 시간

			for (int k = 0; k < 4; k++) {
				int nx = x + X[k] - '1', ny = y + Y[k] - '1';
				if (nx < 1 || nx > H || ny < 1 || ny > W) continue; // 범주 밖이면 무시
				if (map[nx][ny] == '#' || map[nx][ny] == '*') continue; // 벽이거나, 이미 불인 경우도 무시
				q[0].push({ nx,ny, v + 1 }); // 이동 정보 삽입
			}
		}

		int ans = 0;
		while (!q[1].empty()) { // 모든 경우를 살펴봄
			int x, y, v;
			tie(x, y, v) = q[1].front();
			q[1].pop();

			if (visit[x][y]) continue; // 방문한 곳이면 무시
			if (time[x][y] && v >= time[x][y]) continue; // 불이 닿는 시간보다 늦은 경우 불가능
			// 걸리는 시간의 초기 값이 0 이므로, 예외처리 필요
			visit[x][y] = 1;

			for (int k = 0; k < 4; k++) {
				int nx = x + X[k] - '1', ny = y + Y[k] - '1';
				if (nx < 1 || nx > H || ny < 1 || ny > W) { // 맵을 넘어서면 탈출 성공
					ans = v + 1; // 필요한 최소 시간
					break; // 반복문 종료
				}
				if (map[nx][ny] == '#' || map[nx][ny] == '*') continue; // 벽, 불이면 이동 불가
				q[1].push({ nx,ny, v + 1 }); // 이동 정보 삽입
			}
			if (ans) break; // 값이 있다면 반복문 종료
		}
		if (ans) cout << ans << endl;
		else cout << IMP << endl; // 나갈 수 없다면 불가능
	}
}