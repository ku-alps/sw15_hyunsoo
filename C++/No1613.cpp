#include<cstdio>
using namespace std;
// 역사
// 대소 관계를 갖고 있음을 유의하여 입력을 단방향 엣지로 변환
// 단순 탐색의 경우 쿼리 수로 인해 시간초과가 발생하므로,
// 모든 경로에 대한 연산을 먼저 처리 후, 쿼리를 빠르게 수행

#define NUM 400

int map[NUM + 1][NUM + 1]; // a 에서 b 로의 대소관계가 성립하는가?

int main() {
	int N, K;
	scanf("%d %d", &N, &K);
	for (int k = 0; k < K; k++) {
		int a, b;
		scanf("%d %d", &a, &b);
		map[a][b] = 1;
		// 대소 관계이므로, 방향성을 갖고 있다고 생각할 수 있음 ( 빠른 사건 -> 느린 사건 )
	}
	
	// 플로이드-워셜 응용
	for (int k = 1; k <= N; k++) { // k 를 거쳐 가는 경우
		for (int m = 1; m <= N; m++) {
			for (int i = 1; i <= N; i++) { // 맵 전체 갱신 ( 각 사건의 번호는 1~N 까지 )
				map[m][i] = map[m][i] || (map[m][k] && map[k][i]); 
				// 본래 대소관계가 명확하거나, 해당 경우의 대소관계가 모두 명확한 경우 OK
			}
		}
	}

	int S;
	scanf("%d", &S);
	while (S--) {
		int a, b;
		scanf("%d %d", &a, &b);
		printf("%d\n", map[b][a] - map[a][b]);
		// a 가 빠른 사건인 경우, map[a][b] 에 값이 저장됨 ( -1 출력 )
		// a 가 느린 사건인 경우, map[b][a] 에 값이 저장됨 ( 1 출력 )
		// 그 외엔 도달하는 경로가 명확하지 않으므로 모두 0 출력
	}
}