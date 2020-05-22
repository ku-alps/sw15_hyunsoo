#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
using namespace std;
// DFS 스페셜 저지
// 기본적으로 DFS 탐색을 하되, 입력 순서와 일치하는 노드로만 이동을 시도
// 매번 값을 빼내며 탐색하며, 최종적으로 큐에 남아있는 값으로 정답을 판단

#define NUM 100000
#define ROOT 1

int N, visit[NUM + 1]; // 방문 여부
vector<int> v[NUM + 1]; // 엣지 정보
queue<int> ans; // 정답 여부를 판별할 큐

void DFS(int idx) {
	if (ans.empty()) return; // 비어있다면 성공적으로 탐색
	visit[idx] = 1;

	int next = ans.front();
	for (int k = 0; k < v[idx].size(); k++) { // 모든 엣지를 살펴봄
		if (v[idx][k] == next) {
			// 탐색 순서와 맞는 노드가 있으면
			ans.pop(); // 해당 노드를 뽑아내고 재귀호출
			DFS(next);
			if (ans.empty()) return; // 비어있다면 종료
			next = ans.front(); // 다음 탐색 노드를 갱신 후
			k = -1; // 다시 처음부터 엣지를 살핌
		}
	}
}

int main() {
	cin >> N;
	int a, b;
	for (int k = 1; k < N; k++) { // 엣지 연결
		scanf("%d %d", &a, &b);
		v[a].push_back(b);
		v[b].push_back(a); // 계층을 알 수 없으므로 둘다 추가
	}
	int order;
	for (int k = 0; k < N; k++) { // 이후에 탐색 순서를 받아옴
		scanf("%d", &order);
		ans.push(order);
	}
	int start = ans.front(); // 시작점 체크
	ans.pop();
	if (start != ROOT) cout << 0 << endl; // 루트로 시작하지 않으면 무조건 실패
	else {
		DFS(start);
		cout << (ans.empty()) << endl; // 탐색 후 남은 큐 정보로 판단
	}
}
