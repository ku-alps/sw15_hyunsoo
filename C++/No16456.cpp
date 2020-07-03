#include<iostream>
using namespace std;
// 하와와 대학생쨩 하와이로 가는 거시와요~
// 제공되는 연산은 뒤로 1칸, 뒤로 2칸, 앞으로 1칸
// 이때, 모든 섬을 반드시 방문해야 하므로,
// 뒤로 2칸을 가는 경우, 앞으로 1칸 -> 뒤로 2칸 연산이 반드시 따라와야 함
// 이를 사용하여 규칙을 생성

#define NUM 50000
#define DIV 1000000009

int cnt[NUM + 2]; // N번째까지 모두 도달하는 경우 수

int main() {
	int N;
	cin >> N;

	cnt[1] = 1; // 앞으로 순차전진
	for (int k = 1; k <= N; k++) {
		cnt[k + 1] = (cnt[k + 1] + cnt[k]) % DIV; // 바로 다음으로 넘어가는 경우
		if (k + 2 <= N) { // 2칸을 뛴 값이 범위 내이면
			cnt[k + 3] = (cnt[k + 3] + cnt[k]) % DIV; // 그 구간은 채울 수 있음
			// 앞으로 2칸 -> 뒤로 1칸 -> 앞으로 2칸 = 앞으로 3칸 전진과 동일
		}
	}
	cout << cnt[N + 1] << endl;
}