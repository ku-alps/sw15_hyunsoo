#include<iostream>
#include<algorithm>
using namespace std;
// 수확
// 매 턴마다 벨 수 있는 벼는 좌, 우이며, 벼의 이윤이 클수록 늦게 베는 것이 유리
// so, 그리디 + 투포인터 를 사용하려 했으나, 벼의 이윤이 같은 경우 처리가 모호
// DP 를 사용한 방식으로 방향을 우회

#define NUM 2000

// 벼의 수, 각 이윤, dp 배열
long long int N, rice[NUM + 1], dp[NUM + 1][NUM + 1];

long long int DP(int f, int b, int depth) {
	if (dp[f][b]) return dp[f][b]; // 기존 값이 있다면 사용
	if (f == b) return dp[f][b] = rice[f] * depth; // 유일한 값은 출력
	return dp[f][b] = max( // 왼쪽, 오른쪽을 베는 경우 중 큰 값을 선택
		DP(f + 1, b, depth + 1) + rice[f] * depth,
		DP(f, b - 1, depth + 1) + rice[b] * depth);
}

int main() {
	// 입력
	cin >> N; 
	for (int k = 1; k <= N; k++) cin >> rice[k];

	// DP 탐색
	cout << DP(1, N, 1) << endl;
}