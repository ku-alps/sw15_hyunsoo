#include<iostream>
#include<tuple>
#include<queue>
using namespace std;
// 숨바꼭질
// 큐를 사용한 BFS 탐색

#define NUM 100000

int arr[NUM + 1];
queue<pair<int, int>> q;

int main() {
	int N, K;
	cin >> N >> K;

	q.emplace(N, 0); // 출발 위치
	while (!q.empty()) {
		int x, v;
		tie(x, v) = q.front();
		q.pop();

		if (arr[x]) continue; // 이미 방문한 곳이면 무시
		arr[x] = v;
		if (x == K) break; // 동생이 있는 곳이면 종료

		if (x + 1 <= NUM) q.emplace(x + 1, v + 1); // 오른쪽 이동
		if (x - 1 >= 0) q.emplace(x - 1, v + 1); // 왼쪽 이동
		if (x * 2 <= NUM) q.emplace(x * 2, v + 1); // 순간 이동
	}
	cout << arr[K] << endl;
}