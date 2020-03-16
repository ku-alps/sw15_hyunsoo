#include<iostream>
#include<queue>
#include<tuple>
using namespace std;
// 달이 차오른다, 가자.
// 각 문에 맞는 열쇠를 갖고있는가를 판단해야 함
// 일반적인 탐색문제와는 다르게, 왔던 길을 다시 돌아갈 수 있단 점에서 헤메었으나,
// 가지고 있는 열쇠로 상태를 구분할 수 있다는 점에서 BFS 풀이가 가능함을 확인
// 열쇠의 종류는 최대 6개이므로, 비트 마스킹과 BFS 를 적절하게 섞어서 해결

#define NUM 50
#define MAX 1000
#define KEY ( 1 << 7 ) // a~f 까지 총 6개의 문
#define X "0121"
#define Y "1210"

int N, M, step[NUM][NUM][KEY]; // 높이, 너비, BFS 배열
char map[NUM][NUM]; // 맵 정보
pair<int, int> from; 
vector<pair<int, int>> to; // 시작 위치, 도착 위치

int main() {
	cin >> N >> M;
	for (int k = 0; k < N; k++) {
		for (int m = 0; m < M; m++) {
			cin >> map[k][m];
			if (map[k][m] == '0') from = pair<int, int>(k, m); // 시작점
			if (map[k][m] == '1') to.push_back(pair<int, int>(k, m)); // 도착점
		}
	}

	int ans = -1; // 정답이 없는 경우는 -1 을 출력
	queue<tuple<int, int, int,int >> q; // BFS 큐
	q.emplace(from.first, from.second, 0, 0); // 시작점을 기준으로 탐색 시작

	while (!q.empty()) { // 큐가 빌 동안 모두 확인
		int x, y, bit, v; // 좌표값, 가진 열쇠 값, 연 문의 갯수
		tie(x, y, bit, v) = q.front();
		q.pop();

		for (int k = 0; k < to.size(); k++) {
			if (x == to[k].first && y == to[k].second) { // 도착점 중 하나에 도달했다면
				ans = v; // 정답으로 저장
				break; // 탐색 종료
			}
		}
		if (ans > 0) break; // 양수라면 값을 찾았단 의미

		// 벽인 경우, 무시
		if (map[x][y] == '#') continue;
		// 열쇠인 경우, 꾸러미에 합침 (열쇠 보유)
		if (map[x][y] >= 'a' && map[x][y] <= 'f') bit |= 1 << (map[x][y] - 'a');
		// 문인 경우, 현재 열쇠를 갖고 있는지 판단, 없다면 무시
		if (map[x][y] >= 'A' && map[x][y] <= 'F')
			if (!(bit & (1 << (map[x][y] - 'A')))) continue; 

		if (step[x][y][bit]) continue; // 이전에 방문한 기록이 있다면 무시
		step[x][y][bit] = v; // 현재까지 이동한 횟수를 기록

		for (int k = 0; k < 4; k++) { // 네 방향 BFS 탐색
			int n_x = x + X[k] - '1', n_y = y + Y[k] - '1';
			if (n_x < 0 || n_x >= N || n_y < 0 || n_y >= M) continue; // 공간을 벗어나면 무시
			q.emplace(n_x, n_y, bit, v + 1); // 그 외에 대해선 큐에 넣어 살펴봄
		}
	}

	cout << ans << endl;
}