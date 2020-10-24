#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
#include<queue>
#include<functional>
using namespace std;
// Strongly Connected Component 
// SCC 문제
// 각 그래프에서 왕복하는 사이클이 존재한다는 것은
// 모든 길을 거꾸로 뒤집었을 때도 경로가 존재함을 의미

#define NUM 10001

int V, E, visit[NUM]; // 방문 여부 (DFS)
stack<int> s; // 스택
vector<int> edge[NUM], r_edge[NUM]; // 엣지, 역 엣지

// SCC 배열 ( 각 scc는 노드 번호를 오름차순으로 출력해야 하므로, 우선순위 큐를 사용 )
vector<priority_queue<int, vector<int>, greater<int>>> scc;

// 1차 탐색
void DFS(int idx) {
	if (visit[idx]) return;
	visit[idx] = 1; // 방문 여부

	for (int next : edge[idx]) DFS(next); // 다음으로 이동

	s.push(idx); // 해당 노드를 스택에 삽입
}

// 2차 탐색
void RDFS(int idx) {
	visit[idx] = 0; // 방문 여부
	for (int next : r_edge[idx]) {
		if (!visit[next]) continue;
		RDFS(next);
	}
	// 가장 마지막에 만들어진 scc 에 해당 노드 추가
	scc[scc.size() - 1].push(idx);
}

int main() {
	cin >> V >> E;
	for (int k = 0; k < E; k++) {
		int a, b;
		cin >> a >> b; // 입력
		edge[a].push_back(b);
		r_edge[b].push_back(a); // 엣지 삽입
	}

	for (int k = 1; k <= V; k++) DFS(k); // 1차 탐색 시작
	while (!s.empty()) {
		int node = s.top();
		s.pop();
		if (!visit[node]) continue; // 다른 지점에서 방문한 곳은 무시

		// 새로운 scc 생성
		scc.push_back(priority_queue<int, vector<int>, greater<int>>());
		RDFS(node);
	}

	// 각 scc 순서 정렬
	sort(scc.begin(), scc.end(), [](auto a, auto b) -> bool {
		return a.top() < b.top();
	});

	cout << scc.size() << endl;
	for (auto nodes : scc) {
		while (!nodes.empty()) {
			cout << nodes.top() << " "; // 각 노드는 띄어쓰기로 구분
			nodes.pop();
		}
		cout << -1 << endl; // 각 scc는 줄바꿈으로 구분
	}
}