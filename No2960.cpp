#include<iostream>
using namespace std;
// 에라토스테네스의 체
// 단순한 수학적 원리 및 법칙

bool eratos[1001];

int main() {
	int until, num;
	cin >> until >> num;

	int cnt = 0;
	for (int k = 2; k <= until; k++) {
		if (eratos[k]) continue; // 이미 방문한 경우 무시

		for (int m = 1; m * k <= until; m++) {
			// 이후에 나오는 모든 배수들에 대해 수행
			if (eratos[m * k]) continue; // 이미 방문한 경우 무시
			eratos[m * k] = true;

			if (++cnt == num) { // K 번째 수에 도달했으면 출력 후 종료 
				cout << m * k << endl;
				break;
			}
		}
	}
}