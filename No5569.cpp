#include<iostream>
using namespace std;
// 출근 경로
// 기본적으로 경로 규칙 문제
// but, 회전에 조건이 붙으면서 몇가지 반례가 생기므로 주의

#define MAX 100

int W, H; // 가로세로
int verti[MAX + 2][MAX + 2], horiz[MAX + 2][MAX + 2]; 
// 각각 세로, 가로로 들어오는 경우의 수

int main() {
	cin >> W >> H;

	for (int k = 1; k <= H; k++) {
		for (int m = 1; m <= W; m++) {
			if (k == 1 && m == 1) { // 시작지점 예외처리
				verti[1][1] = 1;
				horiz[1][1] = 1;
				continue;
			}

			// 기존 진행 방향은 그대로 쓸 수 있음 (영향 x)
			if (k <= H) verti[k][m] += verti[k - 1][m];
			if (m <= W) horiz[k][m] += horiz[k][m - 1];
			verti[k][m] %= 100000;
			horiz[k][m] %= 100000; // 조건에 맞춰서 값 크기 조정

			if (k + 2 <= H) {
				// 가로 방향에서 꺾어서 세로로 2칸 올라갈 수 있는 경우
				verti[k + 2][m] += horiz[k][m];
			}
			else if (m == W) {
				// 공간은 없지만 꺾으면 끝인경우
				verti[k + 1][m] += horiz[k][m];
			}
			if (m + 2 <= W) {
				// 세로 방향에서 꺾어서 가로로 2칸 이동할 수 있는 경우
				horiz[k][m + 2] += verti[k][m];
			}
			else if (k == H) {
				// 공간은 없지만 꺾으면 끝인경우
				horiz[k][m + 1] += verti[k][m];
			}
		}
	}
	cout << (verti[H][W] + horiz[H][W]) % 100000 << endl; // 각 방향의 경로 합 = 정답
}