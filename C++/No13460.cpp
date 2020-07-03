#include<iostream>
#include<queue>
#include<tuple>
using namespace std;
// 구슬 탈출 2
// 두 정보를 동시에 움직이는 BFS 탐색

#define NUM 10

#define X "1210"
#define Y "2101"

typedef pair<int, int> pr;
typedef tuple<pr, pr, int> tp; // 빨간 구슬, 파란 구슬, 이동 횟수

char map[NUM][NUM];
int N, M, visit[NUM][NUM][NUM][NUM]; // 가로, 세로, 구슬 좌표별 방문 여부
queue<tp> q;

pr operator+(pr a, pr b) { // 튜플 연산자
	return pr(a.first + b.first, a.second + b.second);
}

bool check(pr a, pr b) { // 이동 가능한지 판단
	return map[a.first][a.second] != '#' && !(a.first == b.first && a.second == b.second);
}

int main() {
	cin >> N >> M;

	pr R, B, O;
	for (int k = 0; k < N; k++) {
		for (int m = 0; m < M; m++) {
			cin >> map[k][m];

			switch (map[k][m]) {
			case 'R': // 빨간 구슬
				R = pair<int, int>(k, m);
				break;
			case 'B': // 파란 구슬
				B = pair<int, int>(k, m);
				break;
			}
		}
	}

	int ans = -1;
	q.emplace(R, B, 0); // BFS 탐색
	while (!q.empty()) {
		int cnt;
		pr pa, pb; // R, B 의 좌표

		tie(pa, pb, cnt) = q.front();
		q.pop();
		if (cnt > 9) break; // 10번을 넘겨서 움직이면 실패
		
		// 이전에 방문했던 상태면 무시
		if (visit[pa.first][pa.second][pb.first][pb.second]) continue;
		visit[pa.first][pa.second][pb.first][pb.second] = cnt;

		for (int k = 0; k < 4; k++) { // 네 방향으로 기울임
			bool hole[2] = {};
			pr dir = pr(X[k] - '1', Y[k] - '1'); // 중력 방향
			pr bpa = pa, bpb = pb, npa = pa + dir, npb = pb + dir;

			while (check(npa, bpb) || check(npb, bpa)) { // 기울인 방향으로 구슬이 움직일 수 있는가?
				if (check(npa, bpb)) { // a가 굴러감
					if (map[npa.first][npa.second] == 'O') {
						// 굴러가던 방향에 구멍이 있다면 기록
						hole[0] = true;
						bpa = pr(0, 0);
						npa = pr(0, 0); // 좌표 예외처리
					}
					else {
						bpa = npa;
						npa = npa + dir;
					}
				}
				if (check(npb, bpa)) { // b가 굴러감
					if (map[npb.first][npb.second] == 'O') {
						// 굴러가던 방향에 구멍이 있다면 기록
						hole[1] = true;
						bpb = pr(0, 0);
						npb = pr(0, 0);
					}
					else {
						bpb = npb;
						npb = npb + dir;
					}
				}
			}

			if (hole[0] || hole[1]) { // 하나라도 공이 들어가면 판단
				if (hole[0] && !hole[1]) { // 빨간 공만 구멍에 들어간다면
					ans = cnt + 1; // 정답으로 기록
					break; // 종료
				}
				continue; // 정답 외엔 무시
			}
			q.emplace(bpa, bpb, cnt + 1); // 구멍에 들어간 구슬이 없다면 큐에 삽입
		}
		if (ans != -1) break; // 정답을 얻었다면 종료
	}
	cout << ans << endl;
}