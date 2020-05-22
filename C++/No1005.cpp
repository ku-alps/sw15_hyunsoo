#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
// ACM Craft
// 단순 DFS 로만 문제를 해결해려 했으나, 시간 초과
// so, 메모아이제이션 기법을 추가함
// +) 건물 건설 비용이 0인 경우, 누적비용만으로는 반복적인 재탐색이 이루어짐
// 따라서 방문여부와 누적비용 배열을 분리하여 값을 처리하여 해결

#define NUM 1000

int N, K;
int cost[NUM + 1], visit[NUM + 1], val[NUM + 1]; // 각 건물 비용, 방문, 누적비용
vector<int> v[NUM + 1]; // 각 건물을 짓기 위해 필요한 선행 건물

int DFS(int idx) { // 건물 번호로 DFS 탐색
	if (visit[idx]) return val[idx];
	visit[idx] = 1;
	for (int next : v[idx]) { // 짓기위해 선행되어야 하는 건물
		val[idx] = max(val[idx], DFS(next));
	}
	return val[idx] += cost[idx]; // 해당 지점의 건물 비용을 포함한 값 반환
}

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d %d", &N, &K);

		for (int k = 1; k <= N; k++) {
			scanf("%d", &cost[k]); // 비용
			v[k].clear(); // 초기화
			visit[k] = val[k] = 0;
		}
		for (int k = 0; k < K; k++) { // 엣지
			int a, b;
			scanf("%d %d", &a, &b);
			v[b].push_back(a); // b 를 짓기위해선 a가 필요
		}

		int idx;
		scanf("%d", &idx); // 이기기 위해 지어야 하는 건물
		printf("%d\n", DFS(idx));
	}
}