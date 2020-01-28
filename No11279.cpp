#include<cstdio>
#include<queue>
using namespace std;
// 최대 힙

int loop; // 연산 횟수
priority_queue<int, vector<int>, less<int>> pq; // 최대 우선순위 큐

int main() {
	scanf("%d", &loop);
	int val;
	for (int k = 0; k < loop; k++) {
		scanf("%d", &val); // 입력
		if (!val) { // 0 인 경우, 데이터 출력 시도
			if (pq.empty()) printf("%d\n", 0); // 빈 경우, 0 을 출력
			else {
				printf("%d\n", pq.top());
				pq.pop(); // 데이터가 있다면 출력하고 삭제
			}
		}
		else pq.push(val); // 값이 있다면 추가
	}
}