#include<iostream>
#include<queue>
#include<tuple>
using namespace std;
// 최소 스패닝 트리
// 엣지의 최소값 순으로 선택하는 크루스칼 알고리즘 사용

#define NUM 10000 // 노트 최대 갯수

struct func { // 우선순위 큐 선정 기준
	bool operator()(tuple<int, int, int> a, tuple<int, int, int> b) {
		return get<2>(a) > get<2>(b);
	}
};

int V, E, ans;
int group[NUM + 1]; // 각 노드가 동일한 그룹에 속해있는가?
priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, func> pq;

int Find(int a) { // 그룹 확인
	if (group[a] == a) return a;
	return group[a] = Find(group[a]);
}

bool Sum(int a, int b) { // 두 그룹이 동일인지 확인 후 합침
	int r_a = Find(a), r_b = Find(b);
	if (r_a == r_b) return false;
	group[r_a] = group[r_b];
	return true;
}

int main() {
	cin >> V >> E;

	for (int k = 1; k <= V; k++) group[k] = k; // 초기화
	for (int k = 0; k < E; k++) { // 엣지 입력
		int a, b, w;
		cin >> a >> b >> w;
		pq.emplace(a, b, w);
	}

	while (!pq.empty()) { // 최소 스패닝 트리 생성
		int a, b, w;
		tie(a, b, w) = pq.top();
		pq.pop();
		if (Sum(a, b)) ans += w; // 다른 그룹이면 엣지를 사용 (가중치 추가)
	}
	cout << ans << endl;
}