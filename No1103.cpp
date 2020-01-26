#include<iostream>
#include<algorithm>
using namespace std;
// 게임
// 단순 탐색 문제로 풀려고 하였으나, 시간초과
// so, 이미 기록된 정보를 저장하는 DP 방식을 사용해야 함

#define SIZE 50
#define INF SIZE * 2000

int N, M, calc[SIZE][SIZE], visit[SIZE][SIZE];
char map[SIZE][SIZE];

int DFS(int x,int y) {
	if (x < 0 || x >= N || y < 0 || y >= M || map[x][y] == 'H') return 0; // 진행 불가하면 종료
	if (visit[x][y]) return INF; // 이미 방문한 곳이라면 빙글빙글 돌 수 있음
	if (calc[x][y])return calc[x][y]; // 이전에 계산한 값이 있다면 사용

	visit[x][y] = 1;
	int calc_x = max(DFS(x - (map[x][y] - '0'), y), DFS(x + (map[x][y] - '0'), y));
	int calc_y = max(DFS(x, y - (map[x][y] - '0')), DFS(x, y + (map[x][y] - '0'))); 
	visit[x][y] = 0; // 방문했음을 표기하고, 재귀적으로 계산
	return calc[x][y] = max(calc_x, calc_y) + 1; // 얻을 수 있는 최대값을 저장
}

int main() {
	cin >> N >> M;
	char ch;
	for (int k = 0; k < N; k++) {
		for (int m = 0; m < M; m++) {
			cin >> map[k][m];
		}
	}
	int ans = DFS(0, 0); // 정답을 얻고 조건에 따라 출력
	if (ans >= INF) cout << -1 << endl;
	else cout << ans << endl;
}