#include<iostream>
#include<vector>
#include<queue>
#include<tuple>
#include<algorithm>
using namespace std;
// 보석 줍기
// 최대 신장 트리를 생성 후, 판단
// cause, 최대한의 보석을 줍기 위해선 사용되는 다리의 크기가 최대치가 되는게 유리
// 각 다리는 오름차순으로 정렬하여 DFS 탐색
// 작은 다리를 건너올 수 있었다면, 큰 다리는 그 보석을 모두 갖고 이동할 수 있기 때문

#define NUM 100
typedef tuple<int, int, int> tp; // a와 b를 연결하는 가중치 c 다리

struct func { // 우선순위 큐 정렬 기준
	bool operator()(tp a, tp b) {
		return get<2>(a) < get<2>(b);
	}
};

int N, M, K, visit[NUM + 1], land[NUM + 1], group[NUM + 1];
vector<pair<int,int>> v[NUM + 1]; // 선택된 다리 집합
priority_queue<tp, vector<tp>, func> pq; // 최대 신창 트리 생성용 우선순위 큐

// Union-Find
int Find(int idx) {
	if (group[idx] == idx) return idx;
	return group[idx] = Find(group[idx]);
}

bool Union(int a, int b) {
	int ra = Find(a), rb = Find(b);
	if (ra == rb) return false;
	group[ra] = rb;
	return true;
}

// DFS 탐색
int DFS(int idx, int sum) { // 현재 노드번호, 현재까지 주워 온 보석 수
	if (visit[idx]) return sum; // 이미 방문한 곳이면 무시
	visit[idx] = 1;

	// 각 노드를 다리 허용치가 작은 순으로 정렬
	sort(v[idx].begin(), v[idx].end(), [](pair<int, int> a, pair<int, int> b)->bool {
		return a.second < b.second;
		});

	for (pair<int, int> next : v[idx]) { // 작은 다리부터 건너며 보석을 주워옴
		sum = min(next.second, DFS(next.first, sum));
		// 다리의 허용치와, 넘어간 곳에서 주워 온 보석의 총 갯수 중 작은 수를 선택
	}
	return sum + land[idx]; // 현재 위치의 보석을 주워서 이동
}

int main() {
	cin >> N >> M >> K;
	for (int k = 1; k <= N; k++) { // 유니온파인드 세팅
		group[k] = k;
	}
	for (int k = 0; k < K; k++) { // 보석 입력
		int num;
		cin >> num;
		land[num] = 1; // 해당 섬에 보석이 있음
	}
	for (int k = 0; k < M; k++) { // 엣지 입력
		int a, b, c;
		cin >> a >> b >> c;
		pq.push({ a,b,c }); // 해당 엣지를 삽입
	}

	while (!pq.empty()) { // 최대 스패닝 트리 생성
		int a, b, c;
		tie(a, b, c) = pq.top();
		pq.pop();

		if (Union(a, b)) { // 만일 두 그룹을 새로 합친거라면
			v[a].push_back({ b,c });
			v[b].push_back({ a,c }); // 해당 엣지는 사용함
		}
	}
	cout << DFS(1, 0) << endl; // 시작점부터 탐색
}