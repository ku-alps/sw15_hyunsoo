#include<cstdio>
#include<vector>
using namespace std;
// 트리와 쿼리
// 지정된 노드를 기준으로 DFS 탐색
// 이후 서브트리가 포함된 노드를 모두 더하여 기록

#define NUM 100000 // 10의 5승

int N, R, Q, node[NUM + 1], visit[NUM + 1];
vector<int> v[NUM + 1];

int DFS(int idx) {
	if (visit[idx]) return 0;
	visit[idx] = 1;
	for (int edge : v[idx]) {
		node[idx] += DFS(edge); // 이미 방문했다면 -1 로 없어짐
	}
	return node[idx] += 1; // 자신을 포함하여 기록
}

int main() {
	scanf("%d %d %d", &N, &R, &Q); // 노드 수, 루트, 쿼리 수
	for (int k = 1; k < N; k++) {
		int a, b;
		scanf("%d %d", &a, &b);
		v[a].push_back(b);
		v[b].push_back(a); // 방향성이 없으므로 양쪽 모두 입력
	}
	DFS(R); // 루트를 중심으로 DFS 탐색
	for (int k = 0; k < Q; k++) {
		int query;
		scanf("%d", &query);
		printf("%d\n", node[query]); // 쿼리 결과 출력
	}
}