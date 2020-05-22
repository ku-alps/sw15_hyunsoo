#include<iostream>
#include<vector>
#include<queue>
#include<tuple>
#include<algorithm>
using namespace std;
// 최단경로
// 다익스트라 알고리즘 단순 구현 문제

#define MAX 20000
#define INF MAX*10 + 1

struct S { // 우선순위 큐의 판단용 구조체
	bool operator()(pair<int, int> a, pair<int, int> b) {
		return a.second > b.second;
	}
};

int V, E, root, visit[MAX + 1], w[MAX + 1]; // 선택 여부, 확정된 노드의 도달 비용
vector<pair<int, int>> v[MAX + 1]; // 엣지 정보 (연결 노드 번호, 가중치)
priority_queue<pair<int, int>, vector<pair<int, int>>, S> pq; // 노드 및 도달 비용
// 다익스트라의 경우, 연결되지 않는 노드 중 최소거리를 갖는 놈을 선택

int main() {
	scanf("%d %d %d", &V, &E, &root);

	for (int k = 1; k <= V; k++) {
		w[k] = INF; // 각 노드의 첫 가중치는 무한 (갈 수 있는 길 없음)
	}

	int a, b, c;
	for (int k = 0; k < E; k++) {
		scanf("%d %d %d", &a, &b, &c);
		v[a].push_back(pair<int, int>(b, c)); // 엣지 입력
	}

	w[root] = 0;
	pq.push(pair<int, int>(root, 0));
	while (!pq.empty()) { // 우선순위 큐가 빌 때 까지
		pair<int, int> sel = pq.top(); // 가장 누적 경로가 작은 노드를 꺼내옴
		pq.pop();
		if (visit[sel.first]) continue; // 이미 선택된 경우 무시
		visit[sel.first] = 1; // 방문 했음

		for (int k = 0; k < v[sel.first].size(); k++) { // 해당 노드와 연결된 모든 엣지를 살펴봄
			int len = v[sel.first][k].second + sel.second; // 해당 경로를 거쳐서 도달하는 거리를 계산
			if (w[v[sel.first][k].first] > len) {
				w[v[sel.first][k].first] = len;
				pq.push(pair<int, int>(v[sel.first][k].first, len)); // 계산된 값이 더좋다면, 갱신 후 큐에 추가
			}
		}
	}
	for (int k = 1; k <= V; k++) { // 모든 경로 비용 출력
		if (w[k] == INF) printf("INF\n");
		else printf("%d\n", w[k]);
	}
}