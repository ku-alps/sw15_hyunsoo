#include<iostream>
#include<queue>
#include<tuple>
using namespace std;
// 탈출
// BFS 를 사용하여 S 에서 D 로 가는 최단경로를 파악
// 다만, 시간에 따라 물이 함께 확장한다는 점과
// 시간을 기록해놓는 방식에서 물이 도달하지 못한 공간에 대한 예외처리가 따로 필요했음

#define NUM 50
#define MAX NUM * NUM // 최대 값

#define X "0121" // X축 이동
#define Y "1210" // Y축 이동

char map[NUM][NUM]; // 입력
int R, C, time[NUM][NUM], visit[NUM][NUM]; // 가로, 세로, 물의 도달 시간, 고슴도치 방문 여부
queue<tuple<int, int, int>> S, W; // 고슴도치 좌표 큐, 물 좌표 큐

int main() {
	cin >> R >> C;
	for (int k = 0; k < R; k++) {
		for (int m = 0; m < C; m++) {
			cin >> map[k][m];
			if (map[k][m] == '*') W.push(tuple<int, int, int>(k, m, 0));
			else if (map[k][m] == 'S') S.push(tuple<int, int, int>(k, m, 0));
			else if (map[k][m] == 'D') time[k][m] = MAX;
		} // 입력
	}

	// 물 채우기
	while (!W.empty()) {
		tuple<int, int, int> water = W.front();
		W.pop();
		int w_x = get<0>(water), w_y = get<1>(water); // 물의 좌표값
		for (int k = 0; k < 4; k++) {
			int n_x = w_x + X[k] - '1', n_y = w_y + Y[k] - '1';
			if (n_x < 0 || n_x >= R || n_y < 0 || n_y >= C) continue; // 범주를 넘어서면 무시
			if (time[n_x][n_y] || map[n_x][n_y] == '*' || map[n_x][n_y] == 'X') continue; // 이미 방문했거나, 갈수없다면 건너뜀
			time[n_x][n_y] = get<2>(water) + 1; // 물이 도달하는데 걸리는 시간을 기록
			W.push(tuple<int, int, int>(n_x, n_y, time[n_x][n_y])); // 삽입
		}
	}

	// 고슴도치 이동
	int ans = 0; // 최단거리 (정답)
	while (!S.empty()) { // 모든 고슴도치의 가능성을 판단
		tuple<int, int, int> ani = S.front();
		S.pop();

		int a_x = get<0>(ani), a_y = get<1>(ani); // 고슴도치 좌표값
		if (map[a_x][a_y] == 'D') {
			ans = get<2>(ani);
			break; // 목적지에 도달했다면 시간을 저장하고 종료
		}

		for (int k = 0; k < 4; k++) { // 모든 방향에 대해 이동
			int n_x = a_x + X[k] - '1', n_y = a_y + Y[k] - '1';
			if (n_x < 0 || n_x >= R || n_y < 0 || n_y >= C) continue; // 범주를 넘어서면 무시
			if (visit[n_x][n_y]) continue; // 이미 방문한 곳도 넘어감
			visit[n_x][n_y] = 1;

			if ((time[n_x][n_y] <= get<2>(ani) + 1) && !(!time[n_x][n_y] && map[n_x][n_y] == '.')) continue; 
			// 해당 지역이 그 시점에 물로 차있는 경우 ( 단, '.' 이면서 0 인 경우는, 물이 도달하지 않은 곳이므로 예외처리 )
			S.push(tuple<int, int, int>(n_x, n_y, get<2>(ani) + 1)); // 큐에 삽입
		}
	}
	if (ans) cout << ans << endl; // 조건에 따라 출력
	else cout << "KAKTUS" << endl;
}