#include<iostream>
#include<algorithm>
using namespace std;
// 벽 부수고 이동하기
// DP 를 사용하여 모든 경우에 대해 판단

// 다만, 첫 탐색에서 도달에 실패한 경우, INF 값이 기록되며
// 다른 길을 통한 경로 또한 INF 값을 받는 문제가 발생
// so, 벽을 부순 여부를 기준으로, 정보를 나눠서 기록할 필요가 존재

#define NUM 1000
#define INF NUM * NUM
#define X "0121"
#define Y "1210"

int H, W, len[NUM + 1][NUM + 1][2]; // 높이, 너비, DP값
char map[NUM + 1][NUM + 1]; // 사용될 맵

int DP(int x, int y, bool canBreak) { // 현재 좌표, 벽을 부술 수 있는가?
	if (len[x][y][canBreak]) return len[x][y][canBreak]; // 이미 방문한 경우
	if (x == H && y == W) return len[x][y][canBreak] = 1; // 끝에 도착한 경우, 1을 반환

	len[x][y][canBreak] = INF;
	for (int k = 0; k < 4; k++) {
		int n_x = x + X[k] - '1', n_y = y + Y[k] - '1'; // 이동할 좌표
		if (n_x < 1 || n_x > H || n_y < 1 || n_y > W) continue; // 허용치를 벗어나면 무시

		if (map[n_x][n_y] == '1') { // 본 좌표가 벽이고, 부술 기회가 남아있다면 
			if (canBreak) {
				len[x][y][canBreak] = min(len[x][y][canBreak], DP(n_x, n_y, !canBreak) + 1); // 해당 벽을 부수고 진행
			}
		}
		else { // 벽이 아니라면 한 칸 이동
			len[x][y][canBreak] = min(len[x][y][canBreak], DP(n_x, n_y, canBreak) + 1);
		}
	}
	return len[x][y][canBreak];
}

int main() {
	cin >> H >> W;
	for (int k = 1; k <= H; k++) { // 지도 입력
		for (int m = 1; m <= W; m++) {
			cin >> map[k][m];
		}
	}
	int ans = DP(1, 1, true);
	cout << (ans != INF ? ans : -1) << endl; // 재귀 호출
}