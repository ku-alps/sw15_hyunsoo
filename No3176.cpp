#include<iostream>
#include<cstdio>
#include<vector>
#include<tuple>
#include<algorithm>
using namespace std;
// 도로 네트워크
// 기본적으로 LCA ( Longest Common Ancient ) 기반 문제
// 단순히 부모 정보뿐만 아니라 해당 부모까지 거치게 되는 최대, 최소 도로의 저장이 필요

#define MAX 100000

int N, M;
int depth[MAX + 1], visit[MAX + 1];
vector<tuple<int, int, int>> v[MAX + 1]; // 각 노드의 조상 정보
vector<pair<int, int>> edges[MAX + 1]; // 연결 정보

void DFS(int a, pair<int, int> b) {
	if (visit[b.first]) return; // 이미 방문한 노드면 퇴근 (역 엣지의 경우)
	visit[b.first] = 1;

	// 루트인 1을 기점으로 트리가 만들어지므로,
	// a는 부모, b는 자식이라는 가정이 성립 ( 루트에 가까운 노드가 반드시 먼저 방문 )
	depth[b.first] = depth[a] + 1; // 부모노드 깊이 + 1
	v[b.first].push_back(tuple<int, int, int>(a, b.second, b.second)); // 부모 인덱스 정보를 기록
	int mul = 0, idx = a;
	while (mul < v[idx].size()) {
		int Min = min(get<1>(v[b.first].back()), get<1>(v[idx][mul])); // 현재까지 건너온 도로 중 최소 값
		int Max = max(get<2>(v[b.first].back()), get<2>(v[idx][mul])); // 현재까지 건너 온 도로 중 최대 값
		v[b.first].push_back(tuple<int, int, int>(get<0>(v[idx][mul]), Min, Max)); // 해당 위치의 2의 승수 자리 부모를 저장
		idx = get<0>(v[idx][mul]); // 다음 위치로 이동
		mul += 1; // 뛰는 범위 증가 ( 논리상으로 2배 )
	}

	for (int k = 0; k < edges[b.first].size(); k++) {
		DFS(b.first, edges[b.first][k]); // 현재 위치와 연결된 노드들에 대해 수행 반복
	}
}

int Match(int idx, int d, int* Min, int* Max) {
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
	*Min = min(*Min, get<1>(v[idx][k])); 
	*Max = max(*Max, get<2>(v[idx][k]));
	// 높이를 맞추는 과정에서 발견 될 수도 있으므로, 값의 저장이 필요

	return Match(get<0>(v[idx][k]), d, Min, Max); // 재귀호출
}

int Find(int a, int b, int* Min, int* Max) {
	if (a == b) return a; // 공통 조상에 도착한 경우 종료

	int k = 0;
	for (; k < v[a].size(); k++) { // 둘의 depth 는 동일하므로 벡터 크기도 동일
		if (get<0>(v[a][k]) == get<0>(v[b][k])) { // 두 조상이 같으면 그 밑에 있음
			break;
		}
	}
	if (k != 0) {
		k = k - 1; // k 가 0인 경우는 그대로 유지
	}
	int check1 = min(get<1>(v[a][k]), get<1>(v[b][k]));
	int check2 = max(get<2>(v[a][k]), get<2>(v[b][k]));
	*Min = min(*Min, check1); // 최소값 갱신
	*Max = max(*Max, check2); // 최대값 갱신

	return Find(get<0>(v[a][k]), get<0>(v[b][k]), Min, Max); // 이동하여 탐색 진행
}

int main() {
	cin >> N;
	int a, b, c;
	depth[1] = 1; // 깊이는 1부터 시작
	for (int k = 1; k < N; k++) { // 1~N-1 까지 총 N-1 개
		scanf("%d %d %d", &a, &b, &c);
		edges[a].push_back(pair<int, int>(b, c));
		edges[b].push_back(pair<int, int>(a, c)); // 엣지 정보를 삽입
	}

	visit[1] = 1; // 루트부터 출발하여 하나의 LCA 트리 정보를 생성
	for (int k = 0; k < edges[1].size(); k++) {
		DFS(1, edges[1][k]);
	}

	cin >> M;
	for (int k = 0; k < M; k++) {
		int Min = 1000000, Max = 0; // 반환 받아야 하는 두 값 ( 포인터를 사용해 값을 주고받음 )
		scanf("%d %d", &a, &b);
		if (depth[a] > depth[b]) a = Match(a, depth[b], &Min, &Max);
		else if (depth[a] < depth[b]) b = Match(b, depth[a], &Min, &Max); // 둘 중 낮은 depth 쪽으로 맞춤
		Find(a, b, &Min, &Max); // 공통 부모를 찾아 출력
		printf("%d %d\n", Min, Max);
	}
}