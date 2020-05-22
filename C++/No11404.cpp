#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
// 플로이드
// 플로이드 워셜 알고리즘
// '모든 정점' 에서 '모든 노드' 까지의 최댄거리를 모두 구하는 알고리즘
// 마찬가지로 굉장히 오래 걸리는 알고리즘 중 하나

#define MAX 100 // 노드 최대 갯수
#define VAL MAX*100000 + 1 // 거리 최대 값

int map[MAX + 1][MAX + 1]; // 노드에서 노드까지의 최단거리를 기록, 갱신할 배열
int N, M;

int main() {
	scanf("%d %d", &N, &M);

	for (int k = 1; k <= N; k++)
		for (int m = 1; m <= N; m++)
			if (k == m) map[k][m] = 0;
			else map[k][m] = VAL; // 같은 경우는 0, 그 외에는 우선 도달 불가능

	int a, b, c;
	for (int k = 0; k < M; k++) {
		scanf("%d %d %d", &a, &b, &c);
		map[a][b] = min(map[a][b], c);
	} // 입력되는 여러 경로 중, 중복이 있을 수 있으므로 최소거리만을 사용

	for (int k = 1; k <= N; k++) { // 1~N 까지의 노드를 사용하여 가는 경우
		for (int m = 1; m <= N; m++) { 
			for (int n = 1; n <= N; n++) { // 모든 경로를 갱신
				map[m][n] = min(map[m][n], map[m][k] + map[k][n]);
			} // 현재 선택한 경로 vs 노드 'k'를 거쳐 가는 경로
		}
	}

	for (int k = 1; k <= N; k++) { // 결과 출력
		for (int m = 1; m <= N; m++) {
			if (map[k][m] == VAL) printf("0 ");
			else printf("%d ", map[k][m]);
		}
		printf("\n");
	}
}