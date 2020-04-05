#include<iostream>
#include<queue>
#include<tuple>
using namespace std;
// 미로 탈출
// 버튼을 누를 경우, 모든 위치가 아닌 현재의 행렬만 뒤집히므로
// 각 행과 열의 버튼 활성화 값을 따로 저장하고 처리해야 함

// 해당 문제는 BFS 탐색 문제이며, 각 탐색마다 주어지는 상태 정보는 모두 다를 수 있음
// so, 이를 비트 마스킹으로 들고다니는 방식을 사용하며
// dp 정보를 따로 보관할 필요가 존재

// 맵의 최대 크기는 7*7 이므로, 행열 정보는 각각 7 Bit 만으로 충분

#define NUM 7
#define ROOM ( 1<< 8 )
#define INF 2000
#define X "1210"
#define Y "0121"

#define VER (1 << 3) + (1 << 1) // 위, 아래 ( 1010 )
#define HOR (1 << 2) + (1 << 0) // 왼, 오른쪽 ( 0101 )
#define ALL VER + HOR // 사방 ( 1111 )
#define NON 0 // 문 없음

typedef tuple<int, int, int, int, int> dp_data;
// 좌표, 가로 세로의 뒤집힘 여부, 걸린 시간

struct func {
	bool operator()(dp_data a, dp_data b) { // 걸린 시간이 작은 순으로 선택
		return get<4>(a) > get<4>(b);
	}
};

int N, M, map[NUM][NUM][2];
int dp[NUM][NUM][ROOM][ROOM]; // 미모아이제이션 ( 좌표, 열 비트, 행 비트 )
priority_queue<dp_data, vector<dp_data>, func> q; // BFS 탐색용

int main() {
	cin >> N >> M;
	for (int k = 0; k < N; k++) { // 맵 구성
		for (int m = 0; m < M; m++) {
			char ch;
			cin >> ch;
			if (ch == 'A') { // 사방에 문
				map[k][m][0] = ALL;
				map[k][m][1] = ALL;
			}
			if (ch == 'B') { // 문 없음
				map[k][m][0] = NON;
				map[k][m][1] = NON;
			}
			if (ch == 'C') { // 세로 문
				map[k][m][0] = VER;
				map[k][m][1] = HOR;
			}
			if (ch == 'D') { // 가로 문
				map[k][m][0] = HOR;
				map[k][m][1] = VER;
			}
		}
	}

	// BFS 탐색 (미모아이제이션)
	q.emplace(0, 0, 0, 0, 0);
	while (!q.empty()) {
		int x, y, ver, hor, t; // 좌표, 버튼이 활성화된 라인, 걸린 시간
		tie(x, y, ver, hor, t) = q.top();
		q.pop();

		if (dp[x][y][ver][hor]) continue; // 이미 방문했다면 종료
		dp[x][y][ver][hor] = t; // 시간 기록

		if (x == N - 1 && y == M - 1) { // 원하는 곳에 도달한 경우
			cout << t << endl; // 출력 후 종료
			return 0;
		}

		int room = ((ver & (1 << x) ? 1: 0) + (hor & (1 << y) ? 1: 0)) % 2; // 현재 방이 어떤 형태인가?
		for (int k = 0; k < 4; k++) { // 좌, 하, 우, 상
			if (map[x][y][room] & (1 << k)) { // 해당 방향에 문이 있는 경우
				int n_x = x + X[k] - '1', n_y = y + Y[k] - '1'; // 새로운 좌표
				if (n_x < 0 || n_x >= N || n_y < 0 || n_y >= M) continue; // 범주를 벗어나면 무시

				// 이동할 방에 대해서도 문을 검사함
				int n_room = ((ver & (1 << n_x) ? 1 : 0) + (hor & (1 << n_y) ? 1 : 0)) % 2; 
				if (map[n_x][n_y][n_room] & (1 << k)) { // 이동할 곳 또한 문이 있다면
					q.emplace(n_x, n_y, ver, hor, t + 1);
				}
				if (map[n_x][n_y][(n_room + 1) % 2] & (1 << k)) { // 버튼을 눌러야 가능하다면
					q.emplace(n_x, n_y, ver ^ (1 << x), hor ^ (1 << y), t + 2);
				}
			}
		}
	}
	cout << -1 << endl; // 중간에 끝나지 않는다면 길을 찾지 못한 것 ( 실패 )
	return 0;
}