#include<cstdio>
#include<algorithm>
using namespace std;
// 정수 삼각형
// 하단으로 내려올 때, 이동 경우는 2가지 뿐
// so, 가져올 수 있는 점수 중 최대값을 선택하여 현재 위치의 값을 더함
// 최종적으로 그 중 가장 큰 값을 선택

#define MAX 500

int s, memo[MAX + 1][MAX + 1];

int main() {
	int s;
	scanf("%d", &s);
	for (int k = 1; k <= s; k++) {
		for (int m = 1; m <= k; m++) { // 계층구조로 자신의 앞과 위에서 최대값을 픽
			int d;
			scanf("%d", &d);
			memo[k][m] = max(memo[k - 1][m - 1], memo[k - 1][m]) + d;
			// 각 위치에 도착한 경우의 최대값
		}
	}
	printf("%d\n", *max_element(&memo[s][1], &memo[s][s + 1])); // 최종 결과 중, 최대원소 선택
}