#include<iostream>
#include<queue>
#include<tuple>
#include<cmath>
using namespace std;
// 낚시왕
// 규칙에 따른 시뮬레이션
// 상어가 벽에 부딪히면 방향을 꺾는 점을 수식화하는데 상당히 애를 먹음
// so, 그냥 각 경우로 나누어 처리

#define MAP 100
#define X "10211"
#define Y "11120" // 위, 아래, 오른쪽, 왼쪽

typedef tuple<int, int, int, int> datas; // 깊이, 속도, 방향, 크기

struct func {
	bool operator()(datas a, datas b) {
		return get<0>(a) != get<0>(b) ? get<0>(a) > get<0>(b) : get<3>(a) < get<3>(b);
		// 깊이 순 정렬 (오름차순), 같다면 크기 순 정렬 (내림차순)
	}
};

int R, C, M;
priority_queue<datas, vector<datas>,func> shark[2][MAP + 1]; // 각 라인별 상어 상태

int main() {
	cin >> R >> C >> M;

	for (int k = 0; k < M; k++) {
		int r, c, s, d, z; // 좌표, 속도, 방향, 크기
		cin >> r >> c >> s >> d >> z;
		shark[0][c].push({ r,s,d,z });
	}

	int ans = 0;
	for (int k = 1, idx = 0; k <= C; k++, idx = !idx) { // 낚시꾼은 맵을 한 칸씩 가로지름
		if (!shark[idx][k].empty()) { // 해당 라인에 상어가 있다면 맨 위를 잡음
			int x, y, z, w;
			tie(x, y, z, w) = shark[idx][k].top();
			ans += w;
			while (!shark[idx][k].empty() && x == get<0>(shark[idx][k].top()))
				shark[idx][k].pop(); // 그 상어가 잡아먹은 물고기들 제거
		}

		for (int c = 1; c <= C; c++) { // 맵의 가로를 전부 살펴봄
			while (!shark[idx][c].empty()) { // 그 라인의 모든 상어를 이동
				int r, s, d, z; // 깊이, 속도, 방향, 크기
				tie(r, s, d, z) = shark[idx][c].top();
				while (!shark[idx][c].empty() && r == get<0>(shark[idx][c].top()))
					shark[idx][c].pop();
				// 같은 공간에 있는 상어들은 전부 무시 (큰 놈에게 잡아먹혔음)
				int nx = r + (X[d] - '1') * s, ny = c + (Y[d] - '1') * s;

				// 벽에 대한 처리
				while (nx <= 0 || nx > R) {
					if (nx <= 0) nx = 2 + abs(nx);
					else nx = R - abs(nx - R);
					d = d % 2 + 1;
				}
				while (ny <= 0 || ny > C) {
					if (ny <= 0) ny = 2 + abs(ny);
					else ny = C - abs(ny - C);
					d = d % 2 + 3;
				}
				shark[!idx][ny].push({ nx,s,d,z }); // ny 번째 줄의 nx 깊이로 상어가 이동
			}
		}
	}
	cout << ans << endl;
}