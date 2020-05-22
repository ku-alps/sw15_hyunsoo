#include<iostream>
#include<vector>
#include<queue>
#include<tuple>
#include<intrin.h> // __popcnt() 를 사용하기 위한 Visual C++ 전용 내장 라이브러리

using namespace std;
// 로봇 청소기
// BFS + DFS 를 함께 사용한 풀이

// 초기에는 각 오염구역까지의 거리를 구한 후, 거리가 작은 곳부터 선택하는 그리디 탐색을 사용
// but, 길이 하나 뿐인 경우에 다음 예외가 발생

/*
   5 5
   *....
   xxxx.
   .*o*.
   .xxxx
   ....*

   답 : 8 + 16 = 24
*/

// so, DP 를 사용한 풀이를 생각하였으나, 오염 구역의 수가 최대 10개 뿐이므로,
// 최대 10! = 3,628,800 의 시간을 소요하므로, 단순 DFS 로도 충분

#define DIRTY 10 // 오염 구역 최대 갯수
#define NUM 20 // 공간 최대 크기
#define INF 1000 // 최대 값
#define X "0121"
#define Y "1012" // X,Y 이동

int W, H; // 가로, 세로
char map[NUM][NUM]; // 공간
vector<pair<int, int>> v; // 오염 구역 좌표를 모아둔 벡터

int DFS(int road[DIRTY][NUM][NUM], int idx, int bit, int val) {
	bit |= (1 << idx); // 사용 표기

	if (__popcnt(bit) == v.size()) return val; // 모든 놈을 다 본 경우
		// __popcnt(n) : 주어진 값 n 에서 1로 세팅된 bit 수를 세는 함수
		// gcc의 경우, 별다른 선언 없이 __builtin_popcount 을 사용할 수 있음

	int ans = INF;
	for (int k = 0; k < v.size(); k++) { // 모든 오염구역까지의 거리를 판단
		if (bit & (1 << k)) continue; // 이미 사용한 공간이면 무시

		int b, c;
		tie(b, c) = v[k];
		ans = min(ans, DFS(road, k, bit, val + road[idx][b][c])); // 재귀적으로 최소 값을 뽑아냄
	}
	return ans;
}

int main() {
	while (true) {
		cin >> W >> H;
		if (W == 0 || H == 0) break; // 가로, 세로가 0 이면 종료

		v.clear(); // 오염 구역 초기화
		pair<int, int> s; // 시작점
		for (int k = 0; k < H; k++) {
			for (int m = 0; m < W; m++) { // 입력
				cin >> map[k][m]; // 지도 입력
				if (map[k][m] == '*') v.emplace_back(k, m); // 더러운 좌표 기록
				else if (map[k][m] == 'o') s = pair<int, int>(k, m); // 시작점 기록
			}
		}

		int road[DIRTY][NUM][NUM] = {}; // a 에서 출발하여 각 (b,c) 까지 도달하는데 걸리는 최소시간
		for (int k = 0; k < v.size(); k++) { // 모든 더러운 지점에 대해

			queue<pair<int, int>> node;
			node.emplace(v[k]); // 각 오염구역을 우선적으로 넣고 시작			
			while (!node.empty()) { // 큐르 모두 비울때 까지 BFS 탐색
				int x, y;
				tie(x, y) = node.front();
				node.pop();

				for (int m = 0; m < 4; m++) { // 네 방향에 대해서 처리
					int n_x = x + (X[m] - '1'), n_y = y + (Y[m] - '1');

					if (n_x < 0 || n_x >= H || n_y < 0 || n_y >= W) continue; // 범주를 벗어난 경우
					if (map[n_x][n_y] == 'x') continue; // 돌로 쌓인 경우
					if (road[k][n_x][n_y]) continue; // 이미 도달했던 곳

					road[k][n_x][n_y] = road[k][x][y] + 1; // 거리값 기록
					node.emplace(n_x, n_y); // 큐에 삽입
				}
			}
		}
		
		bool flag = true; // 도달할 수 없는 공간이 있는가?

		int ans = INF;
		for (int k = 0; k < v.size(); k++) { // 최소 값을 획득
			// 모든 놈에 대해 원점에서 연결을 확인하므로, DFS 내에 확인이 없어도 됨
			if (!road[k][s.first][s.second]) flag = false; 
			ans = min(ans, DFS(road, k, 0, road[k][s.first][s.second]));
		}
		if (flag) printf("%d\n", ans); // 가능한 경우, 획득 값
		else printf("-1\n"); // 불가능한 경우 -1
	}
}