#include<iostream>
using namespace std;
// 여행 가자
// 완전 탐색 문제처럼 보이지만, 연결만 존재한다면 경로를 크게 돌아서 갈 수 있음
// so, 실제로는 그룹핑 문제이며 Union-Find 로 해결 가능

#define NUM 200

int N, M, group[NUM + 1];

int Find(int a) {
	if (group[a] == a) return a;
	return group[a] = Find(group[a]);
}

void Union(int a, int b) {
	group[Find(a)] = Find(b); // 각 루트를 서로 합침
}

int main() {
	cin >> N >> M;

	for (int k = 1; k <= N; k++) {
		group[k] = k; // 자기 본인 값이면 루트
	}

	for (int k = 1; k <= N; k++) {
		for (int m = 1; m <= N; m++) {
			int a;
			cin >> a;
			if (a) Union(k, m); // k와 m은 같은 그룹 소속 (연결됨)
		}
	}

	bool flag = true;
	int start;
	cin >> start;
	for (int k = 1; k < M; k++) {
		int idx;
		cin >> idx;
		if (Find(start) != Find(idx)) { // 그룹이 다르다면 해당 경로는 불가능
			flag = false;
			break;
		}
	}
	cout << (flag ? "YES" : "NO") << endl;
}