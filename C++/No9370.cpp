#include<iostream>
#include<vector>
#include<queue>
#include<tuple>
#include<algorithm>
#include<functional>
using namespace std;
// 미확인 도착지
// 다익스트라를 사용한 경로 문제
// 사용한 엣지 여부에 대해 비트마스킹을 사용하려 했으나,
// 입력 가능한 노드의 후보군이 최대 2000 이므로, 표현 가능 범주를 넘어섬
// so, 람다 함수 선언을 통해 조건을 확인하는 방법으로 코드를 축약

#define NUM 2000

typedef tuple<int, int, int> tp;

int main() {
	int loop;
	cin >> loop;
	while (loop--) {
		int N, M, T, S, G, H; // 교차로, 도로, 목적지후보, 출발점, G-H
		cin >> N >> M >> T >> S >> G >> H;

		int visit[2][NUM + 1] = {}; // 최저 비용, 필요엣지 사용 여부
		vector<pair<int, int>> v[NUM + 1]; // 엣지 집합

		for (int k = 0; k < M; k++) {
			int a, b, c;
			cin >> a >> b >> c;
			v[a].push_back({ b,c });
			v[b].push_back({ a,c });
		}

		// 경로 사용 확인 함수 (람다식)
		auto func = [&](int a, int b)->bool{
			return (a == G && b == H) || (a == H && b == G);
		};

		priority_queue<tp, vector<tp>, greater<tp>> pq;
		pq.emplace(0, 0, S); // 출발지 S 부터 최단거리 탐색
		while (!pq.empty()) {
			int val, prnt, child;
			tie(val, prnt, child) = pq.top();
			pq.pop();
			if (visit[0][child]) { // 이전에 방문한 경우
				if (visit[0][child] == val) // 값이 온전히 같은 경우만, 경로 변경 가능
					visit[1][child] = max(visit[1][child], visit[1][prnt]) + func(prnt, child);
				continue; // 이미 방문한 곳은 무시
			}
			visit[0][child] = val; // 해당 값으로 도착

			// G-H 사용 여부에 따라 결과에 차이가 존재
			if (func(prnt, child)) visit[1][child] = 1;
			else visit[1][child] = visit[1][prnt];

			// 다음 탐색을 계속 진행
			for (pair<int, int> next : v[child])
				pq.emplace(val + next.second, child, next.first);
		}

		// 목적지 후보 추려내기
		priority_queue<int,vector<int>,greater<int>> ans;
		for (int k = 0; k < T; k++) {
			int a;
			cin >> a;
			ans.push(a);
		}
		while (!ans.empty()) { // G-H 를 사용했다면 출력
			if (visit[1][ans.top()]) cout << ans.top() << " ";
			ans.pop();
		}
		cout << "\n";
	}
}