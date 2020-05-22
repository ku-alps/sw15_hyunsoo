#include<iostream>
#include<algorithm>
using namespace std;
// 앱

#define MAX 100 // 등장하는 앱의 최대 갯수
#define INF 100 * MAX // 최대 값

int N, M;
int mem[MAX], cost[MAX], calc[INF + 1]; // 메모리, 비용, 각 비용 별 얻을 수 있는 최대 공간

int main() {
	scanf("%d %d", &N, &M);
	for (int k = 0; k < N; k++)
		scanf("%d", &mem[k]);
	for (int k = 0; k < N; k++) {
		scanf("%d", &cost[k]);
	}

	for (int m = 0; m < N; m++) { // 입력된 모든 값을 통해서 갱신
		for (int k = INF; k >= cost[m]; k--) { // 모든 영역에 대해
			calc[k] = max(calc[k], calc[k - cost[m]] + mem[m]); // 해당 비용으로 얻을 수 있는 최대 공간 획득
		}
	}

	int k = 0;
	while (calc[k] < M) { // 원하는 공간을 얻을 때까지 비용 증가
		k++;
	}
	cout << k << endl;
}