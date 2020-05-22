#include<cstdio>
#include<functional>
#include<queue>
using namespace std;
// 가운데를 말해요
// 입력 크기 10만에 대하여 값의 탐색을 묻는 문제
// 단순 일반 탐색의 경우 N 재곱으로 시간초과가 발생하므로
// 중간 값 탐색을 log N 에 해결할 수 있는가를 묻는 문제

// 앞, 뒤 정보를 모두 유지하며 중간 값을 계속해서 유지해야 함
// so, 앞 뒤로 두개의 heap 을 사용하며 크기를 일정하게 유지하는 방식

priority_queue<int, vector<int>, less<int>> pql; // 최대값 우선순위 큐 (왼쪽)
priority_queue<int, vector<int>, greater<int>> pqr; // 최소값 우선순위 큐 (오른쪽)

int main() {
	int loop;
	scanf("%d", &loop); // 수행 횟수 입력

	for (int k = 0; k < loop; k++) {
		int data;
		scanf("%d", &data);

		if (pql.empty()) { // 왼쪽이 빈 경우 (첫 명령)
			pql.push(data); // 무조껀 왼쪽에 추가
			// 항상 왼쪽 큐가 오른쪽 큐와 크기가 같거나 1개 많도록 설정
		}
		else { // 그 외의 모든 경우 
			int mid = pql.top();  // 왼쪽 첫 값을 반환 (중간값) 

			if (mid < data) pqr.push(data); 
			else pql.push(data); 
			// 중간값보다 크면 오른쪽에, 작으면 왼쪽에 삽입

			// 중간값을 항상 유지하기 위해 좌우 큐 크기를 조정
			if (pql.size() < pqr.size()) { 
				int m = pqr.top();
				pqr.pop();
				pql.push(m);
			}
			else if (pql.size() > pqr.size() + 1) {
				int m = pql.top();
				pql.pop();
				pqr.push(m);
			}
		}
		printf("%d\n", pql.top()); // 정답 출력
	}
}
