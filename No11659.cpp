#include<cstdio>
using namespace std;
// 구간 합 구하기 4
// 입력받는 구간에 대해 즉각적인 반응이 필요
// so, 각 구간합을 미리 구해야 하지만 입력 크기는 10만
// 모든 경우에 대해 배열에 저장하게 되는 경우, 크기로 인해 공간이 터짐

#define MAX 100000

int N, M, sum[MAX + 1]; // 누적 합 배열

int main() {
	scanf("%d %d", &N, &M);
	for (int k = 1; k <= N; k++) {
		int d;
		scanf("%d", &d);
		sum[k] += sum[k - 1] + d; // 1~K 번까지의 누적 합
	}

	for (int k = 0; k < M; k++) {
		int a, b;
		scanf("%d %d", &a, &b);
		printf("%d\n", sum[b] - sum[a - 1]);
		// K 번 정보는 1~K 까지의 누적 합이며
		// 구간 합 안에 K 를 포함하기 위해 이전 정보로 계산
		// so, (1~B) - (1~(A-1)) = A~B 
	}
}