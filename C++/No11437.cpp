#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
// LCA 2 ( Longest Common Ancient )

#define MAX 50000

int N, M;
int depth[MAX + 1], visit[MAX + 1];
vector<int> v[MAX + 1];
vector<int> edges[MAX + 1];

void DFS(int a, int b) {
	if (visit[b]) return; // 이미 방문한 노드면 퇴근 (역 엣지의 경우)
	visit[b] = 1;

	// 루트인 1을 기점으로 트리가 만들어지므로,
	// a는 부모, b는 자식이라는 가정이 성립 ( 루트에 가까운 노드가 반드시 먼저 방문 )
	depth[b] = depth[a] + 1; // 부모노드 깊이 + 1
	v[b].push_back(a); // 부모 인덱스 정보를 기록
	int mul = 0, idx = a;
	while (mul < v[idx].size()) {
		v[b].push_back(v[idx][mul]); // 해당 위치의 2의 승수 자리 부모를 저장
		idx = v[idx][mul]; // 다음 위치로 이동
		mul += 1; // 뛰는 범위 증가
		// 처음에는 2의 곱 형태로 mul 을 증가시켰으나,
		// 이는 b의 위치에서의 값일 뿐, 실제 부모노드에서 참조해야 하는 값은 1씩 증가한다는 특징
		// so, 이로 인해 하위 depth 에서 점프 값이 log N 개 보다 부족한 현상이 발생했음
	}

	for (int k = 0; k < edges[b].size(); k++) {
		DFS(b, edges[b][k]);
	}
}

int Match(int idx, int d) {
	if (depth[idx] == d) return idx; // 원하는 높이에 도달했으면 종료

	int mul = 1; // 부모로 올라가는 계단 수
	int k = 0; // 벡터 내의 인덱스 번호
	for (; k < v[idx].size(); k++) {
		if (depth[idx] - mul < d) { // 해당 단계가 원하는 높이보다 위에 있으면
			break; // 종료
		}
		mul *= 2; // 그 외엔 2배씩 이동
	}
	k -= 1; // 빠져나온 경우, 해당 인덱스 이전 것을 선택해야 함
	return Match(v[idx][k], d); // 재귀호출
}

int Find(int a, int b) {
	if (a == b) return a; // 공통 조상에 도착한 경우 종료

	int k = 0;
	for (; k < v[a].size(); k++) { // 둘의 depth 는 동일하므로 벡터 크기도 동일
		if (v[a][k] == v[b][k]) { // 두 조상이 같으면 그 밑에 있음
			break;
		}
	}
	k = k ? k - 1 : k; // k 가 0인 경우는 그대로 유지
	return Find(v[a][k], v[b][k]);
}

int main() {
	cin >> N;
	int a, b;
	depth[1] = 1; // 깊이는 1부터 시작
	for (int k = 1; k < N; k++) { // 1~N-1 까지 총 N-1 개
		scanf("%d %d", &a, &b);
		edges[a].push_back(b);
		edges[b].push_back(a); // 엣지 정보를 삽입
	}

	visit[1] = 1; // 루트부터 출발하여 하나의 LCA 트리 정보를 생성
	for (int k = 0; k < edges[1].size(); k++) {
		DFS(1, edges[1][k]);
	}

	cin >> M;
	for (int k = 0; k < M; k++) {
		scanf("%d %d", &a, &b);
		if (depth[a] > depth[b]) a = Match(a, depth[b]);
		else if (depth[a] < depth[b]) b = Match(b, depth[a]); // 둘 중 낮은 depth 쪽으로 맞춤
		printf("%d\n", Find(a, b)); // 공통 부모를 찾아 출력
	}
}