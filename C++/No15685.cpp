#include<iostream>
#include<vector>
using namespace std;
// 드래곤 커브
// 엣지의 좌표로 구성하는것이 아닌, 시작 꼭짓점과 이동 방향으로 표현
// 각 꼭짓점이 모두 채워졌는가를 비트마스킹으로 확인

#define SIZE 100
#define NUM 20
#define FULL ( 1 << 4 ) - 1
#define X "1012"
#define Y "2101"

int N, map[SIZE][SIZE]; // 0~100 까지의 좌표값 내부의 공간 좌표는 0~99 (100개) 를 사용
vector<int> v[NUM]; // 각 커브의 엣지 방향

int main() {
	cin >> N;
	for (int k = 0; k < N; k++) {
		int x, y, d, g;
		cin >> y >> x >> d >> g;
		// 해당 문제에선 x 좌표를 가로, y 좌표를 세로로 사용하므로
		// 해당 코드에선 입력을 반대로 사용 ( x : 세로, y : 가로 )

		v[k].push_back(d); // 시작 방향
		for (int m = 0; m < g; m++) { // 세대만큼 반복
			for (int i = v[k].size() - 1; i >= 0; i--) {
				// 현재까지 쌓인 방향을 회전시켜 연결
				v[k].push_back((v[k][i] + 1) % 4);
				// RIGHT = 0, UP = 1, LEFT = 2, DOWN = 3 이며
				// 각각은 90도 회전 시, 다음 형태로 방향이 뒤집힘
			}
		}

		// 시작지점에 대한 처리
		if (x - 1 >= 0 && x - 1 < SIZE && y - 1 >= 0 && y - 1 < SIZE) map[x - 1][y - 1] |= (1 << 0);
		if (x - 1 >= 0 && x - 1 < SIZE && y >= 0 && y < SIZE) map[x - 1][y] |= (1 << 1);
		if (x >= 0 && x < SIZE && y - 1 >= 0 && y - 1 < SIZE) map[x][y - 1] |= (1 << 2);
		if (x >= 0 && x < SIZE && y >= 0 && y < SIZE) map[x][y] |= (1 << 3);

		// 이동한 꼭지점에서의 처리
		for (int dir : v[k]) {
			x += X[dir] - '1';
			y += Y[dir] - '1';

			if (x - 1 >= 0 && x - 1 < SIZE && y - 1 >= 0 && y - 1 < SIZE) map[x - 1][y - 1] |= (1 << 0);
			if (x - 1 >= 0 && x - 1 < SIZE && y >= 0 && y < SIZE) map[x - 1][y] |= (1 << 1);
			if (x >= 0 && x < SIZE && y - 1 >= 0 && y - 1 < SIZE) map[x][y - 1] |= (1 << 2);
			if (x >= 0 && x < SIZE && y >= 0 && y < SIZE) map[x][y] |= (1 << 3);
		}
	}

	int cnt = 0; // 모든 꼭지점이 채워진 경우, 1 + 2 + 4 + 8 = 15의 값을 갖고있음
	for (int k = 0; k < SIZE; k++) {
		for (int m = 0; m < SIZE; m++) {
			if (map[k][m] == FULL) cnt += 1;
		}
	}
	cout << cnt << endl;
}