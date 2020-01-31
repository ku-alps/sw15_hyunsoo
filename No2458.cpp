#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
// 키 순서
// 자신의 앞, 뒤에 있는 사람의 수가 전체 인원과 동일하면
// 순서를 명확히 알 수 있음
// so, 해당 조건을 만족하는 대상을 탐색하는 방식으로 접근

// 다만 처음엔 메모아이제이션을 사용하려했으나, 
// 이 경우 각 노드가 자신이 방문한 노드정보를 기록하고 있어야함
// 사용할 경우, 비트 마스크 방식이 필요하나, 메모리 부족 ( 2의 500 제곱승 )
// so, 가장 단순한 전체탐색 방식을 사용

#define MAX 500

int N, M, visit[MAX + 1], total[MAX + 1];
vector<int> v[MAX + 1], r_v[MAX + 1];

int DFS(int idx) { // 뒷쪽 순번 개수 탐색
	if (visit[idx]) return 0; // 이미 방문한 경우 값 포함 x
	visit[idx] = 1;

	int cntB = 0;
	for (int k = 0; k < v[idx].size(); k++) {
		cntB += DFS(v[idx][k]); // 확실히 자신의 뒤에 등장하는 상대 갯수 체크
	}
	return cntB + 1; // 자신을 포함한 개수 반환
}

int r_DFS(int idx) { // 앞쪽 순번 개수 탐색
	if (visit[idx]) return 0; // 이미 방문한 경우 값 포함 x
	visit[idx] = 1;

	int cntF = 0;
	for (int k = 0; k < r_v[idx].size(); k++) {
		cntF += r_DFS(r_v[idx][k]); // 확실히 자신의 앞에 등장하는 상대 갯수 체크
	}
	return cntF + 1; // 자신을 포함한 개수 반환
}

int main() {
	scanf("%d %d", &N, &M);
	int a, b;
	for (int k = 0; k < M; k++) {
		scanf("%d %d", &a, &b);

		v[a].push_back(b);
		r_v[b].push_back(a); // 엣지 추가 ( 정방향, 역방향 )
	}

	for (int k = 1; k <= N; k++) { // 모든 노드에 대해 자신의 뒤 노드 수 탐색
		for (int m = 1; m <= N; m++) visit[m] = 0;
		total[k] += DFS(k); // 탐색 정보에 삽입
	}

	for (int k = 1; k <= N; k++) { // 모든 노드에 대해 자신의 앞 노드 수 탐색
		for (int m = 1; m <= N; m++) visit[m] = 0;
		total[k] += r_DFS(k); // 탐색 정보에 삽입
	}
	
	int people = 0;
	for (int k = 1; k <= N; k++) {
		if (total[k] - 1 == N) people++; // 모든 놈이 자신의 앞뒤에 있다면
	}
	printf("%d\n", people);
}
