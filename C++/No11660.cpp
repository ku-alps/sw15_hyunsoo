#include<cstdio>
using namespace std;
// 구간 합 구하기 5
// 단순 배열이 아닌 2차원 배열 
// so, 각 정보는 (0,0) ~ (A,B) 까지의 모든 정보의 합을 저장
// 이후 불필요한 값을 제거하는 형식이지만 중복으로 빠지는 값이 있으므로
// 추가적인 연산 예외가 필요

#define MAX 1024

int N, M;
int datas[MAX + 1][MAX + 1]; // (0,0) ~ (A,B) 까지의 누적 합

int main() {
	scanf("%d %d", &N, &M);

	int d;
	for (int k = 1; k <= N; k++) {
		int arr[MAX + 1] = {};
		for (int m = 1; m <= N; m++) {
			scanf("%d", &d);
			arr[m] = arr[m - 1] + d; // 이번 라인의 총합
			datas[k][m] = datas[k - 1][m] + arr[m]; // 자신의 윗 줄의 총합 + 현재 라인의 누적합
		}
	}
	for (int k = 0; k < M; k++) {
		int x1, y1, x2, y2;
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		printf("%d\n", datas[x2][y2] - (datas[x2][y1 - 1] + datas[x1 - 1][y2]) + datas[x1 - 1][y1 - 1]);
	} // 좌표평면의 점을 통한 구간합 구하기
	// 다만, 중복으로 빠지는 위치는 더해줌
}