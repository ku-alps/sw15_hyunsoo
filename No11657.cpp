#include<iostream>
#include<vector>
#include<queue>
#include<tuple>
#include<algorithm>
using namespace std;
// 타임머신
// 벨만 포드 알고리즘
// 다익스트라와 다르게, 음수 가중치에 대한 처리가 가능함
// 다만, 모든 노드, 모든 엣지에 대한 확인 및 갱신이 계속해서 일어나므로
// 굉장히 느린 알고리즘 중 하나

#define MAX 500
#define LIMIT MAX*10000 +1 // 각 거리 값의 범위는 -10000 ~ 10000

int N, M;
int arr[MAX + 1], visit[MAX + 1]; // 실제 누적 거리정보, 방문 여부
vector<pair<int,int>> v[MAX + 1]; // 엣지 벡터
queue<tuple<int,int,int>> q; // 탐색용 큐

int main() {
	scanf("%d %d", &N, &M);

	for (int k = 1; k <= N; k++)
		arr[k] = LIMIT; // 각 정보 초기화

	int a, b, c;
	for (int k = 0; k < M; k++) {
		scanf("%d %d %d", &a, &b, &c);
		v[a].push_back(pair<int, int>(b, c)); // 정보를 받아 벡터에 저장
	}
	arr[1] = 0; // 시작 지점의 값은 0
	for (int k = 1; k <= N; k++) { // 모든 노드에 대해서 엣지 탐색
		for (int m = 1; m <= N; m++) visit[m] = 0; // 방문여부 매번 초기화
		q.push(tuple<int, int, int>(k, k, 0)); // 시작을 위해 큐에 기본정보를 삽입

		while (!q.empty()) { // 큐가 빌 때 까지
			tuple<int, int, int> data = q.front();
			q.pop();
			int from = get<0>(data), to = get<1>(data), len = get<2>(data); // 각 데이터를 뽑아옴

			if (arr[from] == LIMIT) continue;
			// 기본적으로 '도달한 노드' 를 기반으로 엣지를 확장
			// 또한 기반이 되는 값은 0으로 초기화 했기에
			// 현재까지 해당 지점이 LIMIT 는 출발지에서 도달하는 길이 없음을 의미

			int calc = arr[from] + len; // 새로운 길이 계산 (탐색 노드값 + 엣지 길이)
			arr[to] = min(calc, arr[to]); // 최솟값 선택

			if (visit[to]) continue; // 방문한 경우 큐에 추가삽입할 필요 x
			visit[to] = 1;
			for (int m = 0; m < v[to].size(); m++) {
				q.push(tuple<int, int, int>(to, v[to][m].first, v[to][m].second)); // 큐에 삽입
			}
		}
	}

	int cnt = 0; // 최소값으로 수렴하지 못하는 경우, 값이 변화하므로
				// 무한히 감소하는 사이클이 존재한다는 것을 의미
				// so, 기존 알고리즘을 1회 더 추가로 시도한 후, 값이 다시 변하는 경우 수렴 불가
	for (int m = 1; m <= N; m++) visit[m] = 0;
	q.push(tuple<int, int, int>(1, 1, 0));
	while (!q.empty()) {
		tuple<int, int, int> data = q.front();
		q.pop();
		int from = get<0>(data), to = get<1>(data), len = get<2>(data);

		if (arr[from] == LIMIT) continue; // 도달하는 길이 없다면 무시

		int calc = arr[from] + len;
		if (calc < arr[to]) { // 새로 얻은 값에 변화가 생기면 (최소값이 갱신된다면)
			cnt++;
			break; // 해당 경로는 음의 사이클로 무한히 값이 줄어듦 (수렴 불가)
		}

		if (visit[to]) continue; // 이미 방문했다면 계속 진행
		visit[to] = 1;
		for (int m = 0; m < v[to].size(); m++) {
			q.push(tuple<int, int, int>(to, v[to][m].first, v[to][m].second)); // 큐에 삽입
		}
	} // 수렴 불가여부 판단 끝

	if (cnt) // 조건에 따라 출력
		cout << -1 << endl;
	else {
		for (int k = 2; k <= N; k++)
			if (arr[k] != LIMIT)
				cout << arr[k] << endl;
			else
				cout << -1 << endl;
	}
}