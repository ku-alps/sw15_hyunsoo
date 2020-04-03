#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
// 합이 0인 네 정수
// hash map 을 사용한 빠른 접근을 사용하려했으나,
// 너무 방대한 데이터 크기 때문에 충돌 처리로 상당히 느린 자료구조가 됨
// so, 이진 탐색을 사용하는 코드가 필요
// long long int 의 출력 타입으로 인해 상당히 헤멘 코드

#define NUM 4000

int N, arr[4][NUM];
vector<int> v[2];

int main() {
	scanf("%d", &N);;
	for (int k = 0; k < N; k++) {
		for (int m = 0; m < 4; m++) {
			scanf("%d", &arr[m][k]);
		}
	}
	for (int k = 0; k < 2; k++) { // 각각 a,b 와 c,d 의 합 벡터를 생성
		for (int m = 0; m < N; m++) {
			for (int i = 0; i < N; i++) {
				v[k].push_back(arr[2 * k][m] + arr[2 * k + 1][i]);
			}
		}
		sort(v[k].begin(), v[k].end(), [](int a, int b)->bool {
			return a < b; // 합 벡터를 크기 순으로 정렬
			});
	}

	long long int ans = 0;
	for (int value : v[0]) { // 모든 값에 대해 탐색
		int s_idx = lower_bound(v[1].begin(), v[1].end(), -value) - v[1].begin(); // 일치하거나 처음으로 큰 값의 위치
		int e_idx = upper_bound(v[1].begin(), v[1].end(), -value) - v[1].begin(); // 처음으로 큰 값의 위치
		ans += e_idx - s_idx; // 두 인덱스 값이 같은 경우, 일치값이 없음
	}
	printf("%lld\n", ans); // long long int 형을 출력
}