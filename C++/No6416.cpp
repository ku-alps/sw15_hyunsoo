#include<iostream>
#include<algorithm>
#include<unordered_map>
using namespace std;
// 트리인가?
// 배열 Union-Find 를 활용하려했으나, 값의 범주가 너무 들쑥날쑥
// vector를 사용하는 경우, 메모리초과가 발생
// so, 문제를 최대한 단순화시켜 생각

// 한 노드가 여러 부모를 갖는가?
// 루트가 될 수 있는 대상이 여러개인가?
// 노드가 하나 뿐인 트리인가?

#define MAX 15

int arr[MAX]; // Union-Find 를 활용
unordered_map<int, int> m; // 트리의 부모 정보

int main() {
	bool loop = true;
	for (int k = 1; ; k++) {
		int u, v;
		bool flag = true; // 트리 여부

		m.clear(); // 초기화

		while (true) {
			cin >> u >> v;
			if (u + v < 0) { // 음의 정수 두 개면 루프 끝
				loop = false;
				break;
			}
			if (u + v == 0) break; // 합이 0이면 입력 끝

			if (m[v]) flag = false; // 연결 엣지가 여러 개인 경우, 트리가 아님
			m[v] = u; // v 의 부모는 u
			m[u]; // 부모 u의 공간을 생성
		}

		if (!loop) break; // 케이스 없으면 종료
		
		int cnt = 0; // 부모가 없는 노드의 수
		for (unordered_map<int, int>::iterator it = m.begin(); it != m.end(); ++it) {
			// 맵의 모든 구성원소를 살펴봄
			if (!it->second) cnt += 1; // 부모가 없다면 증가
		}
		flag &= (!m.size() || cnt == 1);
		// 노드가 유일하거나, 루트가 단 하나인 경우
		cout << "Case " << k << " is " << (!flag ? "not " : "") << "a tree." << endl;
	}
}