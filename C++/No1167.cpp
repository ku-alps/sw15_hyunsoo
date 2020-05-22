#include<cstdio>
#include<vector>
#include<queue>
using namespace std;
// 트리의 지름
// 트리의 가장 먼 두 노드의 거리를 나타내는 표현

// 방식 :
// 임의의 루트에서 가장 먼 노드를 선택 후,
// 선택한 노드를 기준으로 다시 한 번 가장 먼 노드까지의 거리를 구함

// 트리는 각 서브트리로 나눠지는 형태
// so, 각각의 서브트리 중, 가장 멀리 떨어진 두 노드의 거리를 찾아야 함
// 즉, 임의의 노드의 형태에서 '가장 멀리' 떨어진 노드를 새로운 기준으로 찾으며
// 한번 더 탐색하는 방법으로 트리의 지름을 찾을 수 있음

#define NUM 100000

struct func{ // 거리가 작을수록 우선순위 높음
	bool operator()(pair<int, int> a, pair<int, int> b) { 
		return a.second > b.second;
	}
};

int N, visit[NUM + 1];
vector<pair<int, int>> v[NUM + 1]; // 엣지정보
priority_queue<pair<int, int>, vector<pair<int, int>>, func> pq; // 우선순위 큐 

int main() {
	scanf("%d", &N);
	for (int k = 0; k < N; k++) {
		int a, b, c;
		scanf("%d", &a); // 노드 선택

		while (true) { // 엣지 정보
			scanf("%d", &b); // 연결 노드 정보
			if (b == -1) break; // -1 이면 종료
			scanf("%d", &c); // 가중치 정보
			v[a].push_back(pair<int, int>(b, c)); // a 에서 b 로 c 라는 거리의 엣지가 연결됨
		}
	}

	int select = 1; 
	pq.push(pair<int, int>(1, 0)); // 시작점 (임의루트 = 1)
	while (!pq.empty()) { // 비어있지 않을 동안 반복
		pair<int, int> info = pq.top();
		pq.pop(); // 방출

		if (visit[info.first]) continue; // 이미 방문한 노드라면 무시
		visit[info.first] = 1;

		select = info.first; // 현재까지 가장 멀리 떨어진 노드로 선택
		for (pair<int, int> edge : v[info.first]) { // 해당 노드와 연결된 엣지들을 살펴봄
			int len = info.second + edge.second; // 해당 경로를 거쳐가는 거리
			pq.push(pair<int, int>(edge.first, len)); // 기록
		}
	}

	for (int k = 1; k <= N; k++) visit[k] = 0; // 초기화

	// 선택한 노드를 기준으로 다시 한번 반복
	int width;
	pq.push(pair<int, int>(select, 0)); 
	while (!pq.empty()) { // 비어있지 않을 동안 반복
		pair<int, int> info = pq.top();
		pq.pop();

		if (visit[info.first]) continue; // 이미 방문한 노드라면 무시
		visit[info.first] = 1;

		width = info.second; 
		for (pair<int, int> edge : v[info.first]) { // 해당 노드와 연결된 엣지들을 살펴봄
			int len = info.second + edge.second; 
			pq.push(pair<int, int>(edge.first, len));
		}
	}
	printf("%d\n", width);
}