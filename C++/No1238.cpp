#include<iostream>
#include<algorithm>
using namespace std;
// 파티
// 각 학생은 특정 위치로 모여야 하며, 도로는 단방향성을 띄므로
// 오고가는 경로는 다를 수 있음
// so, 모든 경우에 대한 최단거리를 구하는 플로이드 워셜 알고리즘이 필요

#define NUM 1000
#define INF 100 * NUM

int N, M, X;
int w[NUM + 1][NUM + 1]; // a 에서 b 로 가는 최단경로

int main() {
	cin >> N >> M >> X;
	for (int k = 0; k < M; k++) {
		int a, b, c;
		cin >> a >> b >> c;
		w[a][b] = c; // 알고리즘 초기 세팅
	}

	for (int k = 1; k <= N; k++) {
		for (int m = 1; m <= N; m++) {
			w[k][m] = w[k][m] ? w[k][m] : INF; // 입력된 값이 있으면 사용, 아니면 무한
		}
	}

	for (int k = 1; k <= N; k++) { // 플로이드 워셜 알고리즘 (최단거리 탐색)
		for (int m = 1; m <= N; m++) {
			for (int i = 1; i <= N; i++) {
				w[m][i] = min(w[m][i], w[m][k] + w[k][i]);
			}
		}
	}
	
	int ans = 0;
	for (int k = 1; k <= N; k++) {
		if (k == X) continue; // 자기 자신인 경우 무시
		ans = max(ans, w[X][k] + w[k][X]); // 왕복 시간이 가장 오래걸리는 것을 선택
	}
	cout << ans << endl;
}