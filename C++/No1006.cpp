#include<cstdio>
#include<queue>
#include<string>
using namespace std;
// 습격자 초라기
// 우선순위 큐로 그리디 탐색을 시도
// but, 알 수 없는 예외 case 로 실패..

#define NUM 10000

struct func {
	bool operator()(pair<int, int> &a, pair<int, int> &b) {
		return a.second > b.second;
	}
};

int T, arr[2][NUM + 1], visit[2][NUM + 1];
int cnt[2][NUM + 1]; // 연결 가능 지점의 갯수
string x = "211", y = "102";
priority_queue<pair<int,int>,vector<pair<int,int>>,func> q;
vector<int> v[NUM * 2 + 1];

int main() {
	scanf("%d", &T); // 반복 횟수
	for (int m = 0; m < T; m++) {
		int N, W;
		scanf("%d %d", &N, &W);

		for (int k = 0; k < 2; k++) { // 정보 입력
			for (int i = 0; i < N; i++) {
				scanf("%d", &arr[k][i]);
			}
		}

		for (int k = 0; k <= 2 * N; k++) v[k].clear(); // 초기화
		for (int k = 0; k <= N; k++) cnt[0][k] = cnt[1][k] = visit[0][k] = visit[1][k] = 0;

		for (int k = 0; k < 2; k++) {
			for (int i = 0; i < N; i++) { // 모든 정보를 살펴봄
				visit[k][i] = 0; // 초기화

				for (int j = 0; j < 3; j++) { // 엮을 수 있는 경우 수는 3가지
					int new_x = (k + x[j] - '1' + 2) % 2, new_y = (i + y[j] - '1' + N) % N; // 살펴볼 인덱스
					int comp = arr[k][i] + arr[new_x][new_y]; // 해당 위치를 포함한 값
					if (comp > W) continue; // 허용 가능한 인원 수를 넘어서면 종료
					v[k + i * 2].push_back(j); // 선택 방향을 삽입
					cnt[k][i] += 1; // 하나 추가
				}
			}
		} // 가능한 모든 조합을 생성

		for (int i = 0; i < 2; i++) { // 모든 경우를 큐에 추가
			for (int j = 0; j < N; j++) {
				q.push(pair<int, int>(i + 2 * j, cnt[i][j]));
			}
		}

		int ans = 0; // 정답 값
		while (!q.empty()) { // 큐에 데이터가 있으면 계속 진행
			int index = q.top().first;
			q.pop();
			if (visit[index % 2][index / 2]) continue;

			visit[index % 2][index / 2] = 1; // 사용

			int min_x = 0, min_y = N; // 안쓰는 빈공간
			for (int dir : v[index]) {
				int new_x = ((index % 2) + x[dir] - '1' + 2) % 2, new_y = ((index / 2) + y[dir] - '1' + N) % N; // 살펴볼 인덱스
				if (visit[new_x][new_y]) continue; // 이미 사용했으면 스킵

				if (min_y == N) { // 기준값이 없으면 일단 삽입
					min_x = new_x;
					min_y = new_y; // 교체
				}
				else if (cnt[new_x][new_y] < cnt[min_x][min_y]) { // 새로 본 값이 선택지가 더 없다면
					cnt[min_x][min_y] -= 1; // 기존 놈은 선택하지 않으므로 연결된 경우 수를 줄여야함
					q.push(pair<int, int>(min_x + 2 * min_y, cnt[min_x][min_y])); // 조건에 맞으면 삽입

					min_x = new_x;
					min_y = new_y; // 교체
				}
				else {
					cnt[new_x][new_y] -= 1; // 연결된 경우 수를 줄여야함
					q.push(pair<int, int>(new_x + 2 * new_y, cnt[new_x][new_y])); // 조건에 맞으면 삽입
				}
			}
			visit[min_x][min_y] = 1;
			for (int dir : v[min_x + 2 * min_y]) { // 선택한 놈은 주변 선택지에서 제거해야함
				int new_x = (min_x + x[dir] - '1' + 2) % 2, new_y = (min_y + y[dir] - '1' + N) % N; // 살펴볼 인덱스
				cnt[new_x][new_y] -= 1; // 합칠 수 있다면 양방향으로 정보가 있음
				q.push(pair<int, int>(new_x + 2 * new_y, cnt[new_x][new_y])); // 큐에 추가 삽입
			}
			ans += 1;
		}
		printf("%d\n", ans);
	}
}
