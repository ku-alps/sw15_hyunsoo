#include<iostream>
#include<vector>
#include<cstdio>
#include<algorithm>
using namespace std;
// 단절점
// 기본적인 알고리즘 원리를 사용한 단순 구현
// DFS 기반으로 규칙 및 조건을 판단
// ( 자신의 후방 노드들이 윗 노드로 올라올 수 있는가? )

// 다만, 판단 과정에서 상위 노드가 이미 방문한 하위 노드를 볼 때
// 중복 판단으로 오류가 발생하는 문제가 발생
// +) DFS 의 시작점의 경우, 다른 판단 기준이 필요

#define MAX 10000

int V, E, visit[MAX + 1];
int val[MAX + 1][2]; // 0: 방문 순서, 1: 도달가능한 최소 값
int ch[MAX + 1];
vector<int> v[MAX + 1], ans; // 노드의 연결 엣지 정보, 단절점 벡터
int cnt, order = 1, root;

int DFS(int idx) {
	if (visit[idx]) return val[idx][1]; // 이전에 방문했으면 반환
	visit[idx] = 1; // 방문했다고 고정

	val[idx][0] = order++; // 해당 노드의 방문 번호 등록 및 값 증가
	val[idx][1] = val[idx][0]; // 현재 도달 가능한 최대높이는 자기 자신

	bool flag = false;
	int subtree = 0, mini; // 해당 노드의 서브트리 갯수, 자식이 도달 가능한 최대 높이
	for (int k = 0; k < v[idx].size(); k++) { // 모든 엣지를 살펴보며
		if (!visit[v[idx][k]]) { // 아직 방문 안한 경우
			mini = DFS(v[idx][k]); // 해당 노드로 방문
			subtree++; // 서브트리 수 증가
		}
		else { // 방문 한 경우
			if (val[idx][0] > val[v[idx][k]][0]) { // 밑에서 올려다보는 경우
				mini = val[v[idx][k]][0]; // 상위의 번호를 받아옴 (항상 큼)
			} // 위에서 내려다보는 경우는 탐색과정에서 전부 처리했으므로 무시
		}
		if (mini >= val[idx][0]) // 자식들이 내 위로 가는 다른 길이 없다면
			flag = true; // 해당 노드는 종단점
		val[idx][1] = min(val[idx][1], mini); // 또한 자식을 통해 이동 가능하므로 판단 필요
	}

	if ((idx != root && flag) || (idx == root && subtree > 1)) {
		// 1. 루트가 아닌 경우 : 하위 노드의 정보를 통해 판단
		// 2. 루트인 경우 : 자신이 가진 서브트리의 갯수로 판단
		cnt++;
		ans.push_back(idx);
	}
	return val[idx][1]; // 갈 수 있는 가장 높은 위치를 반환
}

int main() {
	scanf("%d %d", &V, &E);

	int a, b;
	for (int k = 0; k < E; k++) {
		scanf("%d %d", &a, &b);
		v[a].push_back(b);
		v[b].push_back(a); // 방향성이 없으므로, 양쪽 모두에 엣지 추가
	}
	for (int k = 1; k <= V; k++) {
		if (visit[k]) continue; // 독립된 노드를 고려하여 모두 탐색 시도
		root = k;
		DFS(k);
	}
	sort(ans.begin(), ans.end()); // 선택된 단절점 정렬

	printf("%d\n", cnt);
	for (int k = 0; k < cnt; k++) {
		printf("%d ", ans[k]); // 정답 출력
	}
}