#include<cstdio>
#include<stack>
using namespace std;
// 텀 프로젝트
// 학생 수가 최대 10만이며, Test Case 수가 따로 존재
// so, 시간 단축을 위해 각 학생들에 대해 단 한 번만 접근하여 사이클을 확인 

// 학생들의 지목을 따라 이동하며, stack 에 정보를 저장
// 이후, 이미 방문한 학생이 다시 지정되었을 때,
// 동일한 그룹에 있는지 확인
// 사이클을 구성하는 일원들을 제거하고 남은 학생들은 모두 짝을 짓지 못함

#define NUM 100000

int T, N, student[NUM + 1];

int main() {
	scanf("%d", &T);
	for (int k = 0; k < T; k++) {
		scanf("%d", &N);
		for (int m = 1; m <= N; m++) { // 학생들 값 입력
			scanf("%d", &student[m]);
		}
		
		int num = 1, cnt = 0;
		int visit[NUM + 1] = {}; // 방문 여부
		for (int m = 1; m <= N; m++) {
			if (visit[m]) continue; // 이미 방문한 곳이면 무시

			int idx = m;
			stack<int> s; // 연결 정보
			for (; !visit[idx]; idx = student[idx]) { // 사이클이 생길 때까지 이동하며 진행
				s.push(idx);
				visit[idx] = num;
			}

			if (visit[idx] == visit[s.top()]) { // 사이클이 정상적으로 만들어진 경우
				while (!s.empty()) { // 내부적으로 사이클을 구성하는 놈들을 추려냄
					int node = s.top();
					s.pop();
					if (node == idx) break; // 사이클 시작점에 도달하면 빠져나옴
				}
			}
			cnt += s.size(); // 이후 스택에 남은 값들은 모두 짝이 없음
			num++;
		}
		printf("%d\n", cnt);
	}
}