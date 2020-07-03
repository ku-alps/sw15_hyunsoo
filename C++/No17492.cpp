#include<iostream>
using namespace std;
// 바둑알 점프
// 맵의 크기가 10으로 작은 편
// so, 완전 탐색으로 성공 여부를 판단

#define MAX 10
#define X "00012221"
#define Y "01222100"

int N, map[MAX][MAX];

bool DFS() {
	bool ans = false; // 자신의 하위 노드의 성공 여부
	int cnt = 0; // 바둑알 수
	for (int x = 0; x < N; x++) {
		for (int y = 0; y < N; y++) {

			if (map[x][y] == 2) { // 해당 위치가 바둑알이면 점프 시도
				cnt += 1; // 바둑알 수 증가

				for (int k = 0; k < 8; k++) { // 8방향으로 점프 가능
					int nx = x + X[k] - '1', ny = y + Y[k] - '1'; // 인접한 곳
					int nnx = nx + X[k] - '1', nny = ny + Y[k] - '1'; // 이동할 곳

					if (nnx < 0 || nnx >= N || nny < 0 || nny >= N) continue; // 범위 밖은 무시
					if (map[nx][ny] == 2 && map[nnx][nny] == 0) {
						// 인접한 곳이 바둑돌이고, 이동할 곳이 빈 공간인 경우만 가능
						map[x][y] = map[nx][ny] = 0;
						map[nnx][nny] = 2;
						ans |= DFS(); // DFS 탐색
						map[x][y] = map[nx][ny] = 2;
						map[nnx][nny] = 0; // 복구
					}
				}
			}
		}
	}
	return ans || (cnt == 1); // 1인 경우면 성공, 그 외는 실패
}

int main() {
	cin >> N;

	for (int k = 0; k < N; k++) { // 전체 맵 입력
		for (int m = 0; m < N; m++) {
			cin >> map[k][m];
		}
	}
	cout << (DFS() ? "Possible" : "Impossible") << endl; // 결과에 따라 출력
}