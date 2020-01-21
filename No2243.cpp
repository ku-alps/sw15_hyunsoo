#include<cstdio>
using namespace std;
// 사탕상자
// 삽입, 삭제가 빈번히 일어나며,
// 갱신되는 정보 내에서 빠르게 탐색을 해야하므로
// 세그먼트 트리를 사용하여 시간 단축

#define MAX 1<<21 // 입력 데이터의 최대 크기

long long int st[MAX]; // 세그먼트 트리용 배열
long long int start = (MAX >> 1) - 1;
// 실제 데이터가 들어가는 인덱스 값은 ((배열 크기의 절반 / 2) - 1)
// 각 세그먼트 트리의 중간 노드 값은 자신의 양측 노드에 존재하는 사탕의 갯수

int main() {
	int loop;
	scanf("%d", &loop);

	for (int k = 0; k < loop; k++) { // 연산 수행 횟수
		int d, v;
		scanf("%d %d", &d, &v);

		if (d == 1) { // 1인 경우, 사탕을 꺼냄
			long long int n = 0;
			for (; n < start;) { // 실제 정보가 들어있는 곳에 도착할 때 까지
				if (st[n * 2 + 1] < v) { // 좌측에 있는 사탕 수가 충분한 경우,
					v -= st[n * 2 + 1];
					n = n * 2 + 2; // 우측으로 넘어감
				}
				else {
					n = n * 2 + 1; // 그 외엔 좌측 이동
				}
			}
			for (long long int m = n; m > 0; ) { // 찾은 곳에서 사탕을 빼고 트리 갱신
				st[m] -= 1;
				m = (m - 1) / 2;
			}
			st[0] -= 1;
			printf("%d\n", n - start + 1); // 찾은 사탕 값 출력
		}
		else { // 2인 경우, 사탕을 넣음 (음수인 경우 제거하나, 상관 x)
			v -= 1;

			int c;
			scanf("%d", &c); // 갯수를 추가로 입력
			for (long long int m = start + v; m > 0;) {
				st[m] += c;
				m = (m - 1) / 2; 
			} // 세그먼트 트리 정보를 순차적으로 갱신
			st[0] += c; // 마지막 루트 정보 갱신
		}
	}
}
