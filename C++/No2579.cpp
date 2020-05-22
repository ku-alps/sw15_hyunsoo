#include<cstdio>
#include<algorithm>
using namespace std;
// 계단 오르기
// 해당 계단까지 도달하는 여러 경로 중 최대값을 얻어야 함
// 이는 재귀적으로 모든 계단에 대해 적용되므로
// 메모아이제이션을 사용

#define MAX 300

int N, memo[MAX + 1][3], stair[MAX + 1];
// 1 : 건너서 밟은 경우, 2 : 연속으로 밟은 경우

int Step(int idx, int cnt) {
	if (cnt == 3 || idx < 1) return 0; // 계단을 3번 연속으로 밟거나 계단이 없으면 허용 x
	if (memo[idx][cnt]) return memo[idx][cnt]; // 값이 이미 있다면 반환
	return memo[idx][cnt] = max(Step(idx - 1, cnt + 1), Step(idx - 2, 1)) + stair[idx];
	// 앞서 나오는 경우 수 중 최대 값 + 현재 계단 점수
	// 각 단계에 따라 얻을 수 있는 최대값을 따로 보관해주어야 재호출 시 step 판단이 가능
}

int main() {
	scanf("%d", &N);
	for (int k = 1; k <= N; k++) {
		scanf("%d", &stair[k]); // 값 저장
	}
	printf("%d\n", Step(N, 1)); // 꼭대기는 항상 밟아야 하므로, 맨 위부터 아래로 탐색하는 방식
}