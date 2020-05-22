#include<cstdio>
#include<vector>
#include<tuple>
#include<algorithm>
using namespace std;
// 중량제한
// 이동하는 경로를 통해 전달 가능한 최대 무게를 획득해야 함
// so, 경로가 여러 개인 경우 최대 값을 선택해아하고,
// 하나의 경로 내에선 구성 원소들의 최소값이 전달 가능한 최대 무게가 됨

// 입력된 엣지를 무게 순으로 정렬하여 maximum-spanning tree 를 구성
// 이후, 해당 트리를 탐색하며, 원하는 노드에 도달한 경우,
// 현재까지 거쳐간 최소 크기의 엣지를 출력하는 방식

#define NUM 100000 // 노드의 최대 갯수
#define INF 1000000000 // 다리의 최대 허용중량

int N, M, A, B, node[NUM + 1], from, to, visit[NUM + 1], ans;
vector<tuple<int, int, int>> v; // 전체 엣지
vector<pair<int, int>> whole[NUM + 1]; // 연결된 엣지

int Repre(int a) { // 대표값 획득 함수
	if (node[a] == a) return a; // 대표값 반환
	return node[a] = Repre(node[a]);
}

bool Union(int a, int b) { // 동치 여부 판단
	return Repre(a) == Repre(b);
}

void DFS(int a, int weight) { // 경로 탐색
	if (a == to) { // from 에서 to 로 도착했다면
		ans = weight; // 현재까지 거쳐 온 다리 중 최소값을 저장
		return; // 종료
	}
	if (visit[a]) return; // 이미 방문한 곳 무시
	visit[a] = 1;

	for (auto edge : whole[a]) { // 선택한 엣지에 대해
		int b, c;
		tie(b, c) = edge; // 다음 목적지 + 엣지 무게
		DFS(b, min(weight, c)); // 이동
	}
}

int main() {
	scanf("%d %d", &N, &M);

	for (int k = 1; k <= N; k++) {
		node[k] = k;
	}

	for (int k = 0; k < M; k++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		v.push_back(tuple<int, int, int>(a, b, c)); // 튜플 형태로 엣지를 저장
	}

	scanf("%d %d", &from, &to); // 공장이 있는 두 지점

	sort(v.begin(), v.end(), [](auto a, auto b)->bool { // 앳지 정렬
		return get<2>(a) > get<2>(b); // 다리의 허용 무게가 큰 순서대로 정렬
		});

	// 엣지가 큰 순서대로 확장 ( Maximum-spanning Tree )
	for (auto& edge : v) { // 각 엣지들에 대해
		int a, b, c;
		tie(a, b, c) = edge; // 튜플 원소 값을 한 번에 받아옴
		if (Union(a, b)) continue; // 이미 연결된 그룹이면 건너뜀

		whole[a].push_back(pair<int, int>(b, c));
		whole[b].push_back(pair<int, int>(a, c)); // 엣지를 연결
		
		int r_a = Repre(a), r_b = Repre(b);
		r_a > r_b ? node[r_a] = r_b : node[r_b] = r_a; // 두 그룹을 합침

		if (Union(from, to)) break; // 두 도시가 연결된 경우, 종료
	}

	DFS(from, INF); // 트리 탐색
	printf("%d\n", ans); // 정답 출력
}