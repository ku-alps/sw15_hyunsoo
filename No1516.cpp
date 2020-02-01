#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
// 게임 개발
// 사이클이 없는 방향성 그래프 (DAG)
// so, 규칙에 의해 한 번 획득한 노드의 시간정보는 절대 갱신되지 않으므로
// 메모아이제이션 기법을 사용할 수 있음

#define MAX 500
#define LIM MAX * 100000

int N, time[MAX + 1], total[MAX + 1];
vector<int> v[MAX + 1];

int DFS(int idx) {
	if (total[idx]) return total[idx]; // 방문한 경우 종료

	total[idx] = time[idx]; // 자신이 걸리는 시간이 최소값
	for (int k = 0; k < v[idx].size(); k++) {
		total[idx] = max(total[idx], DFS(v[idx][k]) + time[idx]);
	} // 앞 건물이 필요한 경우 + 본인 시간
	// 다만, 문제 상에는 최소값이라고 말을 하지만 모든 조건을 충족시켜야 하므로
	// max 알고리즘을 사용해야함

	return total[idx];
	
}

int main() {
	cin >> N;
	for (int k = 1; k <= N; k++) {
		scanf("%d", &time[k]);
		int pre;
		while (true) {
			scanf("%d", &pre);
			if (pre == -1) break;
			v[k].push_back(pre); ; // 이전에 건설해야 하는 건물
		}
	}

	for (int k = 1; k <= N; k++) {
		printf("%d\n", DFS(k));
	} // 출력
}