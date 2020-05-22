#include<iostream>
#include<algorithm>
using namespace std;
// 로봇 조종하기
// 다이나믹 프로그래밍
// 이동 가능한 방향은 위를 제외한 세 방향
// but, 출발, 도착 지점은 정해져 있음

// 기존에는 가장 밑 라인만 규칙에 의거하여 정의 후, DP 를 통해 풀이를 시도
// but, 재귀호출의 깊이가 과도하게 깊어져 런타임 에러를 유발
// so, 각 라인 별로 해당 지점에 도달할 수 있는 최적치를 구하는 방식으로 문제를 축소

#define NUM 1000
#define MIN NUM * NUM * -100

int N, M, map[NUM + 1][NUM + 1], sum[NUM + 1][NUM + 1];
int left[NUM + 1][NUM + 1], right[NUM + 1][NUM + 1];

void DP(int x, int y,int dir,int val) { // 1 : 오른쪽 -> 왼쪽, -1 : 왼쪽 -> 오른쪽
	if (y < 1 || y > M) return; // 인덱스 범주를 넘어서면 종료

	int v = val + map[x][y]; // 새로 얻은 인덱스
	if (v > sum[x][y]) sum[x][y] = v; // 더 큰 경우 바꿔넣음
	
	DP(x, y - dir, dir, v); // 해당 루트를 선택할 수도 있으므로, 모든 원소에 대해 반복
}

int main() {
	cin >> N >> M;
	for (int k = 1; k <= N; k++) {
		for (int m = 1; m <= M; m++) {
			cin >> map[k][m]; // 값 입력
			sum[k][m] = MIN; // 초기화
		}
	}

	for (int k = 1; k <= M; k++) {
		sum[1][k] = map[1][k];
		sum[1][k] += sum[1][k - 1]; // 좌측 값을 기반으로 받아옴
	}

	for (int k = 2; k <= N; k++) { // 중간에 모든 라인에 대해서
		for (int m = 1; m <= M; m++) { // 각 원소들에 대해
			int up_val = sum[k - 1][m]; // 자기 위쪽 최대값을 받아옴
			int v = up_val + map[k][m]; // 새로 얻은 값

			if (v > sum[k][m]) sum[k][m] = v; // 더 큰 경우 교체
			DP(k, m - 1, 1, v);
			DP(k, m + 1, -1, v); // 좌, 우로 정보를 퍼트림
		}
	}
	cout << sum[N][M] << endl; // 출력
}