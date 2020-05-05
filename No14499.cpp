#include<iostream>
#include<queue>
using namespace std;
// 주사위 굴리기
// 단순 구현문제이나,
// 주사위의 상태에 따라 회전 방향이 계속해서 변화
// so, 각 방향에 따른 면을 보관하여 주사위의 면 위치를 계산

#define MAP 20
#define DICE 6
#define X "11102"
#define Y "12011"
// 동, 서, 북, 남 순서로 이동 ( 값 0은 사용하지 않음 )

int H, W, x, y, N; // 높이, 너비, 좌표, 굴리기 횟수
int map[MAP][MAP], dice[DICE + 1]; // 맵, 각 주사위 면이 가진 값
queue<int> dir; // 이동 방향 명령

int main() {
	cin >> H >> W >> x >> y >> N;
	for (int k = 0; k < H; k++) { // 맵 채우기
		for (int m = 0; m < W; m++) {
			cin >> map[k][m];
		}
	}

	int d; // 이동 방향 기록
	for (int k = 0; k < N; k++) {
		cin >> d;
		dir.push(d);
	}

	// 주사위 굴리기
	int mid = 1, top = 2, right = 3; // 주사위의 정면, 위, 오른쪽 면 정보
	while (!dir.empty()) {
		int d = dir.front();
		dir.pop();

		int nx = x + X[d] - '1', ny = y + Y[d] - '1'; // 이동으로 도달할 좌표
		if (nx < 0 || nx >= H || ny < 0 || ny >= W) continue; // 밖이면 무시
		x = nx;
		y = ny;

		int save = 0; // 임시 저장용
		switch (d) { // 주사위 형태 변화
			// 마주보는 주사위 번호의 합이 7이 되므로, 이를 활용
		case 1: // 오른쪽으로 굴리면, 왼쪽 면이 가운데로 올라옴
			save = 7 - right;
			right = mid;
			mid = save;
			break;
		case 2: // 왼쪽으로 굴리면, 오른쪽 면이 가운데로 올라옴
			save = 7 - mid;
			mid = right;
			right = save;
			break;
		case 3: // 위로 굴리면, 아래쪽 면이 가운데로 올라옴
			save = 7 - top;
			top = mid;
			mid = save;
			break;
		case 4: // 아래로 굴리면, 위쪽 면이 가운데로 올라옴
			save = 7 - mid;
			mid = top;
			top = save;
			break;
		default:
			break;
		}

		if (!map[x][y])	// 칸이 0 이면,
			map[x][y] = dice[7 - mid]; // 주사위의 바닥면을 복사
		else { // 0이 아닌 경우,
			dice[7 - mid] = map[x][y]; // 주사위에 값 복사
			map[x][y] = 0; // 칸 비우기
		}

		cout << dice[mid] << endl; // 정면을 보고 있는 면이 가진 값
	}
}