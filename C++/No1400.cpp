#include<iostream>
#include<queue>
#include<tuple>
using namespace std;
// 화물차
// 복잡한 조건을 가진 BFS 탐색 문제 (우선순위 큐 사용)
// 각 교차로마다 지나갈 수 있는 시간대가 존재하며, 이를 확인하는 과정이 상당히 복잡 

#define NUM 20
#define X "1210"
#define Y "2101" // 우, 상, 좌, 하
#define IMP "impossible"

typedef tuple<int, int, int, int> t; // 좌표, 시간, 이동 방향

struct func { // 우선순위 큐 정렬 기준
	bool operator()(t a, t b) {
		return get<2>(a) > get<2>(b);
	}
};

int N, M;
char map[NUM][NUM];
pair<int, int> s, e; // 출발점, 도착점
int cross[10][3]; // 최대 10개의 교차로, 시작 방향, 동서 (가로), 남북 (세로)
priority_queue<t, vector<t>, func> pq;

int main() {
	do {
		cin >> N >> M;
		if (!N && !M) break; // 종료값

		int cnt = 0, visit[NUM][NUM] = {}; // 방문 여부 기록
		for (int k = 0; k < N; k++) {
			for (int m = 0; m < M; m++) {
				cin >> map[k][m];
				if (map[k][m] == 'A') s = { k,m }; // 출발점
				if (map[k][m] == 'B') e = { k,m }; // 도착점
				if (map[k][m] >= '0' && map[k][m] <= '9') cnt++;
			}
		}
		for (int k = 0; k < cnt; k++) {
			int num;
			char ch;
			cin >> num >> ch; // 교차로 번호, 시작 방향

			cross[num][0] = (ch != '-') + 1; // 1 이면 가로, 2 이면 세로
			cin >> cross[num][1] >> cross[num][2]; // 각각 시간 입력
		}

		pq.push({ s.first, s.second, 0, 0 }); // 시작점에서 출발
		while (!pq.empty()) { // 교차로에서 추가처리가 필요함..
			int x, y, t, d;
			tie(x, y, t, d) = pq.top();
			pq.pop();

			if (visit[x][y]) continue; // 이미 방문했다면 무시
			visit[x][y] = t;

			for (int k = 0; k < 4; k++) { // 짝수 : 좌우, 홀수 : 상하
				int nx = x + X[k] - '1', ny = y + Y[k] - '1';
				if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue; // 범위 초과

				if (map[nx][ny] == '.') continue; // 못가는 곳
				else if (map[nx][ny] >= '0' && map[nx][ny] <= '9') { // 0~9 사이 값
					int number = map[nx][ny] - '0';
					int dir = cross[number][0]; // 시작 방향
					int total = cross[number][1] + cross[number][2]; // 전체 사이클 시간
					int delay = 1; // 기본 딜레이 1초

					if (t % total < cross[number][dir]) { // 먼저 등장한 방향
						if (k % 2 + 1 != dir) { // 방향이 일치하지 않으면 시간을 차이만큼 맞춰줌
							delay += cross[number][dir] - (t % total);
						}
					}
					else { // 다음에 등장한 방향
						if (k % 2 + 1 == dir) { // 방향이 일치하지 않으면 처리
							delay += total - (t % total);
						}
					}
					pq.push({ nx, ny, t + delay, k % 2 }); // 탐색 추가
				}
				else pq.push({ nx, ny, t + 1, k % 2 }); // 단순한 길
			}
		}
		if (visit[e.first][e.second]) cout << visit[e.first][e.second] << endl;
		else cout << IMP << endl;
	} while (true);
}