#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
// SCC
// 코사라주 알고리즘을 사용하려 했으나, 실패

int v, e; // 노드, 엣지 수
bool visit[10000]; // 하나의 SCC들을 구분하는 값
vector<int> ori[10000]; // 10000개의 노드들에 대한 연결관계
vector<int> rev[10000]; //역방향 그래프
vector<int> stack; // 스택
vector<vector<int>> group;

void DFS(int here); // 그래프 탐색
void Union();
void R_DFS(int here, int& num);


int main() {
	cin >> v >> e;

	while (e--) {
		int a, b; //연결 관계
		cin >> a >> b;
		ori[a - 1].push_back(b - 1); // a에서 b 방향으로 연결됨
		rev[b - 1].push_back(a - 1); // 역 방향
	}

	for (int k = 0; k < v; k++) { // 모든 노드를 방문해야함
		if (!visit[k]) // 아직 방문 안한 곳이 있다면
			DFS(k); //방문 시작
	} // 우선 순 방향 그래프 탐색 완료
	Union();
}

void DFS(int here) {
	if (visit[here]) // 방문한 적이 있는 곳이면
		return; // 둘러보지 않음
	visit[here] = true; // 방문 했음을 표기
	for (int k = 0; k < ori[here].size(); k++) { //자신과 연결된 모든 엣지를 보며
		DFS(ori[here][k]); // 해당 노드로 방문 시도
	}
	stack.push_back(here); //해당 위치와 연결된 지점을 모두 보았으면, 스택에 넣음 (탐색 끝난 순)
	return;
}

void Union() {
	for (int k = 0; k < v; k++) {
		visit[k] = false; // 초기화
	}
	int num = 0;
	for (int k = stack.size() - 1; k >= 0; k--) {
		int place = stack[k]; // 이번에 방문해야할 곳
		if (visit[place])
			continue; // 이미 방문한 곳이라면 넘기고 아니면 진행
		group.resize(group.size() + 1); //사이즈를 1칸 늘림
		R_DFS(place, num); // 탐색 시작
		num++;
	}

	int head[10000];
	for (int k = 0; k < group.size(); k++) { // 그룹 단위별로 모두 초기화
		sort(group[k].begin(), group[k].end()); // 해당 범위를 정렬
		head[k] = k;
	}

	for (int k = 0; k < group.size(); k++) {
		for (int i = k; i < group.size(); i++) {
			if (group[head[k]][0] > group[head[i]][0]) {
				// 만일 먼저나온 놈의 최소값이 뒤에 나온 놈의 최소값보다 작은 경우
				int save = head[k];
				head[k] = head[i];
				head[i] = save; // 스와이핑
			}
		}
	} // 각 그룹별로도 정렬

	for (int k = 0; k < group.size(); k++) {
		int list = head[k]; // 정렬된 순서대로 SCC를 출력
		for (int i = 0; i < group[list].size(); i++) {
			cout << group[list][i] + 1 << " ";
		}
		cout << "-1\n"; // 끝은 -1
	}
}

void R_DFS(int here, int& num) {
	if (visit[here]) // 방문한 적이 있는 곳이면
		return; // 둘러보지 않음
	visit[here] = true; // 방문 했음을 표기
	for (int k = 0; k < rev[here].size(); k++) { //자신과 연결된 모든 엣지를 보며
		R_DFS(rev[here][k], num); // 해당 노드로 방문 시도
	}

	group[num].push_back(here); //해당 그룹에 소속해있음

	return;
}
